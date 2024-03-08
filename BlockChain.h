#pragma once
#include "Block.h"

class BlockChain
{
public: 
	BlockChain();
	void add_block(Block block);
	Block get_latest_block();	

private:
	Block create_genesis_block();

};

