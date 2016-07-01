#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>

using namespace std;

#define N 860

int main(int argv, char* argc[])
{
  unsigned int input;
  cin >> input;
 
  unsigned int d[8];
  for(int i=0; i<8; i++)
	d[i] = input & (unsigned int)pow((double)2,(double)i);

  vector<unsigned int> data;
  unsigned int output[N];
  int tmp_cnt = 1;
  data.push_back(0);
  for(int i=1; i<N+1; i+=tmp_cnt+1){
	for(int j=0; j<tmp_cnt; j++)
	  data.push_back(0);
	data.push_back(1);
	tmp_cnt++;
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
