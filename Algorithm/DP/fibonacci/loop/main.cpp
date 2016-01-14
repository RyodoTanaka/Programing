#include <iostream>
#include <vector>

using namespace std;

int n = 9;      // 求めたい番号
int cnt = 0;	// ループカウンタ

vector<int> dp(n+1, -1);

int fib(int req)
{
  int res;
  if(req == 0) res = 0;
  if(req == 1) res = 1;

  for(int i=2; i<=req; i++){
	cnt++;
	dp[i] = dp[req-1] + dp[req-2];
  }
	
  res = dp[i];
  
  return res;
}

int main(int argc, char* argv[])
{
  
  cout << fib(n) << endl;
  cout << cnt << endl;
  
  for(size_t i=0; i<dp.size(); i++)
	cout << dp[i] << endl;
  
  return 0;
}
