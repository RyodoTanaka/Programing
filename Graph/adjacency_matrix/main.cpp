#include <iostream>
#include <vector>
#include <random>

#define MAX_V 1000

using namespace std;

int main(void)
{
  int v_num = 5; // 頂点の数
  vector< vector<int> > graph(5, vector<int>(5,0)); // グラフの初期化

  // 値の代入
  // 乱数の生成
  random_device rnd;
  mt19937 mt;
  mt.seed(rnd());
  
  for(int i=0; i<v_num; i++){
	for(int j=0; j<v_num; j++){
	  graph[i][j] = mt()%2;
	  cout << graph[i][j] << " ";
	}
	cout << endl;
  }
  
  return 0;
}
