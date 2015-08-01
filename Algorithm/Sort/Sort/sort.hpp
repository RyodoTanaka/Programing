#ifndef __SORT__
#define __SORT__

#include "../Time/time.hpp"
#include "../Data/data.hpp"

class Sort : private Data, private Time
{
public :
  Sort(){ 
    data_raw = new int [n]; 
    for(int i=0; i<n; i++)
      data_raw[i] = data[i];
  }
  ~Sort(){ delete [] data_raw; }

  void Bubble();
  // void Quick();

  void ShowData(bool flg);
private :

  int* data_raw;
  void swap(int i, int j);
  // void find_pivot();
};

#endif
