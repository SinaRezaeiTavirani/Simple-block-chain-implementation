#include "Block.h"

Block::Block(int index, std::string data, std::string time_stamp, std::string previous_hash) 
{
	block_info_.index_ = index;
	block_info_.data_ = data;
	block_info_.time_stamp_ = time_stamp;
	block_info_.previous_hash_ = previous_hash;
	block_info_.hash_ = this->calculate_hash();
	block_info_.nonce_ = 0;
}

Block::Block()
{	
}

std::string Block::calculate_hash()
{

	try {
		std::string hash_data = std::to_string(block_info_.index_) + block_info_.previous_hash_ + block_info_.time_stamp_ + block_info_.data_ + std::to_string(block_info_.nonce_);
		CryptoPP::SHA256 hash;
		std::vector<CryptoPP::byte> digest(CryptoPP::SHA256::DIGESTSIZE);
		hash.CalculateDigest(digest.data(), (CryptoPP::byte*)hash_data.c_str(), hash_data.size());

		CryptoPP::HexEncoder encoder;
		std::string encoded;
		encoder.Attach(new CryptoPP::StringSink(encoded));
		encoder.Put(digest.data(), digest.size());
		encoder.MessageEnd();

		return encoded;
	}
	catch(const CryptoPP::Exception &ex)
	{
		std::string exception_error = ex.what();
		return "Crypto++ library exception is " + exception_error;
	}
}

std::string Block::mine_block(int difficulty)
{
	std::string difficulty_zero(difficulty, '0');
	while (block_info_.hash_.substr(0, difficulty) != difficulty_zero) {
		block_info_.hash_ = calculate_hash();
		block_info_.nonce_++;
	}
	return block_info_.hash_;

}

Block::BlockInfo& Block::get_block_info()
{
	return block_info_;
}



