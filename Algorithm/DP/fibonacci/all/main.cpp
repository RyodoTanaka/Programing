#include <iostream>
#include <vector>

using namespace std;

int n = 9;      // 求めたい番号
int cnt = 0;	// ループカウンタ

int fib(int req)
{
  cnt++;
  if(req == 0) return 0;
  if(req == 1) return 1;
  return fib(req-1) + fib(req-2);
}

int main(int argc, char* argv[])
{
  
  cout << fib(n) << endl;
  cout << cnt << endl;
  
  return 0;
}
