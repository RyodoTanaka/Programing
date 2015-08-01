#include "sort.hpp"
#include <iostream>

using namespace std;

void Sort::Bubble()
{
  cout << "Start Bubble Sort" << endl;
  TimerStart();
  for(int i=0; i<n-1; i++){
    for(int j=n-1; j>i; j--){
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

  TimerStop();
  show_times();
}

inline void Sort::swap(int i, int j)
{
  int tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

inline int Sort::find_pivot(int i, int j)
{
  int max = data[i];
  for(int k=i; k<=j; k++){
    if(data[k] > max)
      max = data[k]; 
  }
  return max;
}
