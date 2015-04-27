#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
  string filename;
  cout << "Input File name" << endl;
  cin >> filename;
  
  // Open the file
  ifstream fin(filename.c_str());
  if(!fin){
    cerr << "Cannot open the file." << endl;
    
  }
  
  // Read the file. And find ";".
  char ch;
  int cnt = 0;
  while(!fin.eof()){
    fin >> ch;
    if(ch==';')
      cnt++;
  }
  cout << "The number of ; is ..." << cnt << endl;
  
  return 0;
}
