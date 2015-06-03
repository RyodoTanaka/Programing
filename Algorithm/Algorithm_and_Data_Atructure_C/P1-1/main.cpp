#include <iostream>

using namespace std;

int max4(int a, int b, int c, int d)
{
  int max = a;
  if(max < b)
    max = b;
  if(max < c)
    max = c;
  if(max < d)
    max = d;
  
  return max;
}

int main(int argc, char *argv[])
{
  int data[4];

  cout << "Input four datas" << endl;
  for(int i=0; i<4; i++)
    cin >> data[i];
  
  cout << "The max is : " << max4(data[0], data[1], data[2], data[3]) << endl;

  return 0;
}
