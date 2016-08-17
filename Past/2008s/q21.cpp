#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define V_MAX 100

int main(int argc, char** argv)
{
  vector<int> G[V_MAX];
  vector<int> G_deg(V_MAX);
  vector<double> cluster(V_MAX);
  
  // = file 読み込み ==========================================
  ifstream ifs(argv[1], ios::in);
  string buf;
  int cnt = 0;
  while(1){
	// read by line
	getline(ifs, buf);
	cnt++;
	if(cnt > 181)
	  break;
	// read by delimiter on reading "one" line
	const char delimiter = ' ';
	string spreat_buf;
	int edge[2];
	istringstream line_separater(buf);
	for(int i=0; ;i++){
	  if(line_separater.eof())
		break;
	  getline(line_separater, spreat_buf, delimiter);
	  edge[i] = atoi(spreat_buf.c_str());
	}

	// 無向グラフの隣接リストを作成
	G[edge[0]-1].push_back(edge[1]-1);
	G[edge[1]-1].push_back(edge[0]-1);
  }
  // = file 読み込み ========================================

  // 無向グラフの中身を確認
  vector<int>::iterator itr;
  for(int i=0; i<V_MAX; i++){
	// 各隣接リストをソート
	sort(G[i].begin(),G[i].end()); // 昇順
	//sort(G[i].begin(), G[i].end(), greater<int>()); //降順

	// 隣接リストのサイズを保存
	G_deg[i] = G[i].size();

	// 隣接リストの表示
  	cout << "G[" << i << "] : ";
  	for(itr=G[i].begin(); itr<G[i].end(); itr++)
  	  cout << *itr << ", ";
  	cout << endl;
  }

  // 次数を降順に表示
  for(size_t i; i<G_deg.size(); i++){
	itr = max_element(G_deg.begin(), G_deg.end()); // 最大値を取得（降順）
	//itr = min_element(G_deg.begin(), G_deg.end()); // 最小値を取得（昇順）
	size_t index = distance(G_deg.begin(), itr);
	cout << "G[" << index << "] : " << G[index].size() << endl; // 表示
	*itr = -*itr; // 最大値を反転
  }
  
  
  return 0;
}
