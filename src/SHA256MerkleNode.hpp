//
// Created by Eduardo Andres Flores Barreto on 2019-08-01.
//
#pragma once

// C++ standard libraries.
#include <iostream>
#include <string>

#include "MerkleNode.hpp"
#include "utils.cpp"

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#define SHA256_DIGEST_LENGTH = 256

using namespace std;

class SHA256MerkleNode : public MerkleNode<string, hash_SHA256, SHA256_DIGEST_LENGTH> {

    const char *computeHash();
private:

};

const char* SHA256MerkleNode::computeHash()
{
    // Concatenate the hashes of the left and the right children
    string hashSource;
    if (this.m_left & this.m_right){ // If the nodes has both children
        hashSource = str(m_left->getHash()) + str(m_right->getHash());
    }else if (m_left & !m_right){ // If the node only has the left children
        hashSource = str(m_left->getHash()) + str(m_left->getHash());
    }

    string digest = hashFunction(hashSource);

    return digest;
}