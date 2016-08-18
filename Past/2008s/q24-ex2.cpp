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
		  flg = true;
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

// For sorting
bool sort_less(const binder& left,const binder& right){
    return left.E < right.E;
}
bool sort_greater(const binder& left,const binder& right){
    return left.E > right.E;
}

// for print
ostream& operator<<(ostream& os, const binder& b)
{
  os << b.start << ", " << b.goal << ", " << b.E << ", " << b.avg_cluster;
  return os;
}

int main(int argc, char** argv)
{
  vector< vector<int> > G;  // 隣接リスト
  G.resize(V);          
  vector<int> G_deg(V);     // 隣接リストの要素数
  int start = 1;			// 開始行数(1行目のカウントは１)
  int goal = 181;			// 終了行数


  vector<double> cluster(V); // クラスタ係数
  bool flg = false;          // 連結があるかどうか
  double avg_cluster;        // 平均くらすた係数
  binder smallest;
  int e = 1;
  smallest.E = 4950;
  
  // えだきりほうでしらべる
  // Q2の問題だから、181行目までなのかな...?
  // そうでなくとも、forを4950にしてしまえばOK
  for(int s=1; s+e-1<=181; s++){
	e=1;
	for(; e<smallest.E; e++){
	  getGraph(argv[1], s, s+e-1, G, G_deg);
	  if(getCluster(cluster, G)){
		smallest.start = s;
		smallest.goal = s+e-1;
		smallest.E = e;
		smallest.avg_cluster =  accumulate(cluster.begin(),cluster.end(),0.0)/(double)cluster.size();
		break;
	  }
	}
	G.clear();
	G.resize(V);
	G_deg.clear();
	G_deg.resize(V);
	cluster.clear();
	cluster.resize(V);
  }

  // vector<binder>::iterator b_itr;
  // for(b_itr=b_data.begin(); b_itr<b_data.end(); b_itr++)
  // 	cout << *b_itr << endl;
  // cout << "===============" << endl;
  
  //sort(b_data.begin(), b_data.end(), sort_less);    // 昇順
  // sort(b_data.begin(), b_data.end(), sort_greater); // 降順

  // for(b_itr=b_data.begin(); b_itr<b_data.end(); b_itr++)
  // 	cout << *b_itr << endl;

  cout << smallest << endl;

  // == 隣接リストの表示 ==
  // if(G[i].size()){
  // 	cout << "G[" << i << "] : ";
  // 	for(itr=G[i].begin(); itr<G[i].end(); itr++)	
  // 	  cout << *itr << ", ";
  // 	cout << endl;	  
  // }
  
  // // クラスタ係数の表示
  // for(size_t i=0; i<cluster.size(); i++)
  // 	cout << cluster[i] << endl;
  
  return 0;
}
