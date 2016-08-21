#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <limits>

using namespace std;

// INF の定義
const int INF = numeric_limits<int>::max();

// 辺にコストがある場合
struct edge{
  int to;
  int cost;
};

bool edge_sort_less(const edge& left,const edge& right){
    return left.to < right.to;
}

bool edge_sort_greater(const edge& left,const edge& right){
    return left.to > right.to;
}

void getGraph(vector< vector<edge> >&G, char* filename, int start, int goal)
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
	int data[2];
	istringstream line_separater(buf);
	for(int i=0; ;i++){
	  if(line_separater.eof())
		break;
	  getline(line_separater, spreat_buf, delimiter);
	  data[i] = atoi(spreat_buf.c_str());
	}

	// 無向グラフの隣接リストを作成
	// 有向ぐらふなら一方だけ
 	edge tmp;
	tmp.to = data[1] - 1;
	tmp.cost = data[2];
	G[data[0]-1].push_back(tmp);
	tmp.to = data[0] - 1;
	G[data[1]-1].push_back(tmp);
  }
  // = file 読み込み ========================================

  // = リストの整理 ===================================
  for(int i=0; i<G.size(); i++){
	// == 各隣接リストをソート ==
	sort(G[i].begin(),G[i].end(), edge_sort_less); // 昇順
	//sort(G[i].begin(), G[i].end(), edge_sort_greater); //降順
  } 
  // = リストの整理 ====================================
  
}

ostream& operator<<(ostream& os, const vector< vector<edge> >& g)
{
  vector<edge>::const_iterator itr;
  for(size_t i=0; i<g.size(); i++){
	os << "G[" << i << "] : "; 
	for(itr=g[i].begin(); itr<g[i].end(); itr++)
	  os << "(" << itr->to << ", " << itr->cost << ")";
	os << endl;
  }
  
  return os;
}

const int V = 12;  // 頂点の数
const int E = 12;  // 辺の数

typedef pair<int, int> P; // first:最短距離，second:頂点の番号

void bellman_ford(int s, const vector< vector<edge> > G)
{
  vector<int> d(V);  // 最短コスト
  fill(d.begin(), d.end(), INF);
  d[s] = 0;

  while(true){
	bool update = false;
	for(size_t i=0; i<G.size() ; i++){
	  for(vector<edge>::const_iterator itr=G[i].begin(); itr<G[i].end(); itr++){
		if(d[i] != INF && d[itr->to] > d[i] + itr->cost){
		  d[itr->to] = d[i] + itr->cost;
		  update = true;
		}
	  }
	}
	if(!update) break;
  }

  cout << "from V : " << s << endl;
  for(size_t i=0; i<d.size(); i++)
	cout << "d[" << i << "] : " << d[i] << endl;
}

int main(int argc, char** argv)
{
  vector< vector<edge> > G;
  G.resize(V);
  getGraph(G, argv[1], 0, 11);
  cout << G << endl;
  bellman_ford(0, G);

  return 0;
}
