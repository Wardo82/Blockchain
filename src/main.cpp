/*
 * Includes
 */
#include <iostream>

#include "SHA256MerkleNode.hpp"

using namespace std;

template<typename NodeType>
const NodeType *build(NodeType *nodes[], size_t len){
    if (len == 1) return new NodeType(nodes[0], nullptr);
    if (len == 2) return new NodeType(nodes[0], nodes[1]);

    size_t half = len % 2 == 0 ? len/2 : len/2 + 1;
    return new NodeType(build(nodes, half), build(nodes + half, len - half));
}

/*
 * Main
 */
int main() {
    //TODO: Abstraer el tipo de dato timestamp y data.

    cout << "Test up and running." << endl;

    // Generating Genesis Block.
    std::string sl[]{"spring", "winter", "summer", "fall"};
    SHA256MerkleNode *leaves[4];

    for (int i = 0; i<4; i++) {
        leaves[i] = new SHA256MerkleNode(sl[i]);
    }

    SHA256MerkleNode *a = new SHA256MerkleNode(leaves[0], leaves[1]);
    SHA256MerkleNode *b = new SHA256MerkleNode(leaves[2], leaves[3]);
    SHA256MerkleNode root(a, b);


    cout << "Hash o Genesis block is: \n" << str(root.getHash()) << endl;

    return 0;
}
