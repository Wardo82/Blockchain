#pragma once
/*=============================================================================
--------------------------------- Includes -------------------------------------
==============================================================================*/
// C++ standard libraries.
#include <iostream>
#include <string>

// Crypto++ libraries
#include <cryptopp/sha.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

// Custom libraries.
#include "DummyData.hpp"

using namespace std;
using namespace CryptoPP;

/*=============================================================================
----------------------------- Class declaration -------------------------------
==============================================================================*/
template <class T>
class Block
{
public:
  // ----------------- CONSTRUCTORS. ------------------
  // Default Constructor.
  Block();
  // Constructor with parameters.
  Block(unsigned int index, const string timestamp, CDummyData<T>& data, Block<T>& previousBlock);
  // Copy Constructor.
  Block(const Block<T>& block);

  // Destructor.
  ~Block(){};

  // -------------------- GETTERS --------------------
  unsigned int getIndex() const { return m_index; };
  string getHash() const { return m_hash; };
  Block* getPreviousBlock() { return m_previousBlock; };

  // --------------------- SETTERS --------------------
  void setPreviousBlock(Block<T>& block) { m_previousBlock = &block; };

  // Hash Block and returns the hash as a string.
  string hashBlock();

private:
  // ------------------------- Variables ----------------------------
  // Height of the block.
  unsigned int m_index;
  // Time stamp where the block was created.
  string m_timestamp;
  // Data to be stored on the blockchain.
  CDummyData<T>* m_data;
  // Previous block.
  Block<T>* m_previousBlock;
  // This block's hash.
  string m_hash;
};

/*
 * Class Implementation
 */
// Constructor
template <class T>
Block<T>::Block()
{
  m_index = 0;

  m_timestamp = "00/00/0000";

  m_data = NULL;

  m_previousBlock = NULL;

  m_hash = "Block without information.";
}

// Constructor with parameters.
template <class T>
Block<T>::Block(unsigned int index, const string timestamp, CDummyData<T>& data,Block<T>& previousBlock)
{
  m_index = index;

  m_timestamp = timestamp;

  m_data = &data;

  m_previousBlock = &previousBlock;

  m_hash = this->hashBlock();
}

// Copy Constructor
template <class T>
Block<T>::Block(const Block& block)
{
  m_index = block.m_index;

  m_timestamp = block.m_timestamp;

  m_data = block.m_data;

  m_previousBlock = block.m_previousBlock;

  m_hash = block.getHash();
}

// Hash Block data.
templat
string Block<T>::hashBlock()
{
  SHA256 hash;
  string digest;

  string hashSource = to_string(m_index) + m_timestamp + m_data->hashData() + m_previousBlock->getHash();

  StringSource s(hashSource, true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));

  m_hash = digest;

  return digest;
}
