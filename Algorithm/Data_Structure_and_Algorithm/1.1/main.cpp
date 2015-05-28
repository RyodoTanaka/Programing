#include <iostream>
#include <cstdlib>

using namespace std;

int Euclid(int m, int n){
  int r = m%n;
  if(r == 0){
    return n;
  }
  else{
    m = n;
    n = r;
    Euclid(m, n);
  }
}

int main(int argc, char* argv[])
{
  int m, n;
  if(argc != 3){
    cout << "Input 2 data" << endl;
    cin >> m >> n;
  }
  else{
    m = atoi(argv[1]);
    n = atoi(argv[2]);
  }

  cout << "Answer : " << Euclid(m, n) << endl;

  return 0;
}
