# Keypair�ֲ�

## ����

���ĵ���ϸ������Keypair������˽Կ�ԣ������ɹ����Լ��ڴ˻�����������ɵ�ַ��address�����Խ���ǩ����������ִ�н��׵��õ����ֽӿڷ�ʽ�Լ�������̣��ṩ�˶���ProtoBuf���ݽṹ�ο���Ϣ�������ʾ���ķ�ʽ��ϸ���������ֽ����ύ��ʽ�������ýӿ�����transaction_blob���Լ�����transaction_blob��

## ����

���½ڶԸ��ĵ���ʹ�õ��������������ϸ˵����

**Keypair**

keypair��BUMO���������ɹ�Կ��˽Կ����ַ��ǩ���Ľӿڡ���ǩ�������н�֧��ED25519ǩ���㷨��

**˽Կ**

˽Կ��ͨ���㷨���ɵ�һ���ַ����������ɹ�Կ�͵�ַ��ǰ��������ͬʱҲ�����ǩ���Ļ���Ҫ�ء�˽Կ���ɺ��ܸ��ģ�һ����ʧ���޷��һأ������Ҫ���Ʊ��ܡ�

**��Կ**

��Կ�ǻ���˽Կ������һ���ַ��������Զ�˽Կ���ܵ��ַ���������֤��������䴫��ʱ���ᵼ��˽Կй¶��ͬʱҲ�����ɵ�ַ�ı�Ҫ������

**��ַ**

��ַ�ǻ��ڹ�Կ������һ���ַ���������ʵ�����еĵ�ַ���ƣ�û�е�ַ���޷��ҵ���ϵ�ˣ����Ҳ���޷���ɽ��ס�

**ǩ��**

ǩ����ָͨ���㷨��˽Կ�Խ������ݽ��м���ȷ�ϲ��õ�ǩ�����ݵĹ��̡��û�����ͨ��ǩ�������жϽ������ݵ������Ժ���ȷ�ԡ�

**����**

��BUMO�������޸����������ݵĲ�������Ϊ���ף����緢���ʲ���ת���ʲ�������BU�������˺š�����metadata������Ȩ�޵ȶ��ǽ��ס�

**Transaction Blob**

Transaction Blob��ָ��һ�����׶���������л�����֮��õ���16�����ַ������������л���ָͨ��ProtoBuf���ݽṹ�����׶����״̬��Ϣת���ɿ��Դ洢�ʹ�����ַ����Ĺ��̡�

**Raw Private Key**

Raw Private Key ��ָͨ������㷨�õ����ֽ����飬���ֽ�����������˽Կ��ǰ��������

**Raw Public Key**

Raw Public Key ��ָͨ��ED25519�㷨�� raw private key ���д������ɵ��ֽ����飬���ֽ����������ɹ�Կ��ǰ��������

## ԭ��ͼ
��ͼ˵����˽Կ����Կ�͵�ַ������ԭ��
![](/assets/schematic.png)

## ����˽Կ
����˽Կ��Ҫʹ������㷨��SHA256�ȶ���㷨����ʵ�֡�����˽Կ�������²��裺

1.��������㷨����һ��256λ�����������ѧ�����ϵ�˽Կ�����õ��ֽ����鼴 raw private key��������ʾ��
```
[17,236,24,183,207,250,207,180,108,87,224,39,189,99,246,85,138,120,236,78,228,233,41,192,124,109,156,104,235,66,194,24]
```

2.�� raw private key ǰ�����3���ֽڵ�ǰ׺��Prefix����Ȼ���ټ���1���ֽڵİ汾�ţ�Version�����õ��µ��ֽ����飬������ʾ��

```
[218,55,159,1,17,236,24,183,207,250,207,180,108,87,224,39,189,99,246,85,138,120,236,78,228,233,41,192,124,109,156,104,235,66,194,24]
```

>**˵��**������Prefix��Version�Լ�Checksum��鿴��1��

3.�Ե�2���еõ����ֽ������������SHA256���㣬ȡ��������ǰ4���ֽڣ��õ�У���루Checksum�����ֽ����飬������ʾ��

```
[30,19,80,117]
```

4.����2���е��ֽ�����͵�3���е�У�����ֽ����鰴���Ⱥ�˳��������һ�𣬵õ��µ��ֽ����飬������ʾ��

```
[218,55,159,1,17,236,24,183,207,250,207,180,108,87,224,39,189,99,246,85,138,120,236,78,228,233,41,192,124,109,156,104,235,66,194,24,30,19,80,117]
```

