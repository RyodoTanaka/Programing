#ifndef __SORT__
#define __SORT__

#include "../Time/time.hpp"
#include "../Data/data.hpp"

#define SORTED true
#define RAW false

class Sort : private Data, private Time
{
public :
  Sort(){ 
    data_raw = new int [data_size]; 
    for(int i=0; i<data_size; i++)
      data_raw[i] = data[i];
  }
  ~Sort(){ delete [] data_raw; }

  void Bubble();
  void Quick();

  void ShowData(bool flg);
private :

  int* data_raw;

  void quick_sort(int i, int j);
  void show_times();

  void swap(int i, int j);
  int find_pivot(int i, int j);
  int partition(int i, int j, int pivot);
  
};

#endif
