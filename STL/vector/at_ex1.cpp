#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main(int argv, char* argc[])
{
  vector<int> v(10);
  int i;

  try{
	for(i=0; i<100; i++)
	  v.at(i) = 100;
  } catch(out_of_range except){
	cerr << "Out of vector range" << endl;
	cerr << "At location : " << i << endl;
  }

  // これはプログラムがクラッシュする(core dump)
  // for(i=0; i<100; i++) i=100;
  
  return 0;
}
