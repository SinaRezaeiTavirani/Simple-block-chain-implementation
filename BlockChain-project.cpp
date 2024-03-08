#include <iostream>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <string>

using namespace CryptoPP;

int main() {
    try {
        // Input data to be hashed
        std::string data = "Hello, World!";

        // Hash object with SHA-256 algorithm
        SHA256 hash;

        // Hashing process
        byte digest[SHA256::DIGESTSIZE];
        hash.CalculateDigest(digest, (byte*)data.c_str(), data.length());

        // Convert the digest to a hex string representation
        HexEncoder encoder;
        std::string encoded;    
        encoder.Attach(new StringSink(encoded));
        encoder.Put(digest, sizeof(digest));
        encoder.MessageEnd();

        // Output the hashed data
        std::cout << "SHA-256 hash of '" << data << "' is: " << encoded << std::endl;
    }
    catch (const Exception& ex) {
        std::cerr << "Crypto++ library exception: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

