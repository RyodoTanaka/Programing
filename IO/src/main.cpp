#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{  
  // Read the file. And find ";".
  char ch;
  int cnt = 0;
  while(!cin.eof()){
    cin >> ch;
    if(ch==';')
      cnt++;
  }
  cout << "The number of ; is ..." << cnt << endl;
  
  return 0;
}
