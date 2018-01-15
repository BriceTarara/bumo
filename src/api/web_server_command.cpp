/*
Copyright Bubi Technologies Co., Ltd. 2017 All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <utils/headers.h>
#include <common/private_key.h>
#include <common/general.h>
#include <main/configure.h>
#include <overlay/peer_manager.h>
#include <glue/glue_manager.h>
#include <ledger/ledger_manager.h>
#include <ledger/contract_manager.h>
#include "web_server.h"

namespace bumo {

	void WebServer::SubmitTransaction(const http::server::request &request, std::string &reply) {

		Json::Value body;
		if (!body.fromString(request.body)) {
			LOG_ERROR("Parse request body json failed");
			Json::Value reply_json;
			reply_json["results"][Json::UInt(0)]["error_code"] = protocol::ERRCODE_INVALID_PARAMETER;
			reply_json["results"][Json::UInt(0)]["error_desc"] = "request must being json format";
			reply_json["success_count"] = Json::UInt(0);
			reply = reply_json.toStyledString();
			return;
		}

		Json::Value reply_json = Json::Value(Json::objectValue);
		Json::Value &results = reply_json["results"];
		results = Json::Value(Json::arrayValue);
		uint32_t success_count = 0;

		int64_t begin_time = utils::Timestamp::HighResolution();
		const Json::Value &json_items = body["items"];
		for (size_t j = 0; j < json_items.size() && running; j++) {
			const Json::Value &json_item = json_items[j];
			Json::Value &result_item = results[results.size()];

			int64_t active_time = utils::Timestamp::HighResolution();
			Result result;
			result.set_code(protocol::ERRCODE_SUCCESS);
			result.set_desc("");

			protocol::TransactionEnv tran_env;
			do {
				if (json_item.isMember("transaction_blob")) {
					if (!json_item.isMember("signatures")) {
						result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
						result.set_desc("'signatures' value not exist");
						break;
					}

					std::string decodeblob;
					std::string decodesig;
					if (!utils::String::HexStringToBin(json_item["transaction_blob"].asString(), decodeblob)) {
						result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
						result.set_desc("'transaction_blob' value must be Hex");
						break;
					}

					protocol::Transaction *tran = tran_env.mutable_transaction();
					if (!tran->ParseFromString(decodeblob)) {
						result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
						result.set_desc("ParseFromString from 'sign_data' invalid");
						LOG_ERROR("ParseFromString from decodeblob invalid");
						break;
					}

					const Json::Value &signatures = json_item["signatures"];
					for (uint32_t i = 0; i < signatures.size(); i++) {
						const Json::Value &signa = signatures[i];
						protocol::Signature *signpro = tran_env.add_signatures();

						//utils::decode_b16(signa["sign_data"].asString(), decodesig);
						decodesig = "";
						if (!utils::String::HexStringToBin(signa["sign_data"].asString(), decodesig)) {
							result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
							result.set_desc("'sign_data' value must be Hex");
							break;
						}

						PublicKey pubkey(signa["public_key"].asString());
						if (!pubkey.IsValid()) {
							result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
							result.set_desc("'public_key' value not exist or parameter error");
							LOG_ERROR("Invalid publickey (%s)", signa["public_key"].asString().c_str());
							break;
						}

						signpro->set_sign_data(decodesig);
                        signpro->set_public_key(pubkey.GetEncPublicKey());
					}

					// add node signature
					std::string content = tran->SerializeAsString();
					PrivateKey privateKey(bumo::Configure::Instance().p2p_configure_.node_private_key_);
					if (!privateKey.IsValid()) {
						result.set_code(protocol::ERRCODE_INVALID_PRIKEY);
						result.set_desc("signature failed");
						break;
					}
					std::string sign = privateKey.Sign(content);
					protocol::Signature *signpro = tran_env.add_signatures();
					signpro->set_sign_data(sign);
                    signpro->set_public_key(privateKey.GetEncPublicKey());
					result_item["hash"] = utils::String::BinToHexString(HashWrapper::Crypto(content));
				}
				else {
					protocol::Transaction *tran = tran_env.mutable_transaction();
					std::string error_msg;
					if (!Json2Proto(json_item["transaction_json"], *tran, error_msg)){
						result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
						result.set_desc(error_msg);
						break;
					}
	

					std::string content = tran->SerializeAsString();
					const Json::Value &private_keys = json_item["private_keys"];
					for (uint32_t i = 0; i < private_keys.size(); i++) {
						const std::string &private_key = private_keys[i].asString();

						PrivateKey privateKey(private_key);
						if (!privateKey.IsValid()) {
							result.set_code(protocol::ERRCODE_INVALID_PRIKEY);
							result.set_desc("signature failed");
							break;
						}

						std::string sign = privateKey.Sign(content);
						protocol::Signature *signpro = tran_env.add_signatures();
						signpro->set_sign_data(sign);
                        signpro->set_public_key(privateKey.GetEncPublicKey());
					}

					result_item["hash"] = utils::String::BinToHexString(HashWrapper::Crypto(content));
				}

				TransactionFrm frm(tran_env);
				if (!frm.CheckValid(-1)){
					result = frm.result_;
					break;
				}

			} while (false);

			if (result.code() == protocol::ERRCODE_SUCCESS) {
				TransactionFrm::pointer ptr = std::make_shared<TransactionFrm>(tran_env);
				GlueManager::Instance().OnTransaction(ptr, result);
				PeerManager::Instance().Broadcast(protocol::OVERLAY_MSGTYPE_TRANSACTION, tran_env.SerializeAsString());
				if (result.code() == protocol::ERRCODE_SUCCESS) success_count++;
			}
			result_item["error_code"] = result.code();
			result_item["error_desc"] = result.desc();
		}
		LOG_TRACE("Create %u transaction use " FMT_I64 "(ms)", json_items.size(),
			(utils::Timestamp::HighResolution() - begin_time) / utils::MICRO_UNITS_PER_MILLI);


		reply_json["success_count"] = success_count;
		reply = reply_json.toStyledString();
	}

	void WebServer::CreateAccount(const http::server::request &request, std::string &reply) {
		std::string error_desc;
		int32_t error_code = protocol::ERRCODE_SUCCESS;
		Json::Value reply_json = Json::Value(Json::objectValue);
		
		SignatureType sign_type = SIGNTYPE_CFCASM2;

		do {
			std::string sign_type_s = request.GetParamValue("sign_type");
			if (sign_type_s == ""){
				if (HashWrapper::GetLedgerHashType() == HashWrapper::HASH_TYPE_SHA256) {
					sign_type = SIGNTYPE_ED25519;
				}
				else {
					sign_type = SIGNTYPE_CFCASM2;
				}
			}
			else {
				sign_type = GetSignTypeByDesc(sign_type_s);
				if (sign_type == SIGNTYPE_NONE) {
					error_code = protocol::ERRCODE_INVALID_PARAMETER;
					break;
				} 
			}

			PrivateKey priv_key(sign_type);
            std::string public_key = priv_key.GetEncPublicKey();
            std::string private_key = priv_key.GetEncPrivateKey();
            std::string public_address = priv_key.GetEncAddress();

			LOG_TRACE("Creating account address:%s", public_address.c_str());

			Json::Value &result = reply_json["result"];
			result["public_key"] = public_key;
			result["private_key"] = private_key;
			result["private_key_aes"] = utils::Aes::CryptoHex(private_key, bumo::GetDataSecuretKey());
			result["address"] = public_address;
			result["public_key_raw"] = EncodePublicKey(priv_key.GetRawPublicKey());
			result["sign_type"] = GetSignTypeDesc(sign_type);

		} while (false);
		reply_json["error_code"] = error_code;
		reply = reply_json.toStyledString();
	}

	void WebServer::TestContract(const http::server::request &request, std::string &reply) {
		
		Json::Value body;
		if (!body.fromString(request.body)) {
			LOG_ERROR("Parse request body json failed");
			Json::Value reply_json;
			reply_json["results"][Json::UInt(0)]["error_code"] = protocol::ERRCODE_INVALID_PARAMETER;
			reply_json["results"][Json::UInt(0)]["error_desc"] = "request must being json format";
			reply_json["success_count"] = Json::UInt(0);
			reply = reply_json.toStyledString();
			return;
		}

		ContractTestParameter test_parameter;
		test_parameter.code_ = body["code"].asString();
		test_parameter.input_ = body["input"].asString();
		test_parameter.exe_or_query_ = body["exe_or_query"].asBool();
		test_parameter.contract_address_ = body["contract_address"].asString();
		test_parameter.source_address_ = body["source_address"].asString();
		test_parameter.fee_ = body["fee"].asInt64();

		int32_t error_code = protocol::ERRCODE_SUCCESS;
		std::string error_desc;
		AccountFrm::pointer acc = NULL;

		Json::Value reply_json = Json::Value(Json::objectValue);
		Json::Value &result = reply_json["result"];

		do {
			if (!test_parameter.contract_address_.empty()) {
				if (!Environment::AccountFromDB(test_parameter.contract_address_, acc)) {
					error_code = protocol::ERRCODE_NOT_EXIST;
					error_desc = utils::String::Format("Account(%s) not exist", test_parameter.contract_address_.c_str());
					LOG_ERROR("%s", error_desc.c_str());
					break;
				}

				test_parameter.code_ = acc->GetProtoAccount().contract().payload();
			} 

			if (test_parameter.code_.empty()) {
				error_code = protocol::ERRCODE_NOT_EXIST;
				error_desc = utils::String::Format("Account(%s) has no contract code", test_parameter.contract_address_.c_str());
				LOG_ERROR("%s", error_desc.c_str());
				break;
			}

			Result exe_result;
			if (!LedgerManager::Instance().context_manager_.SyncTestProcess(LedgerContext::AT_TEST_V8,
				(TestParameter*)&test_parameter,
				utils::MICRO_UNITS_PER_SEC, 
				exe_result, result["logs"], result["txs"], result["rets"], result["real_fee"])) {
				error_code = exe_result.code();
				error_desc = exe_result.desc();
				LOG_ERROR("%s", error_desc.c_str());
				break;
			}

		} while (false);

		reply_json["error_code"] = error_code;
		reply_json["error_desc"] = error_desc;
		reply = reply_json.toStyledString();
	}

	void WebServer::TestTransaction(const http::server::request &request, std::string &reply) {
		Json::Value body;
		if (!body.fromString(request.body)) {
			LOG_ERROR("Parse request body json failed");
			Json::Value reply_json;
			reply_json["results"][Json::UInt(0)]["error_code"] = protocol::ERRCODE_INVALID_PARAMETER;
			reply_json["results"][Json::UInt(0)]["error_desc"] = "request must being json format";
			reply_json["success_count"] = Json::UInt(0);
			reply = reply_json.toStyledString();
			return;
		}
		

		int64_t begin_time = utils::Timestamp::HighResolution();
		const Json::Value &json_items = body["items"];
		if (json_items.size() > 1) {			
			LOG_ERROR("Test transaction too much(%d)", json_items.size());
			Json::Value reply_json;
			reply_json["results"][Json::UInt(0)]["error_code"] = protocol::ERRCODE_TX_SIZE_TOO_BIG;
			reply_json["results"][Json::UInt(0)]["error_desc"] = "Test transaction too much,just can test only one transaction";
			reply_json["success_count"] = Json::UInt(0);
			reply = reply_json.toStyledString();
			return;
		}

		Json::Value reply_json = Json::Value(Json::objectValue);
		Json::Value &result_json = reply_json["result"];
		//results = Json::Value(Json::arrayValue);
		//uint32_t success_count = 0;

		TransactionTestParameter test_parameter;
		protocol::TransactionEnvSet* tx_set = test_parameter.consensus_value_.mutable_txset();

		for (size_t j = 0; j < json_items.size() && running; j++) {
			const Json::Value &json_item = json_items[j];

			int64_t active_time = utils::Timestamp::HighResolution();
			Result result;
			result.set_code(protocol::ERRCODE_SUCCESS);
			result.set_desc("");

			protocol::TransactionEnv tran_env;
			do {
				if (json_item.isMember("transaction_blob")) {
					if (!json_item.isMember("signatures")) {
						result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
						result.set_desc("'signatures' value not exist");
						break;
					}

					std::string decodeblob;
					std::string decodesig;
					//utils::decode_b16(json_item["transaction_blob"].asString(), decodeblob);
					decodeblob;// = utils::String::HexStringToBin(json_item["transaction_blob"].asString());
					if (!utils::String::HexStringToBin(json_item["transaction_blob"].asString(), decodeblob)) {
						result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
						result.set_desc("'transaction_blob' value must be Hex");
						break;
					}

					protocol::Transaction *tran = tran_env.mutable_transaction();
					if (!tran->ParseFromString(decodeblob)) {
						result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
						result.set_desc("ParseFromString from 'sign_data' invalid");
						LOG_ERROR("ParseFromString from decodeblob invalid");
						break;
					}

					const Json::Value &signatures = json_item["signatures"];
					for (uint32_t i = 0; i < signatures.size(); i++) {
						const Json::Value &signa = signatures[i];
						protocol::Signature *signpro = tran_env.add_signatures();

						//utils::decode_b16(signa["sign_data"].asString(), decodesig);
						decodesig = "";
						if (!utils::String::HexStringToBin(signa["sign_data"].asString(), decodesig)) {
							result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
							result.set_desc("'sign_data' value must be Hex");
							break;
						}

						PublicKey pubkey(signa["public_key"].asString());
						if (!pubkey.IsValid()) {
							result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
							result.set_desc("'public_key' value not exist or parameter error");
							LOG_ERROR("Invalid publickey (%s)", signa["public_key"].asString().c_str());
							break;
						}

						signpro->set_sign_data(decodesig);
                        signpro->set_public_key(pubkey.GetEncPublicKey());
					}

					// add node signature
					std::string content = tran->SerializeAsString();
					PrivateKey privateKey(bumo::Configure::Instance().p2p_configure_.node_private_key_);
					if (!privateKey.IsValid()) {
						result.set_code(protocol::ERRCODE_INVALID_PRIKEY);
						result.set_desc("signature failed");
						break;
					}
					std::string sign = privateKey.Sign(content);
					protocol::Signature *signpro = tran_env.add_signatures();
					signpro->set_sign_data(sign);
                    signpro->set_public_key(privateKey.GetEncPublicKey());
					result_json["hash"] = utils::String::BinToHexString(HashWrapper::Crypto(content));
				}
				else {
					protocol::Transaction *tran = tran_env.mutable_transaction();
					std::string error_msg;
					if (!Json2Proto(json_item["transaction_json"], *tran, error_msg)){
						result.set_code(protocol::ERRCODE_INVALID_PARAMETER);
						result.set_desc(error_msg);
						break;
					}


					std::string content = tran->SerializeAsString();
					const Json::Value &private_keys = json_item["private_keys"];
					for (uint32_t i = 0; i < private_keys.size(); i++) {
						const std::string &private_key = private_keys[i].asString();

						PrivateKey privateKey(private_key);
						if (!privateKey.IsValid()) {
							result.set_code(protocol::ERRCODE_INVALID_PRIKEY);
							result.set_desc("signature failed");
							break;
						}

						std::string sign = privateKey.Sign(content);
						protocol::Signature *signpro = tran_env.add_signatures();
						signpro->set_sign_data(sign);
                        signpro->set_public_key(privateKey.GetEncPublicKey());
					}

					// add node signature
					PrivateKey privateKey(bumo::Configure::Instance().p2p_configure_.node_private_key_);
					if (!privateKey.IsValid()) {
						result.set_code(protocol::ERRCODE_INVALID_PRIKEY);
						result.set_desc("signature failed");
						break;
					}
					std::string sign = privateKey.Sign(content);
					protocol::Signature *signpro = tran_env.add_signatures();
					signpro->set_sign_data(sign);
                    signpro->set_public_key(privateKey.GetEncPublicKey());
					result_json["hash"] = utils::String::BinToHexString(HashWrapper::Crypto(content));
				}

				TransactionFrm frm(tran_env);
				if (!frm.CheckValid(-1)){
					result = frm.result_;
					break;
				}

			} while (false);

			if (result.code() == protocol::ERRCODE_SUCCESS) {
				TransactionFrm::pointer ptr = std::make_shared<TransactionFrm>(tran_env);
				//...TODO
				*tx_set->add_txs() = tran_env;
				Result exe_result;
				if (!LedgerManager::Instance().context_manager_.SyncTestProcess(LedgerContext::AT_TEST_TRANSACTION,
					(TestParameter*)&test_parameter,
					utils::MICRO_UNITS_PER_SEC,
					exe_result, result_json["logs"], result_json["txs"], result_json["rets"], result_json["real_fee"])) {
					reply_json["error_code"] = exe_result.code();
					reply_json["error_desc"] = exe_result.desc();
					LOG_ERROR("%s", exe_result.desc().c_str());
					break;
				}
				//if (result.code() == protocol::ERRCODE_SUCCESS) success_count++;
			}
			reply_json["error_code"] = result.code();
			reply_json["error_desc"] = result.desc();

		}//end for
		LOG_TRACE("Create %u transaction use " FMT_I64 "(ms)", json_items.size(),
			(utils::Timestamp::HighResolution() - begin_time) / utils::MICRO_UNITS_PER_MILLI);
		reply = reply_json.toStyledString();
	}
}