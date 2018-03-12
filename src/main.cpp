/*=============================================================================
--------------------------------- Includes -------------------------------------
==============================================================================*/
#include <iostream>

#include "Block.hpp"
#include "DummyData.hpp"
/*------------------------------------------------------
--------------------- Namespaces -------------------------
------------------------------------------------------*/
using namespace std;

/*=============================================================================
----------------------------- Main Function -----------------------------------
==============================================================================*/
int main(/*int argc, char const *argv[]*/) {
  //TODO: Abstraer el tipo de dato timestamp y data.

  cout << "Test up and running." << endl;

  // Generating Genesis Block.
  CDummyData<int> Data1(100);
  Block<int> EmptyBlock;

  Block<int> Genesis (unsigned(0), "10/08/2017", Data1, EmptyBlock );
  Block<int>* previousBlock(&Genesis);

  cout << "Hash o Genesis block is: \n" << Genesis.hashBlock() << endl;

  const int numOfBlocks = 10;

  for (int i = 0; i < numOfBlocks; i++) {
    CDummyData<int> Data(i);
    Block<int>* block = new Block<int>(unsigned(previousBlock->getIndex()+1), "10/08/2017", Data, *previousBlock);

    cout << "Block with index: " << block->getIndex() << " and hash: \n" << block->getHash() << " generated." << endl;
    previousBlock = block;
  }
  return 0;
}
