#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100	// 商品の最大個数

int n = 4;			// 商品の合計個数
int W = 5;			// 商品の合計価値
vector<int> w, v;	// w : 重さ, v : 価値

// i番目までで重さがu以下の価値の最大値を返す
int search(int i, int u)
{
  if(i == n) // 合計個数に到達していたら終了
	return 0;
  else if(u < w[i]) // uより重さが重たくなったらi番目のを使用しない
	return search(i+1, u);
  else{
	int ret1 = search(i+1, u);				// i番目を使用しない場合
	int ret2 = search(i+1, u-w[i]) + v[i];	// i番目を使用する場合
	return max(ret1, ret2);                 // 価値の高いほうを返す
  }
}


int main(int argc, char* argv[])
{
  w.push_back(2);
  w.push_back(1);
  w.push_back(3);
  w.push_back(2);

  v.push_back(3);
  v.push_back(2);
  v.push_back(4);
  v.push_back(2);
   
  cout << search(0, W) << endl;
    
  return 0;
}
