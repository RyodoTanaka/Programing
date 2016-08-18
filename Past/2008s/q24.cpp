#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define V_MAX 100
#define READ_NUM 181



int main(int argc, char** argv)
{

  double avg_cluster;
  int start;
  int cnt = 0;
  
  for(start=2; ;start++){
    bool flg = true;
	for(int i=0; flg; i++){
	  vector<int> G[V_MAX]; // 隣接リスト
	  vector<int> G_deg(V_MAX); // 次数
  
	  ifstream ifs(argv[1], ios::in);
	  string buf;
	  cnt = 0;
	  // = file 読み込み ==========================================
	  // start行まで読み飛ばす
	  for(int i=1; i<start; i++)
		getline(ifs,buf);
	  while(1){
		// read by line
		getline(ifs,buf);
		cnt++;
		if(cnt > i)
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

	  vector<int>::iterator itr;
	  for(int i=0; i<V_MAX; i++){
		// 各隣接リストをソート
		sort(G[i].begin(),G[i].end()); // 昇順
		//sort(G[i].begin(), G[i].end(), greater<int>()); //降順

		// 隣接リストの表示
		// if(G[i].size()){
		// 	cout << "G[" << i << "] : ";
		// 	for(itr=G[i].begin(); itr<G[i].end(); itr++)	
		// 	  cout << *itr << ", ";
		// 	cout << endl;	  
		// }
	  
	  }

	  // == すべてのクラスタ係数を求め，連結成分の有無を調べる======================
	  vector<double> cluster(V_MAX); // クラスタ係数
	  double sum = 0;
	  double k = 0;
	  double tmp = 0;
	  for(size_t i=0; i<cluster.size(); i++){
		for(itr=G[i].begin(); itr<G[i].end(); itr++){
		  vector<int>::iterator itr2;
		  for(itr2=G[i].begin(); itr2<G[i].end(); itr2++){
			if(find(G[*itr].begin(),G[*itr].end(), *itr2) != G[*itr].end()){
			  flg = false;
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
	  // クラスタ係数の表示
	  // if(flg==false){
	  //   for(size_t i=0; i<cluster.size(); i++)
	  // 	cout << cluster[i] << endl;
	  // }

	  // 平均クラスタ係数を求める
	  avg_cluster = accumulate(cluster.begin(),cluster.end(),0.0)/(double)cluster.size();
	  if(!flg)
		cout << "cnt : " << cnt << ", " << "Avg : " << avg_cluster << endl;
	}
  }
  
  return 0;
}
