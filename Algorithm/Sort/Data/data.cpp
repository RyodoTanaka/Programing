#include "data.hpp"

using namespace std;

Data::Data()
{
  InitRand(); 

  cout << "How many datas ? : ";
  cin >> data_size;
  cout << "Max ? : ";
  cin >> max;
  cout << "Min ? : ";
  cin >> min;

  data = new int [data_size];

  for(int i=0; i<data_size; i++)
    data[i] = GetRand(max, min);
}

Data::~Data()
{
  delete [] data; 
}
