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
	std::string calculate_hash();

private:
	int index_;
	std::string data_;
	std::string time_stamp_;
	std::string previous_hash_;
	std::string hash_;
	
};

