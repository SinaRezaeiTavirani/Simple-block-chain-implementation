#pragma once
#include "Block.h"
#include <iostream>

class BlockChain
{
public: 
	BlockChain(std::string time_stamp, std::string data);
	BlockChain() {}
	void add_block(Block block);
	Block& get_latest_block();	
	void print_chain();
	bool is_chain_valid();
	int get_block_chain_size();

private:
	std::vector <Block> chain_;
	Block create_genesis_block(std::string time_stamp, std::string data);
	Block default_block;

};

