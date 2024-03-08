#pragma once
#include "Block.h"

class BlockChain
{
public: 
	BlockChain(std::string time_stamp, std::string data);
	void add_block(Block block);
	Block get_latest_block();	
	void print_chain();
	bool is_chain_valid();

private:
	std::vector <Block> chain;
	Block create_genesis_block(std::string time_stamp, std::string data);

};

