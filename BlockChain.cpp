#include "BlockChain.h"

BlockChain::BlockChain(std::string time_stamp, std::string data)
{
	chain.push_back(create_genesis_block(time_stamp, data));
}

Block BlockChain::create_genesis_block(std::string time_stamp, std::string data)
{
	return Block{0,data, time_stamp};
}

Block BlockChain::get_latest_block()
{
	return chain[chain.size()-1];
}

void BlockChain::print_chain()
{
	for (auto block : chain)
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
	for (int i = 1; i < chain.size(); i++)
	{
		auto current_block = chain[i];
		auto previous_block = chain[i - 1];

		if (current_block.get_block_info().hash_ != current_block.calculate_hash())
			return false;
		if (current_block.get_block_info().previous_hash_ != previous_block.get_block_info().hash_)
			return false;
	}
	return true;
}





void BlockChain::add_block(Block block)
{
	std::string previous_hash = get_latest_block().get_block_info().hash_;
	block.set_previous_hash(previous_hash);
	block.set_hash(block.calculate_hash());
	chain.push_back(block);
}
