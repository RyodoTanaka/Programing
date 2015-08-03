#include "sort.hpp"
#include <iostream>

using namespace std;

void Sort::Bubble()
{
  cout << "Start Bubble Sort" << endl;
  TimerStart();
  for(int i=0; i<data_size-1; i++){
    for(int j=data_size-1; j>i; j--){
      if(data[j-1] > data[j])
	swap(j-1, j);
    }
  }
  TimerStop();
  cout << "Finish Bubble Sort" << endl;
  show_times();
}

void Sort::Quick()
{
  cout << "Start Quick Sort" << endl;
  TimerStart();
  quick_sort(0, data_size-1);
  TimerStop();
  show_times();
}

void Sort::quick_sort(int i, int j)
{
  if(i >= j)
    return;
  int pivot = find_pivot(i,j);
  i++;
  // int k = partition(i, j, pivot);
  // quick_sort(i, k-1);
  // quick_sort(k, j);
}

inline void Sort::swap(int i, int j)
{
  int tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

inline int Sort::find_pivot(int i, int j)
{
  if(i > j){
    int tmp = j;
    j = i;
    i = tmp;
  }

  int k = i;

  for(k=i; (data[k] == data[k+1]) || (k < j); k++);

  if(data[k] > data[k+1])
    return data[k];
  else 
    return data[k+1];
}

inline int Sort::partition(int l, int r, int pivot)
{
  if(l > r){
    int tmp = r;
    r = l;
    l = tmp;
  }
  while(l <= r){
    while(data[l] < pivot)
      l++;
    while(data[r] >= pivot)
      r--;
    if(l > r)
      break;
    swap(l, r);
  }

  return l;
}
