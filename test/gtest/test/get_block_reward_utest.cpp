#include "gtest/gtest.h"
#include "common/general.h"

/*
����5��
ʮ��һ���飬һ�� 3153600�飬���� 3153600 * 5 = 15768000��

ÿ��Ľ�����250000000 / 15768000 = 15.85489599188229

���ƹ��̣�
ÿ���齱��15���ң�15 * 3153600 * 5 * 2 = 473040000
*/
class decrement_value_utest : public testing::Test
{
protected:

    // Sets up the test fixture.
    virtual void SetUp()
    {
    }

    // Tears down the test fixture.
    virtual void TearDown()
    {

    }

protected:
    void UT_Calc_Block_Decrement_Vaule();
};

TEST_F(decrement_value_utest, UT_Calc_Block_Decrement_Vaule){ UT_Calc_Block_Decrement_Vaule(); }
void decrement_value_utest::UT_Calc_Block_Decrement_Vaule()
{
	//��׼����
	EXPECT_EQ(bumo::GetBlockReward(0 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 1);
	EXPECT_EQ(bumo::GetBlockReward(1 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 1);
	EXPECT_EQ(bumo::GetBlockReward(1 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 2);
	EXPECT_EQ(bumo::GetBlockReward(1 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 2);

	EXPECT_EQ(bumo::GetBlockReward(2 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 2);
	EXPECT_EQ(bumo::GetBlockReward(2 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 4);
	EXPECT_EQ(bumo::GetBlockReward(2 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 4);

	EXPECT_EQ(bumo::GetBlockReward(3 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 4);
	EXPECT_EQ(bumo::GetBlockReward(3 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 8);
	EXPECT_EQ(bumo::GetBlockReward(3 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 8);

	EXPECT_EQ(bumo::GetBlockReward(4 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 8);
	EXPECT_EQ(bumo::GetBlockReward(4 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 16);
	EXPECT_EQ(bumo::GetBlockReward(4 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 16);

	EXPECT_EQ(bumo::GetBlockReward(5 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 16);
	EXPECT_EQ(bumo::GetBlockReward(5 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 32);
	EXPECT_EQ(bumo::GetBlockReward(5 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 32);

	EXPECT_EQ(bumo::GetBlockReward(6 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 32);
	EXPECT_EQ(bumo::GetBlockReward(6 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 64);
	EXPECT_EQ(bumo::GetBlockReward(6 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 64);

	EXPECT_EQ(bumo::GetBlockReward(7 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 64);
	EXPECT_EQ(bumo::GetBlockReward(7 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 128);
	EXPECT_EQ(bumo::GetBlockReward(7 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 128);

	EXPECT_EQ(bumo::GetBlockReward(8 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 128);
	EXPECT_EQ(bumo::GetBlockReward(8 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 256);
	EXPECT_EQ(bumo::GetBlockReward(8 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 256);

	EXPECT_EQ(bumo::GetBlockReward(9 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 256);
	EXPECT_EQ(bumo::GetBlockReward(9 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 512);
	EXPECT_EQ(bumo::GetBlockReward(9 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 512);

	EXPECT_EQ(bumo::GetBlockReward(10 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 512);
	EXPECT_EQ(bumo::GetBlockReward(10 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 1024);
	EXPECT_EQ(bumo::GetBlockReward(10 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 1024);

	EXPECT_EQ(bumo::GetBlockReward(11 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 1024);
	EXPECT_EQ(bumo::GetBlockReward(11 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 2048);
	EXPECT_EQ(bumo::GetBlockReward(11 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 2048);

	EXPECT_EQ(bumo::GetBlockReward(12 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 2048);
	EXPECT_EQ(bumo::GetBlockReward(12 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 4096);
	EXPECT_EQ(bumo::GetBlockReward(12 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 4096);

	EXPECT_EQ(bumo::GetBlockReward(13 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 4096);
	EXPECT_EQ(bumo::GetBlockReward(13 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 8192);
	EXPECT_EQ(bumo::GetBlockReward(13 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 8192);

	EXPECT_EQ(bumo::GetBlockReward(14 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 8192);
	EXPECT_EQ(bumo::GetBlockReward(14 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 16384);
	EXPECT_EQ(bumo::GetBlockReward(14 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 16384);

	EXPECT_EQ(bumo::GetBlockReward(15 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 16384);
	EXPECT_EQ(bumo::GetBlockReward(15 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 32768);
	EXPECT_EQ(bumo::GetBlockReward(15 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 32768);

	EXPECT_EQ(bumo::GetBlockReward(16 * bumo::General::REWARD_PERIOD - 1), bumo::General::REWARD_INIT_VALUE / 32768);
	EXPECT_EQ(bumo::GetBlockReward(16 * bumo::General::REWARD_PERIOD), bumo::General::REWARD_INIT_VALUE / 65536);
	EXPECT_EQ(bumo::GetBlockReward(16 * bumo::General::REWARD_PERIOD + 1), bumo::General::REWARD_INIT_VALUE / 65536);
}
