#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define V 100

void getGraph(char* filename, int start, int goal, vector< vector<int> >&G, vector<int> &G_deg)
{
  ifstream ifs(filename, ios::in);
  string buf;
  int cnt = 0;
  // = file 読み込み ==========================================
  // start行まで読み飛ばす
  for(int i=1; i<start; i++)
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

bool getCluster(vector<double> &cluster, vector< vector<int> > G)
{
  // == すべてのクラスタ係数を求め，連結成分の有無を調べる======================
  double sum = 0;    // 隣接頂点同士の隣接数の2倍の値
  double k = 0;      // 次数
  double tmp = 0;    // sum/2.取りうる値の最大値
  bool flg = false;  // クラスタ係数0以外があったか(連結成分があったか)

  vector<int>::iterator itr;
  vector<int>::iterator itr2;
  
  for(size_t i=0; i<G.size(); i++){
	for(itr=G[i].begin(); itr<G[i].end(); itr++){
	  for(itr2=G[i].begin(); itr2<G[i].end(); itr2++){
		if(find(G[*itr].begin(),G[*itr].end(), *itr2) != G[*itr].end()){
		  flg = true; // 連結があった
		  sum++;
		}
	  }
	}
	sum /= 2.;
	k = G[i].size();
	if(k<=1)
	  cluster[i] = 0.;
	else{
	  tmp = (k*(k-1))/2.;
	  cluster[i] = sum/tmp;
	}
	sum = 0;
	k = 0;
	tmp = 0;
  }

  return flg;
}

struct binder{
  int start;
  int goal;
  int E;
  double avg_cluster;
};

// for print
ostream& operator<<(ostream& os, const binder& b)
{
  os << b.start << ", " << b.goal << ", " << b.E << ", " << b.avg_cluster;
  return os;
}

int main(int argc, char** argv)
{
  vector< vector<int> > G3;  // 隣接リスト
  G3.resize(V);          
  vector<int> G3_deg(V);     // 隣接リストの要素数
  int start = 1;			// 開始行数(1行目のカウントは１)
  int goal = 181;			// 終了行数


  vector<double> cluster3(V); // クラスタ係数
  binder smallest;           // 最小エッジ数の情報
  int e = 1;                 // エッジ数カウンタ
  smallest.E = 4950;         // 最大エッジ数で初期化
  
  // 枝切り法で調べる
  // Q2の問題だから、181行目までなのかな...?
  // そうでなくとも、forを4950にしてしまえばOK
  for(int s=1; s+e-1<=181; s++){
	e=1;
	for(; e<smallest.E; e++){
	  getGraph(argv[1], s, s+e-1, G3, G3_deg);
	  if(getCluster(cluster3, G3)){
		smallest.start = s;
		smallest.goal = s+e-1;
		smallest.E = e;
		smallest.avg_cluster =  accumulate(cluster3.begin(),cluster3.end(),0.0)/(double)cluster3.size();
		break;
	  }
	}
	G3.clear();
	G3.resize(V);
	G3_deg.clear();
	G3_deg.resize(V);
	cluster3.clear();
	cluster3.resize(V);
  }
  
  vector< vector<int> > G4;
  G4.resize(V);
  vector<int> G4_deg(V);
  vector<double> cluster4(V);
  getGraph(argv[1], smallest.start, smallest.start+99, G4, G4_deg);
  getCluster(cluster4, G4);
  double avg_cluster4 = accumulate(cluster4.begin(), cluster4.end(),0.0)/(double)cluster4.size();

  cout << "G4 Avg Cluster : " << avg_cluster4 << endl;
  
  return 0;
}
