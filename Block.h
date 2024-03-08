#pragma once

#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

#include <string>
//#include <memory>	
#include <vector>

class Block
{
public:
	Block(int index, std::string data, std::string time_stamp, std::string previous_hash = "");
	Block();

	std::string calculate_hash();

	struct BlockInfo {
		int index_ = 0;
		std::string data_;
		std::string time_stamp_;
		std::string previous_hash_;
		std::string hash_;
	};
	BlockInfo get_block_info();
	void set_previous_hash(std::string previous_hash);
	void set_hash(std::string hash);

private:
	BlockInfo block_info_;
	
};

