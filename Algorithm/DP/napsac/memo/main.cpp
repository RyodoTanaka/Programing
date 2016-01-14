#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100	// 最大個数
#define MAX_U 100   // 最大の重さ

int n = 4;										// 合計個数
int W = 5;										// 規定の重さ
vector<int> w, v;								// w : 重さ, v : 価値
vector< vector<int> > memo(n+1,vector<int>(W+1,-1));   // 計算結果の保持

int cnt = 0; // search()に入ったカウント

// i番目までで重さがu以下の価値の最大値を返す
int search(int i, int u)
{
  cout << i << "\t" << u << endl;
  ++cnt;
  if(memo[i][u] >= 0){
	cout << "here : ";
	cout << i << "\t" << u << endl;
	return memo[i][u]; //すでに計算していたら、記録結果を返す
  }
	
  int res;
  if(i == n) // 合計個数に到達していたら終了
	res = 0;
  else if(u < w[i]) // uより重さが重たくなったらi番目のを使用しない
  	res =  search(i+1, u);
  else{
	// search(i+1, u);				// i番目を使用しない場合
	// search(i+1, u-w[i]) + v[i];	// i番目を使用する場合
	res = max(search(i+1, u), search(i+1, u-w[i])+v[i]); // 価値の高いほうを返す
  }
  return memo[i][u] = res; 
}


int main(int argc, char* argv[])
{
  w.push_back(2);
  w.push_back(2);
  w.push_back(3);
  w.push_back(2);

  v.push_back(3);
  v.push_back(2);
  v.push_back(4);
  v.push_back(2);
  
  cout << search(0, W) << endl;
  cout << cnt << endl;

  // for(int i=0; i<n; i++)
  // 	for(int j=0; j<W; j++)
  // 	  cout << memo[i][j] << endl;
    
  return 0;
}
