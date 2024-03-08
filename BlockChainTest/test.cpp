#include "pch.h"
#include "../BlockChain-project/BlockChain.h"


std::string get_current_time_stamp() {

	std::time_t currentTime;
	std::time(&currentTime);

	// Convert the current time to a struct tm
	std::tm timeInfo;
	localtime_s(&timeInfo, &currentTime);

	// Format the time into a string
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeInfo);

	return std::string(buffer);
}

class BlockChain_Fixture : public testing::Test
{
protected:
	void SetUp() override
	{
		block_chain_ = std::make_unique<BlockChain>(get_current_time_stamp(), "Genesis Block");
	}
	void TearDown() override
	{

	}
	std::unique_ptr<BlockChain> block_chain_;
};

TEST_F(BlockChain_Fixture, Genesis_block_test)
{
	Block block = block_chain_->get_latest_block();
	EXPECT_EQ(block.get_block_info().data_, "Genesis Block");
}
TEST_F(BlockChain_Fixture, add_block_test)
{
	Block block(1, "add test ", get_current_time_stamp());
	block_chain_->add_block(block);
	EXPECT_EQ(2, block_chain_->get_block_chain_size());
}
TEST_F(BlockChain_Fixture, get_previos_block_hash_test)
{
	std::string actual_previous_hash = block_chain_->get_latest_block().calculate_hash();
	block_chain_->add_block(Block(2, "another test", get_current_time_stamp()));
	std::string expected_previous_hash =  block_chain_->get_latest_block().get_block_info().previous_hash_;

	EXPECT_EQ(expected_previous_hash,actual_previous_hash);
}