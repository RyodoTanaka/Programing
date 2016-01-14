#include <iostream>
#include <vector>

using namespace std;

int n = 9;      // 求めたい番号
int cnt = 0;	// ループカウンタ

vector<int> dp(n+1, -1);

int fib(int req)
{
  cnt++;
  int res;
  if(req == 0) res = 0;
  else if(req == 1) res = 1;
  else if(dp[req] >= 0) //  すでに計算したことが有る
	res = dp[req];
  else
	res = dp[req] = fib(req-1) + fib(req-2);
  return res;
}

int main(int argc, char* argv[])
{
  
  cout << fib(n) << endl;
  cout << cnt << endl;
  
  return 0;
}
