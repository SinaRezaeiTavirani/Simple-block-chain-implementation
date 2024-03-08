#include "BlockChain.h"

BlockChain::BlockChain(std::string time_stamp, std::string data)
{
	chain_.push_back(create_genesis_block(time_stamp, data));
}

Block BlockChain::create_genesis_block(std::string time_stamp, std::string data)
{
	return Block{0,data, time_stamp};
}

 Block& BlockChain::get_latest_block()
{
	 if (chain_.size() != 0)
		 return chain_[chain_.size() - 1];
	 else
		 return default_block;
}

void BlockChain::print_chain()
{
	for (auto block : chain_)
	{
		Block::BlockInfo block_info;
		block_info = block.get_block_info();
		std::cout << "block index : " << block_info.index_ << "\n";
		std::cout << "	block data : " << block_info.data_ << "\n";
		std::cout << "	block hash : " << block_info.hash_ << "\n";
		std::cout << "	block previous hash : " << block_info.previous_hash_ << "\n";
	}
}

bool BlockChain::is_chain_valid()
{
	for (int i = 1; i < chain_.size(); i++)
	{
		auto current_block = chain_[i];
		auto previous_block = chain_[i - 1];

		if (current_block.get_block_info().hash_ != current_block.calculate_hash())
			return false;
		if (current_block.get_block_info().previous_hash_ != previous_block.get_block_info().hash_)
			return false;
	}
	return true;
}

int BlockChain::get_block_chain_size() {
	return chain_.size();
}




void BlockChain::add_block(Block block)
{
	std::string previous_hash = get_latest_block().get_block_info().hash_;
	block.get_block_info().previous_hash_ = previous_hash;
	block.get_block_info().hash_ = block.calculate_hash();
	chain_.push_back(block);
}
