#include <iostream>

using namespace std;

int min3(int a, int b, int c)
{
  int min = a;
  
  if(min > b)
    min = b;
  if(min > c)
    min = c;
  
  return min;
}

int main(int argc, char *argv[])
{
  int data[3];

  cout << "Input the datas" << endl;
  for(int i=0; i<3; i++)
    cin >> data[i];
  
  cout << "The minimum is : " << min3(data[0], data[1], data[2]) << endl;

  return 0;
}
