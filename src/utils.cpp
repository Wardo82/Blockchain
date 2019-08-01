// Crypto++ libraries
#include "cryptopp/sha.h"
#include "cryptopp/filters.h"
#include "cryptopp/hex.h"

using namespace CryptoPP;

string hash_SHA256(const string* p_hashSource)
{
    SHA256 hash;
    string digest;

    StringSource s(p_hashSource, true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));

    return digest;
}