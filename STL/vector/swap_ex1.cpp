#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
  vector<char> a;
  vector<char> b;

  int i;

  for(i = 0; i<5; i++){
	a.push_back('A' + i);
	b.push_back('Z' - i);
  }

  
  
  return 0;
}
