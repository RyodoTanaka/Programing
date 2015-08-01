#ifndef __DATA__
#define __DATA__

#include <iostream>
#include <cstdlib>

class Data{
public :

  int n;     // number of datas
  int* data;

  Data();
  ~Data(){ delete [] data; }

private :

  int max;  // maximum data
  int min;  // minimum data

  inline void InitRand(){ srand((int)time(NULL)); }
  inline int GetRand(int max, int min){ return (rand() % (max-min+1) + min); }
};

#endif
