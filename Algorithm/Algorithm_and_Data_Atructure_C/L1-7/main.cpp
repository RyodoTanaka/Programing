#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  cout << "----------九九の表----------" << endl;
  for(int i=1; i<=9; i++){
    for(int j=1; j<=9; j++)
      cout << i*j;
    cout << endl;
  }

  return 0;
}
