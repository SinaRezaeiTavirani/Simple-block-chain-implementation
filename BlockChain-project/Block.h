#pragma once

#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

#include <string>
//#include <memory>	
#include <vector>
#include<iostream>

class Block
{
public:
	Block(int index, std::string data, std::string time_stamp, std::string previous_hash = "");
	Block();

	std::string calculate_hash();
	std::string mine_block(int difficulty);


	struct BlockInfo {
		int index_ = 0;
		std::string data_;
		std::string time_stamp_;
		std::string previous_hash_;
		std::string hash_;
		long long nonce_;
	};
	BlockInfo& get_block_info();


private:
	BlockInfo block_info_;
	
};

