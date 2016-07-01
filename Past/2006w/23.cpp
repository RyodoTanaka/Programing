#include <iostream>
#include <bitset>

using namespace std;

unsigned int get_inv_d(unsigned int input)
{
  //cout << int(input) << endl;
  
  unsigned int data_1 = input & 0x0002;
  unsigned int data_3 = input & 0x0008;
  unsigned int data_4 = input & 0x0010;
  unsigned int data_6 = input & 0x0040;
  unsigned int data = input & 0x00a5;
  
  data_1 = data_1 << 3;
  data_3 = data_3 << 3;
  data_4 = data_4 >> 3;
  data_6 = data_6 >> 3;
  
  data = data | data_1 | data_3 | data_4 | data_6;
  
  bitset<8> input_print(input);
  bitset<8> data_print(data);
 
  //cout << input_print << " -> " << data_print << endl;

  return data;
}

int main(int argv, char* argc[])
{
  int cnt = 0;
  
  for(unsigned int i=0; i<256; i++){
	if(i == get_inv_d(i))
	  cnt++;
  }

  cout << cnt << endl;

  return 0;
}
