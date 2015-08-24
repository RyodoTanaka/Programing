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
  // ifstream fin(filename.c_str());
  ifstream fin("./Data/program.txt");
  if(!fin){
    cerr << "Cannot open the file." << endl;
    exit(1);
  }
  
  // Read the file. And find ";".
  // char ch;
  // int cnt = 0;
  // while(!fin.eof()){
  //   fin >> ch;
  //   if(ch==';')
  //     cnt++;
  // }
  // cout << "The number of ; is ..." << cnt << endl;
  
  // Using getline
  int cnt = 0;
  string str;
  while(getline(fin,str,';')){
    cnt++;
    cout << str;
  }
  cout << cnt << endl;

  return 0;
}
