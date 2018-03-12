#pragma once
/*=============================================================================
--------------------------------- Includes -------------------------------------
==============================================================================*/
// Custom libraries.
#include "Data.hpp"

using namespace std;
/*=============================================================================
----------------------------- Class declaration -------------------------------
==============================================================================*/
template <class T>
class CDummyData : public CData< CDummyData<int> >
{
public:
  // --------------------- Constructor --------------------
  // Default Constructor.
  CDummyData(){ m_num = T(); };
  // Constructor with parameters
  CDummyData(T num) { m_num = num; };

  // Destructor.
  ~CDummyData(){
    //CData::~CData();
  };

  // Hash Data and returns hashed string.
  string hashData() {return "Dummy Hash."; };

  void operator=(const CDummyData<T>& data) { m_num = data.m_num; };

private:
  T m_num;
};
