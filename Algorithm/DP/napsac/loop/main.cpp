#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100	// 商品の最大個数

int n = 4;			// 商品の合計個数
int W = 5;			// 商品の合計価値
vector<int> w, v;	// w : 重さ, v : 価値

vector< vector<int> > dp(n+1, vector<int>(W+1,0));  // DPの表(0で初期化)

int cnt = 0; // ループカウンタ

int main(int argc, char* argv[])
{
  // 初期代入
  w.push_back(2);
  w.push_back(1);
  w.push_back(3);
  w.push_back(2);
  w.push_back(0);

  v.push_back(3);
  v.push_back(2);
  v.push_back(4);
  v.push_back(2);
  v.push_back(0);

  for(int i=n-1; i>=0; i--)
	for(int u=1; u<=W; u++){
	  cnt++;
	  if(u < w[i])
		dp[i][u] = dp[i+1][u];
	  else
		dp[i][u] = max(dp[i+1][u], dp[i+1][u-w[i]]+v[i]);
	}

  cout << dp[0][W] << endl;
  cout << cnt << endl;
  
    
  return 0;
}
