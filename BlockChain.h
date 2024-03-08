#pragma once
#include "Block.h"

class BlockChain
{
public: 
	BlockChain();

private:
	Block create_genesis_block();
	Block get_latest_block();
	void add_block(Block block);

};

