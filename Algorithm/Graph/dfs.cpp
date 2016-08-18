#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

void getGraph(vector< vector<int> >&G, char* filename, int start, int goal)
{
  ifstream ifs(filename, ios::in);
  string buf;
  int cnt = 0;
  // = file 読み込み ==========================================
  // start行まで読み飛ばす
  for(int i=0; i<start; i++)
	getline(ifs,buf);
  while(1){
	// read by line
	getline(ifs,buf);
	cnt++;
	if(cnt > goal-start+1)
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

  // = リストの整理 ===================================
  vector<int>::iterator itr;
  for(int i=0; i<G.size(); i++){
	// == 各隣接リストをソート ==
	sort(G[i].begin(),G[i].end()); // 昇順
	//sort(G[i].begin(), G[i].end(), greater<int>()); //降順	  
  }
  // = リストの整理 ====================================
  
}

ostream& operator<<(ostream& os, const vector< vector<int> >& g)
{
  vector<int>::const_iterator itr;
  for(size_t i=0; i<g.size(); i++){
	os << "G[" << i << "] : ";
	for(itr=g[i].begin(); itr<g[i].end(); itr++)
	  os << *itr << ", ";
	os << endl;
  }
  return os;
}

int dfs(int v, vector<bool> &visit, const vector< vector<int> > G)
{
  if(visit[v])  // 探索済み
	return 0;
  else{         // 未探索
	visit[v] = true;
	cout << v << ", ";
	vector<int>::const_iterator itr;
	for(itr=G[v].begin(); itr<G[v].end(); itr++){
	  if(!visit[*itr])
		dfs(*itr, visit, G);
	}
	return 0;
  }	
}

void DFS(const vector< vector<int> > G)
{
  vector<bool> visit(G.size(), false); // 初期化(すべて未探索)
  
  dfs(0, visit, G);
  cout << endl;
}

const int V = 12;

int main(int argc, char** argv)
{
  vector< vector<int> > G;
  G.resize(V);
  getGraph(G, argv[1], 0, 11);
  cout << G << endl;
  DFS(G);
}
