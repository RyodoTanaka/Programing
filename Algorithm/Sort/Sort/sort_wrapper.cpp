#include "sort.hpp"

using namespace std;

void Sort::ShowData(bool flg)
{
  if(flg){
    cout << "Sorted data ..." << endl;
    for(int i=0; i<n; i++)
      cout << data[i] << " ";
    cout << endl;
  }
  else{
    cout << "Raw Data ..." << endl;
    for(int i=0; i<n; i++)
      cout << data_raw[i] << " ";
    cout << endl;
  }
}

void Sort::swap(int i, int j)
{
  int tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}
