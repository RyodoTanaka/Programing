#include "data.hpp"

using namespace std;

Data::Data()
{
  InitRand(); 

  cout << "How many datas ? : ";
  cin >> n;
  cout << "Max ? : ";
  cin >> max;
  cout << "Min ? : ";
  cin >> min;

  data = new int [n];

  for(int i=0; i<n; i++)
    data[i] = GetRand(max, min);
}