5.�Ե�4���в������ֽ��������Base58���룬�õ���priv��ʼ���ַ�������˽Կ��private key����������ʾ��

```
privbsGZFUoRv8aXZbSGd3bwzZWFn3L5QKq74RXAQYcmfXhhZ54CLr9z
```

>**˵��**�����˾������˽Կ�����ɡ�

��1

| ���� | �������� | ���� |
|----------- | ----------------------------------------- | ----- |
| Prefix | 0xDA 0x37 0x9F | 3���ֽ� |
| Version | 0x01 | 1���ֽ� |
| Checksum | �Ե�2���еõ����ֽ������������SHA256����֮��ȡ��������ǰ4���ֽ� | 4���ֽ� |

�ñ������˽Կ��ʹ�õ���Prefix��Version�Լ�Checksum������˵����

## ���ɹ�Կ
���ɹ�Կ��Ҫ������˽Կ֮�����ʵ�֣���Ҫ�õ�ED25519�㷨�����ɹ�Կ�������²��裺

1.ͨ��ED25519�㷨��raw private key���д�������32λ���ֽ����飬��raw public key������˽Կ��
`privbsGZFUoRv8aXZbSGd3bwzZWFn3L5QKq74RXAQYcmfXhhZ54CLr9z`����raw public key������ʾ��

```
[21,118,76,208,23,224,218,117,50,113,250,38,205,82,148,81,162,27,130,83,208,1,240,212,54,18,225,158,198,50,87,10]
```

2.��raw public key ǰ�����1���ֽڵ�ǰ׺��Prefix����Ȼ���ټ���1���ֽڵİ汾�ţ�Version�����õ��µ��ֽ����飬������ʾ��

```
[176,1,21,118,76,208,23,224,218,117,50,113,250,38,205,82,148,81,162,27,130,83,208,1,240,212,54,18,225,158,198,50,87,10]
```

>**˵��**������Prefix��Version�Լ�Checksum��鿴��2��

3.�Ե�2���е��ֽ������������SHA256���㣬ȡ��������ǰ4���ֽڣ��õ�У���루Checksum�����ֽ����飬������ʾ��

```
[116,171,22,107]
```

4.����2���е��ֽ������3����У�����ֽ����鰴���Ⱥ�˳��������һ�𣬵õ��µ��ֽ����飬������ʾ��

```
[176,1,21,118,76,208,23,224,218,117,50,113,250,38,205,82,148,81,162,27,130,83,208,1,240,212,54,18,225,158,198,50,87,10,116,171,22,107]
```

5.�Ե�4���е��ֽ��������16���Ʊ��룬�õ�16�����ַ���������Կ��public key����������ʾ��

```
b00115764cd017e0da753271fa26cd529451a21b8253d001f0d43612e19ec632570a74ab166b
```

>**˵��**�����˾�����˹�Կ�����ɡ�

��2

| ���� | �������� | ���� |
|----------- | ----------------------------------------- | ----- |
| Prefix | 0xB0 | 1���ֽ� |
| Version | 0x01 | 1���ֽ� |
| Checksum | �Ե�2���еõ����ֽ������������SHA256����֮��ȡ��������ǰ4���ֽ� | 4���ֽ� |

�ñ�����ɹ�Կ��ʹ�õ���Prefix��Version�Լ�Checksum������˵����

## ���ɵ�ַ
������˽Կ�͹�Կ����Խ�һ��ͨ���㷨���ɵ�ַ�����ɵ�ַ�������²��裺

1.ͨ��ED25519�㷨��raw private key���д�������32λ���ֽ����飬�� raw public key������˽ԿΪ `privbsGZFUoRv8aXZbSGd3bwzZWFn3L5QKq74RXAQYcmfXhhZ54CLr9z`����raw public key ������ʾ��

```
[21,118,76,208,23,224,218,117,50,113,250,38,205,82,148,81,162,27,130,83,208,1,240,212,54,18,225,158,198,50,87,10]
```
2.�� raw public key ��������SHA256���㣬��ȡ�������ĺ�20λ�ֽڣ��õ��ֽ����飬������ʾ��

```
[173,148,59,51,183,193,55,160,1,133,247,80,65,13,67,190,164,114,18,220]
```
3.�ڵ�2���������ֽ�����ǰ�����2���ֽڵ�ǰ׺��Prefix����Ȼ���ټ���1���ֽڵİ汾�ţ�Version�����õ��µ��ֽ����飬������ʾ��

