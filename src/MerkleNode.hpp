//
// Created by Eduardo Andres Flores Barreto on 2019-08-01.
//
#pragma once

using namespace std;

template <typename T, char* (hashFunction)(const T&), size_t hashLen>
class MerkleNode {
public:
    // Constructor: Builds a "leaf" node.
    MerkleNode(const T &value) : m_value(new T(value)), m_left(nullptr), m_right(nullptr) {
        m_hash = hashFunction(value);
    }

    // Build an "intermediate" node, storing the descendants as well as compound hash.
    MerkleNode(const MerkleNode *p_left, const MerkleNode *p_right) : m_left(p_left), m_right(p_right), m_value(nullptr) {}

    // Destructor: Deallocates the memory pointed to by the m_hash pointer;
    virtual ~MerkleNode() {
        if (m_hash) delete[](m_hash);
    }

    // Returns true if it has at least one children, false otherwise
    bool hasChildren() const {
        return m_left || m_right;
    }

    // Recursively validate the subtree rooted in this node
    virtual bool validate() const;

    /*
     * Getters
     */
    // Returns the length of the hash, also part of the template instantiation
    size_t getHashLen() const { return hashLen; }

    // Returns the buffer containing the hash value. Of length 'getHashLen()'
    const char *getHash() const { return m_hash; }

    // Return a pointer to the left child and the right child respectively
    const MerkleNode *getLeftChild() const { return m_left.get(); }
    const MerkleNode *getRightChild() const { return m_right.get(); }

protected:
    /**
    * Computes the hash of the children nodes' respective hashes.
    * In other words, given a node N, with children (N1, N2), whose hash values are,
    * respectively, H1 and H2, computes:
    *
    *     H = hash(H1 || H2)
    *
    * where `||` represents the concatenation operation.
    * If the `right_` descendant is missing, it will simply duplicate the `left_` node's hash.
    *
    * For a "leaf" node (both descendants missing), it will use the `hash_func()` to compute the
    * hash of the stored `value_`.
    */
    virtual const char *computeHash() const = 0;

    // Children of this node
    unique_ptr<const MerkleNode> m_left, m_right;
    // Computed hash of this node
    const char *m_hash;
    // Data stored in the node
    const shared_ptr<T> m_value;
    // Height of the block.
    unsigned int m_index;
    // Time stamp where the block was created.
    string m_timestamp;

};

/*
 * Class Implementation
 */
template <typename T, char* (hashFunction)(const T&), size_t hashLen>
bool MerkleNode<T, hashFunction, hashLen>::validate() const {
    // If either child is not valid, the entire subtree is invalid too
    if  (m_left && !m_left->validate()) {
        return false;
    }
    if  (m_right && !m_right->validate()) {
        return false;
    }

    unique_ptr<const char> computedHash(hasChildren() ? computeHash() : hashFunction(*m_value));
    return memcpm(m_hash, computedHash.get(), getHashLen()) == 0;
}

