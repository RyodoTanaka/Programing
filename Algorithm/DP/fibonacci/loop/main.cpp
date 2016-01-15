#include <iostream>
#include <vector>

using namespace std;

int n = 9;      // 求めたい番号
int cnt = 0;	// ループカウンタ

vector<int> dp(n+1, -1);

int fib(int req)
{
  dp[0] = 0;
  dp[1] = 1;
  for(int i=2; i<=req; i++){
	cnt++;
	dp[i] = dp[i-1] + dp[i-2];
  }
  
  return dp[req];
}

int main(int argc, char* argv[])
{
  
  cout << fib(n) << endl;
  cout << cnt << endl;
  
  for(size_t i=0; i<dp.size(); i++)
	cout << dp[i] << endl;
  
  return 0;
}
