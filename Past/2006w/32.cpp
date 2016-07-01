#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

#define N 123

int main(int argv, char* argc[])
{
  unsigned int input;
  cin >> input;
 
  unsigned int d[8];
  for(int i=0; i<8; i++)
	d[i] = input & (unsigned int)pow((double)2,(double)i);

  unsigned int data[N+2] = {0};
  unsigned int output[N];
  int tmp_cnt = 0;
  for(int j=0; j<N; j++){
	tmp_cnt = 0;
	for(int i=0; i<7; i++){
	  if(j & (unsigned int)pow((double)2,(double)i))
		tmp_cnt++;
	}
	if(tmp_cnt == 3)
	  data[j+1] = 1;
  }
  
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
