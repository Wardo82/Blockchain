#pragma once
/*=============================================================================
--------------------------------- Includes -------------------------------------
==============================================================================*/
// C++ standard library
#include <iostream>
#include <string>
using namespace std;
/*=============================================================================
----------------------------- Class declaration -------------------------------
==============================================================================*/
template <class T>
class CData
{
public:
  // --------------------- Constructor --------------------
  // Default Constructor.
  //CData();

  // Destructor.
  //virtual ~CData() = 0;

  // Hash Data and returns hashed string.
  virtual string hashData() = 0;

  virtual void operator=(const T& data) = 0;
};