```
[1,86,1,173,148,59,51,183,193,55,160,1,133,247,80,65,13,67,190,164,114,18,220]
```

>**˵��**������Prefix��Version�Լ�Checksum��鿴��3��

4.�Ե�3���е��ֽ������������SHA256���㣬ȡ��������ǰ4���ֽڣ��õ�У���루Checksum�����ֽ����飬������ʾ��

```
[167,127,34,35]
```

5.����3���е��ֽ�����͵�4����У�����ֽ����鰴���Ⱥ�˳��������һ�𣬵õ��µ��ֽ����飬������ʾ��

```
[1,86,1,173,148,59,51,183,193,55,160,1,133,247,80,65,13,67,190,164,114,18,220,167,127,34,35]
```

6.�Ե�5���в������ֽ��������Base58���룬�õ���bu��ͷ���ַ���������ַ��address����������ʾ��

```
buQmWJrdYJP5CPKTbkQUqscwvTGaU44dord8
```

>**˵��**�����˾�����˵�ַ�����ɡ�

��3

| ���� | �������� | ���� |
|----------- | ----------------------------------------- | ------ |
| Prefix | 0x01 0x56 | 2���ֽ� |
| Version | 0x01 | 1���ֽ� |
| PublicKey| ȡraw public key�ĺ�20���ֽ� | 20���ֽ� |
| Checksum | �Ե�3���еõ����ֽ������������SHA256����֮��ȡ��������ǰ4���ֽ� | 4���ֽ� |

�ñ�����ɵ�ַ��ʹ�õ���Prefix��Version�Լ�Checksum������˵����

## ����ǩ��
����ED25519�㷨��˽Կ�Դ�ǩ���Ľ��ף�transaction_blob�ķ�16���Ʊ���õ����ֽ����飩����ǩ����������16����ת�����õ�ǩ���ַ���sign_data��

�����ʾ��չʾ�������ED25519��˽Կ��transaction_blobǩ����

˽Կ�ǣ�

```
b00115764cd017e0da753271fa26cd529451a21b8253d001f0d43612e19ec632570a74ab166b
```

Transaction_blob��:

```
0A24627551566B5555424B70444B526D48595777314D553855376E676F5165686E6F31363569109F0818C0843D20E80732146275696C642073696D706C65206163636F756E743A5F08011224627551566B5555424B70444B526D48595777314D553855376E676F5165686E6F3136356922350A246275516E6936794752574D4D454376585850673854334B35615A557551456351523670691A0608011A02080128C7A3889BAB20
```

��ED25519��ǩ���ӿڶ�transaction_blob����ǩ����������16����ת���󣬵õ���sign_data�ǣ�

