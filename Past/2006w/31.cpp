#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

#define N 100

int main(int argv, char* argc[])
{
  unsigned int input;
  cin >> input;
 
  unsigned int d[7];
  for(int i=0; i<8; i++)
	d[i] = input & (unsigned int)pow((double)2,(double)i);

  unsigned int data[N+2] = {0};
  unsigned int output[N];
  data[40+1] = 1;
  data[0] = data[N];
  data[N+1] = data[1];
  
  for(int i=1; i<N+1; i++){
	int index = data[i-1]*4 + data[i]*2 + data[i+1];
	output[i-1] = d[index];	
  }

  for(int i=0; i<N; i++){
	if(!data[i+1])
	  cout << ".";
	else
	  cout << "#";
  }
  cout << endl;
  
  for(int i=0; i<N; i++){
	if(!output[i])
	  cout << ".";
	else
	  cout << "#";
  }
  cout << endl;

  return 0;
}
