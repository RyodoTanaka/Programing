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
  cout << "It takes ... " << GetTime() << " [sec] ." << endl;
}
