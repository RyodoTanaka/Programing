#include "sort.hpp"

using namespace std;

void Sort::show_times()
{
  cout << "It takes ... " << GetTime() << " [sec] ." << endl;
}

void Sort::ShowData(bool flg)
{
  if(flg){
    cout << "Sorted data ..." << endl;
    for(int i=0; i<data_size; i++)
      cout << data[i] << " ";
    cout << endl;
  }
  else{
    cout << "Raw Data ..." << endl;
    for(int i=0; i<data_size; i++)
      cout << data_raw[i] << " ";
    cout << endl;
  }
}