```
a46ee590a84abdeb8cc38ade1ae8e8a2c71bb69bdc4cd7dc0de1b74b37e2cbd1696229687f80dff4276b1a3dd3f95a9bc1d569943b337fe170317430f36d6401
```
## �����ύ��ʽ
���׵�ִ�������ֽӿڵ��÷�ʽ��[���ýӿ�����transaction_blob](#���ýӿ�����transaction_blob) ��[�Լ����� transaction_blob](#�Լ�����transaction_blob)��

### ���ýӿ�����transaction_blob
>**ע��**������transaction_blob�ܿ��ܱ���ȡ�ʹ۸ģ���˲����������ַ�ʽ����transaction_blob��

�����Ҫ���ýӿ�����transaction_blob��ǩ�����ύ���ף���鿴bumo�Ŀ����ĵ�����ַ���£�

https://github.com/bumoproject/bumo/blob/master/docs/develop.md

���ýӿ�����transation_blob�������²��裺

1.����`getAccount`�ӿڻ�ȡ���������˻���nonceֵ������������ʾ��


```
HTTP GET host:port/getAccount?address=�˻���ַ
```


2.������Ҫ���json���ݲ���ɽ���������䣬��ʽ������ʾ��


```
{
"source_address":"xxxxxxxxxxx", //����Դ�˺ţ������׵ķ���
"nonce":2, //nonce��ֵ
"ceil_ledger_seq": 0, //��ѡ
"fee_limit":1000, //����֧���ķ���
"gas_price": 1000, //gas�۸�(��С�����õ����ֵ)
"metadata":"0123456789abcdef", //��ѡ���û��Զ�������׵ı�ע��16���Ƹ�ʽ
"operations":[
{
//���ݲ�ͬ�Ĳ�����д
},
{
//���ݲ�ͬ�Ĳ�����д
}
......
]
}
```
>**ע��**��nonceֵ��Ҫ�ڵ�1���л�ȡֵ�Ļ����ϼ�1��

3.ͨ������`getTransactionBlob`�ӿڽ���2�������ɵ�json������Ϊ�������룬�õ�һ������hash��transaction_blob��ʵ�ֽ������л�����ʽ������ʾ��

```
{
"error_code": 0,
"error_desc": "",
"result": {
"hash": "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //���׵�hash
"transaction_blob": "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //�������л�֮���16���Ʊ�ʾ
}
}
```

4.�Խ��׽���ǩ������佻�����ݡ�����֮ǰ���ɵ�˽Կ��transaction_blobǩ����Ȼ������ύ���׵�json���ݣ���ʽ������ʾ��

```
{
"items" : [{
"transaction_blob" : "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //һ���������л�֮���16���Ʊ�ʾ
"signatures" : [{//��һ��ǩ��
"sign_data" : "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //ǩ������
"public_key" : "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //��Կ
}, {//�ڶ���ǩ��
"sign_data" : "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //ǩ������
"public_key" : "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //��Կ
}
]
}
]
}
```

5.ͨ������`submitTransaction`�ӿڣ�����4�������ɵ�json������Ϊ�������룬�õ���Ӧ�������ɽ����ύ����Ӧ����ĸ�ʽ������ʾ��

```
{
"results": [
{
"error_code": 0,
"error_desc": "",
"hash": "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //���׵�hash
}
],
"success_count": 1
}
```

### �Լ�����transaction_blob
�Լ�����transaction_blob��ǩ�������ύ���ף���������������²��裺

1.ͨ������`getAccount`�ӿڻ�ȡ�������׵��˻���nonceֵ��������ʾ��

```
HTTP GET host:port/getAccount?address=�˻���ַ
```
2.���protocol buffer�Ľ��׶���Transaction�����������л��������Ӷ��õ�transaction_blob������Ľ������ݽṹ�����뿴[ProtoBuf���ݽṹ](#ProtoBuf���ݽṹ)��

3.ǩ�����ף�����佻�����ݡ�����˽Կ���ɹ�Կ������˽Կ��transaction_blobǩ����Ȼ������ύ���׵�json���ݣ���ʽ���£�

```
{
"items" : [{
"transaction_blob" : "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //һ���������л�֮���16���Ʊ�ʾ
"signatures" : [{//��һ��ǩ��
"sign_data" : "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //ǩ������
"public_key" : "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //��Կ
}, {//�ڶ���ǩ��
"sign_data" : "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //ǩ������
"public_key" : "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //��Կ
}
]
}
]
}
```
4.ͨ������`submitTransaction`�ӿڣ�����3�����ɵ�json������Ϊ�������룬��ɽ����ύ����Ӧ�����ʽ���£�

```
{
"results": [
{
"error_code": 0,
"error_desc": "",
"hash": "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //���׵�hash
}
],
"success_count": 1
}
```

## ProtoBuf���ݽṹ

Protocol Buffers��ProtoBuf�� ��һ������Ч�Ľṹ�����ݴ洢��ʽ���������ڽṹ�����ݴ��л�������˵���л��������ʺ������ݴ洢�� RPC ���ݽ�����ʽ��������ͨѶЭ�顢���ݴ洢������������޹ء�ƽ̨�޹ء�����չ�����л��ṹ���ݸ�ʽ��Ŀǰ�ṩ�� C++��Java��Python �������Ե� API��

Ҫ�˽�������ProtoBuf����Ϣ����鿴�������ӣ�

https://developers.google.com/protocol-buffers/docs/overview

������������Protocol Buffer�����ݽṹ���飬���ṩ��Խű����ɵĸ������Ե�protocol buffer���ļ��ͼ򵥲��Գ���

### ���ݽṹ
��������˽����п����õ��ĸ���ProtoBuf���ݽṹ������;�����û��ο�ʹ�á�

1.Transaction

�����ݽṹ�����������Ľ��ס�

```
message Transaction {
enum Limit{
UNKNOWN = 0;
OPERATIONS = 1000;
};
string source_address = 1; // ���׷����˻���ַ
int64 nonce = 2; // �������к�
int64 fee_limit = 3; // ���׷��ã�Ĭ��1000Gas����λ��MO��1 BU = 10^8 MO
int64 gas_price = 4; // ���״�����ã�Ĭ����1000����λ��MO��1 BU = 10^8 MO
int64 ceil_ledger_seq = 5; // ����߶�����
bytes metadata = 6; // ���ױ�ע
repeated Operation operations = 7; // �����б�
}
```

2.Operation

�����ݽṹ�����ڽ����еĲ�����
```
message Operation {
enum Type {
UNKNOWN = 0;
CREATE_ACCOUNT = 1;
ISSUE_ASSET = 2;
PAY_ASSE = 3;
SET_METADATA = 4;
SET_SIGNER_WEIGHT = 5;
SET_THRESHOLD = 6;
PAY_COIN = 7;
LOG = 8;
SET_PRIVILEGE = 9;
};
Type type = 1; // ��������
string source_address = 2; // ����Դ�˻���ַ
bytes metadata = 3; // ������ע
OperationCreateAccount create_account = 4; // �����˻�����
OperationIssueAsset issue_asset = 5; // �����ʲ�����
OperationPayAsset pay_asset = 6; // ת���ʲ�����
OperationSetMetadata set_metadata = 7; // ����metadata
OperationSetSignerWeight set_signer_weight = 8; // ����ǩ����Ȩ��
OperationSetThreshold	set_threshold = 9; // ���ý�������
OperationPayCoin pay_coin = 10; // ת��coin
OperationLog log = 11; // ��¼log
OperationSetPrivilege set_privilege = 12; // ����Ȩ��
}
```

3.OperationCreateAccount

�����ݽṹ���ڴ����˻���

```
message OperationCreateAccount{
string dest_address = 1; // ��������Ŀ���˻���ַ
Contract contract = 2; // ��Լ
AccountPrivilege priv = 3; // Ȩ��
repeated KeyPair metadatas = 4; // ������Ϣ
int64	init_balance = 5; // ��ʼ�����
string init_input = 6; // ��Լ���
}
```

4.Contract

�����ݽṹ�������ú�Լ��

```
message Contract{
enum ContractType{
JAVASCRIPT = 0;
}
ContractType type = 1; // ��Լ����
string payload = 2; // ��Լ����
}
```

5.AccountPrivilege

�����ݽṹ���������˻�Ȩ�ޡ�

```
message AccountPrivilege {
int64 master_weight = 1; // �˻�����Ȩ��
repeated Signer signers = 2; // ǩ����Ȩ���б�
AccountThreshold thresholds = 3; // ����
}
```

6.Signer

�����ݽṹ��������ǩ����Ȩ�ء�

```
message Signer {
enum Limit{
SIGNER_NONE = 0;
SIGNER = 100;
};
string address = 1; // ǩ�����˻���ַ
int64 weight = 2; // ǩ����Ȩ��
}
```

7.AccountThreshold

�����ݽṹ���������˻����ޡ�

```
message AccountThreshold{
int64 tx_threshold = 1; // ��������
repeated OperationTypeThreshold type_thresholds = 2; // ָ�������Ľ��������б�δָ���Ĳ����Ľ�����tx_thresholdΪ����
}
```
8.OperationTypeThreshold

�����ݽṹ����ָ�����͵Ĳ������ޡ�

```
message OperationTypeThreshold{
Operation.Type type = 1; // ��������
int64 threshold = 2; // �ò�����Ӧ������
}
```

9.OperationIssueAsset

�����ݽṹ���ڷ����ʲ���

```
message OperationIssueAsset{
string code = 1; // �����е��ʲ�����
int64 amount = 2; // �����е��ʲ�����
}
```

10.OperationPayAsset

�����ݽṹ����ת���ʲ���

```
message OperationPayAsset {
string dest_address = 1; // Ŀ���˻���ַ
Asset asset = 2; // �ʲ�
string input = 3; // ��Լ���
}
```

11.Asset

�����ݽṹ�������ʲ���

```
message Asset{
AssetKey	key = 1; // �ʲ���ʶ
int64	amount = 2; // �ʲ�����
}
```

12.AssetKey

�����ݽṹ���ڱ�ʶ�ʲ�Ψһ�ԡ�

```
message AssetKey{
string issuer = 1; // �ʲ������˻���ַ
string code = 2; // �ʲ�����
int32 type = 3; // �ʲ����ͣ�Ĭ��Ϊ0����ʾ������������
}
```

13.OperationSetMetadata

�����ݽṹ��������Metadata��

```
message OperationSetMetadata{
string	key = 1; // �ؼ��֣�Ωһ
string value = 2; // ����
int64 version = 3; // �汾���ƣ��ɲ�����
bool delete_flag = 4; // �Ƿ�ɾ��
}
```

14.OperationSetSignerWeight

�����ݽṹ��������ǩ����Ȩ�ء�

```
message OperationSetSignerWeight{
int64 master_weight = 1; // ����Ȩ��
repeated Signer signers = 2; // ǩ����Ȩ���б�
}
```

15.OperationSetThreshold

�����ݽṹ�����������ޡ�

```
message OperationSetThreshold{
int64 tx_threshold = 1; // ��������
repeated OperationTypeThreshold type_thresholds = 2; // ָ�������Ľ��������б�δָ���Ĳ����Ľ�����tx_thresholdΪ����
}
```

16.OperationPayCoin

�����ݽṹ���ڷ���coin��

```
message OperationPayCoin{
string dest_address = 1; // Ŀ���˻���ַ
int64 amount = 2; // coin������
string input = 3; // ��Լ���
}
```

17.OperationLog���ݽṹ

�����ݽṹ���ڼ�¼log��Ϣ��

```
message OperationLog{
string topic = 1; // ��־����
repeated string datas = 2; // ��־����
}
```

18.OperationSetPrivilege���ݽṹ

�����ݽṹ���������˻�Ȩ�ޡ�

```
message OperationSetPrivilege{
string master_weight = 1; // �˻�����Ȩ��
repeated Signer signers = 2; // ǩ����Ȩ���б�
string tx_threshold = 3; // ��������
repeated OperationTypeThreshold type_thresholds = 4; // ָ�������Ľ��������б�δָ���Ĳ����Ľ�����tx_thresholdΪ����
}

```

### ʹ��ʾ��

�������ṩ��proto�ű����Լ�cpp��java��javascript��pyton��object-c��php���ɵ�protoԴ���ʾ������ϸ��Ϣ��鿴��������: 

https://github.com/bumoproject/bumo/tree/develop/src/proto

�����е�Ŀ¼�ṹ˵����

1. cpp: C++��Դ��
2. io: Java��Դ��
3. go: Go��Դ�뼰���Գ���
4. js: Javascript��Դ�뼰���Գ���
5. python: Python��Դ�뼰���Գ���
6. ios: Object-c��Դ�뼰���Գ���
7. php: PHP��Դ�뼰���Գ���

## �����ύʾ��
�������˻�A ��`buQVkUUBKpDKRmHYWw1MU8U7ngoQehno165i`�������˻�B��ͨ��Keypair�е�[���ɵ�ַ](#���ɵ�ַ)���������˻���ַ����

### �ӿ�����transaction_blobʾ��
ͨ���ӿ�����transaction_blob�������²��裺

1.ͨ��GET��ȡ���������˻���nonceֵ��

```
GET http://seed1.bumotest.io:26002/getAccount?address=buQsurH1M4rjLkfjzkxR9KXJ6jSu2r9xBNEw
```

�õ�����Ӧ���ģ�

```
{
"error_code" : 0,
"result" : {
"address" : "buQsurH1M4rjLkfjzkxR9KXJ6jSu2r9xBNEw",
"assets" : [
{
"amount" : 1000000000,
"key" : {
"code" : "HNC",
"issuer" : "buQBjJD1BSJ7nzAbzdTenAhpFjmxRVEEtmxH"
}
}
],
"assets_hash" : "3bf279af496877a51303e91c36d42d64ba9d414de8c038719b842e6421a9dae0",
"balance" : 27034700,
"metadatas" : null,
"metadatas_hash" : "ad67d57ae19de8068dbcd47282146bd553fe9f684c57c8c114453863ee41abc3",
"nonce" : 5,
"priv" : {
"master_weight" : 1,
"thresholds" : [{
"tx_threshold" : 1
}
]
}
}
}
address: ��ǰ��ѯ���˻���ַ
assets: �˻��ʲ��б�
assets_hash: �ʲ��б�hash
balance: �˻��ʲ����
metadata: ���ױ�ע��������16����
metadatas_hash: ���ױ�עhash
nonce: ת�����������кţ�ͨ����ѯ�˻���Ϣ�ӿڷ��ص�nonce + 1
priv: Ȩ��
master_weight: ��ǰ�˻�Ȩ��
thresholds: ����
tx_threshold: ����Ĭ������
```

2.��ɽ���������䡣

ͨ�� Keypair �е� [���ɵ�ַ](#���ɵ�ַ)���ɵ����˻�B�ĵ�ַ��`buQoP2eRymAcUm3uvWgQ8RnjtrSnXBXfAzsV`������json�������£�

```
{
"source_address":"buQsurH1M4rjLkfjzkxR9KXJ6jSu2r9xBNEw",
"nonce":7,
"ceil_ledger_seq": 0,
"fee_limit":1000000,
"gas_price": 1000,
"metadata":"",
"operations":[
{
"type": 1,
"create_account": {
"dest_address": "buQoP2eRymAcUm3uvWgQ8RnjtrSnXBXfAzsV",
"init_balance": 10000000,
"priv": {
"master_weight": 1,
"thresholds": {
"tx_threshold": 1
}
}
}
}
]
}
```
>**ע��**�������nonceֵ����6��û����������˸ý��׻ᳬʱ������ɹ���

3.�Խ������ݽ������л�����

```
POST http://seed1.bumotest.io:26002/getTransactionBlob
```

������:
4.1.2������json����
��Ӧ����:

```
{
"error_code": 0,
"error_desc": "",
"result": {
"hash": "be4953bce94ecd5c5a19c7c4445d940c6a55fb56370f7f606e127776053b3b51",
"transaction_blob": "0a2462755173757248314d34726a4c6b666a7a6b7852394b584a366a537532723978424e4577100718c0843d20e8073a37080122330a246275516f50326552796d4163556d33757657675138526e6a7472536e58425866417a73561a0608011a0208012880ade204"
}
}
```

4.ͨ��˽Կ�Խ��ף�transaction_blob��ǩ����


�����:import io.bumo.encryption.key.PrivateKey;

˽Կ��:

```
privbvTuL1k8z27i9eyBrFDUvAVVCSxKeLtzjMMZEqimFwbNchnejS81
```
ǩ�����sign_data�ǣ�

```
9C86CE621A1C9368E93F332C55FDF423C087631B51E95381B80F81044714E3CE3DCF5E4634E5BE77B12ABD3C54554E834A30643ADA80D19A4A3C924D0B3FA601
```

5.��ɽ���������䡣

```
{
"items" : [{
"transaction_blob" : "0a2462755173757248314d34726a4c6b666a7a6b7852394b584a366a537532723978424e4577100718c0843d20e8073a37080122330a246275516f50326552796d4163556d33757657675138526e6a7472536e58425866417a73561a0608011a0208012880ade204",                        
"signatures" : [{
"sign_data" : "9C86CE621A1C9368E93F332C55FDF423C087631B51E95381B80F81044714E3CE3DCF5E4634E5BE77B12ABD3C54554E834A30643ADA80D19A4A3C924D0B3FA601",
"public_key" : "b00179b4adb1d3188aa1b98d6977a837bd4afdbb4813ac65472074fe3a491979bf256ba63895"
}
]
}
]
}
```

6.ͨ��POST�ύ���ס�

```
POST http://seed1.bumotest.io/submitTransaction
```

�õ����µ���Ӧ���ģ�

```
{
"results": [{
"error_code": 0,
"error_desc": "",
"hash": "be4953bce94ecd5c5a19c7c4445d940c6a55fb56370f7f606e127776053b3b51"
}
],
"success_count": 1
}
```
>**˵��**����success_count��:1��ʾ�ύ�ɹ���

### �Լ�����transaction_blobʾ��
�Լ�����transaction_blob����JavaΪ�����������²��裺

1.ͨ��GET��ȡ���������˻���nonceֵ��

```
GET http://seed1.bumotest.io:26002/getAccount?address=buQsurH1M4rjLkfjzkxR9KXJ6jSu2r9xBNEw
```

�õ�����Ӧ���ģ�

```
{
"error_code" : 0,
"result" : {
"address" : "buQsurH1M4rjLkfjzkxR9KXJ6jSu2r9xBNEw",
"assets" : [
{
"amount" : 1000000000,
"key" : {
"code" : "HNC",
"issuer" : "buQBjJD1BSJ7nzAbzdTenAhpFjmxRVEEtmxH"
}
}
],
"assets_hash" : "3bf279af496877a51303e91c36d42d64ba9d414de8c038719b842e6421a9dae0",
"balance" : 27034700,
"metadatas" : null,
"metadatas_hash" : "ad67d57ae19de8068dbcd47282146bd553fe9f684c57c8c114453863ee41abc3",
"nonce" : 5,
"priv" : {
"master_weight" : 1,
"thresholds" : [{
"tx_threshold" : 1
}
]
}
}
}
address: ��ǰ��ѯ���˻���ַ
assets: �˻��ʲ��б�
assets_hash: �ʲ��б�hash
balance: �˻��ʲ����
metadata: ���ױ�ע��������16����
metadatas_hash: ���ױ�עhash
nonce: ת�����������кţ�ͨ����ѯ�˻���Ϣ�ӿڷ��ص�nonce + 1
priv: Ȩ��
master_weight: ��ǰ�˻�Ȩ��
thresholds: ����
tx_threshold: ����Ĭ������
```

2.��佻�ף�Transaction�����ݽṹ��������transaction_blob��

�����:import io.bumo.sdk.core.extend.protobuf.Chain;


```
Chain.Transaction.Builder builder = Chain.Transaction.newBuilder();
builder.setSourceAddress("buQsurH1M4rjLkfjzkxR9KXJ6jSu2r9xBNEw");
builder.setNonce(7);
builder.setFeeLimit(1000 * 1000);
builder.setGasPrice(1000);
builder.setCeilLedgerSeq(0);
builder.setMetadata(ByteString.copyFromUtf8(""));
Chain.Operation.Builder operation = builder.addOperationsBuilder();
operation.setType(Chain.Operation.Type.CREATE_ACCOUNT);
Chain.OperationCreateAccount.Builder operationCreateAccount = Chain.OperationCreateAccount.newBuilder();
operationCreateAccount.setDestAddress("buQoP2eRymAcUm3uvWgQ8RnjtrSnXBXfAzsV");
operationCreateAccount.setInitBalance(10000000);
Chain.AccountPrivilege.Builder accountPrivilegeBuilder = Chain.AccountPrivilege.newBuilder();
accountPrivilegeBuilder.setMasterWeight(1);
Chain.AccountThreshold.Builder accountThresholdBuilder = Chain.AccountThreshold.newBuilder();
accountThresholdBuilder.setTxThreshold(1);
accountPrivilegeBuilder.setThresholds(accountThresholdBuilder);
operationCreateAccount.setPriv(accountPrivilegeBuilder);
operation.setCreateAccount(operationCreateAccount);
String transaction_blob = HexFormat.byteToHex(builder.build().toByteArray());
�õ���transaction_blob�ǣ�
0a2462755173757248314d34726a4c6b666a7a6b7852394b584a366a537532723978424e4577100718c0843d20e8073a37080122330a246275516f50326552796d4163556d33757657675138526e6a7472536e58425866417a73561a0608011a0208012880ade204
```
>**ע��**�������nonceֵ����6��û����������˸ý��׻ᳬʱ������ɹ���

3.ͨ��˽Կ�Խ��ף�transaction_blob��ǩ����

�����:import io.bumo.encryption.key.PrivateKey;

˽Կ�ǣ�

```
privbvTuL1k8z27i9eyBrFDUvAVVCSxKeLtzjMMZEqimFwbNchnejS81
```
ǩ�����sign_data�ǣ�

```
9C86CE621A1C9368E93F332C55FDF423C087631B51E95381B80F81044714E3CE3DCF5E4634E5BE77B12ABD3C54554E834A30643ADA80D19A4A3C924D0B3FA601
```

4.��ɽ���������䡣

```
{
"items" : [{
"transaction_blob" : "0a2462755173757248314d34726a4c6b666a7a6b7852394b584a366a537532723978424e4577100718c0843d20e8073a37080122330a246275516f50326552796d4163556d33757657675138526e6a7472536e58425866417a73561a0608011a0208012880ade204",                        
"signatures" : [{
"sign_data" : "9C86CE621A1C9368E93F332C55FDF423C087631B51E95381B80F81044714E3CE3DCF5E4634E5BE77B12ABD3C54554E834A30643ADA80D19A4A3C924D0B3FA601",
"public_key" : "b00179b4adb1d3188aa1b98d6977a837bd4afdbb4813ac65472074fe3a491979bf256ba63895"
}
]
}
]
}
```

5.ͨ��POST�ύ���ס�

```
POST http://seed1.bumotest.io/submitTransaction
```
�õ�����Ӧ���ģ�

```
{
"results": [{
"error_code": 0,
"error_desc": "",
"hash": "be4953bce94ecd5c5a19c7c4445d940c6a55fb56370f7f606e127776053b3b51"
}
],
"success_count": 1
}
```
>**˵��**��"success_count":1���������ύ�ɹ���