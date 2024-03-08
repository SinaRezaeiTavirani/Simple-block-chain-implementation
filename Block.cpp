#include "Block.h"

Block::Block(int index, std::string data, std::string time_stamp, std::string previous_hash) : index_(index), data_(data), time_stamp_(time_stamp), previous_hash_(previous_hash)
{
	this->hash_ = this->calculate_hash();
}

std::string Block::calculate_hash()
{
	try {
		std::string hash_data = std::to_string(index_) + previous_hash_ + time_stamp_ + data_;
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
