#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
  pair<char, int> val;
  node *lch, *rch;
};

node *insert(node* root, node* small, node* large, pair<char, int> small_val, pair<char, int> large_val)
{
  root  = new node;
  small = new node;
  large = new node;

  root->val.first=0;
  root->val.second = small_val.second + large_val.second;

  root->rch = 
  
}

// For sorting
bool sort_less(const pair<char, int>& left,const pair<char, int>& right){
    return left.second < right.second;
}
bool sort_greater(const pair<char, int>& left,const pair<char, int>& right){
    return left.second > right.second;
}

int main(int argc, char* argv[])
{
  ifstream ifs(argv[1], ios::in);  // ファイルストリーム用
  string data;					   // 文字列バッファ
  unsigned int counter = 0;        // 文字カウンタ

  vector< pair<char, int> > result;				// pair型のvectorコンテナ
												// [<char, int>][<char, int>]...
												// charが文字、intは登場回数
  vector< pair<char, int> >::iterator result_itr; // 上記のイテレータ

  // resultの初期化
  result.push_back(pair<char, int>(10, 0));
  for(size_t i=0; i<95; i++)
	result.push_back(pair<char, int>(' '+i, 0));

  while(1){
	// Get the data
	if(!ifs.eof()){
	  data.push_back('\n');
	} else
	  break;
	getline(ifs, data);
	
	//count
	int char_num;
	for(size_t i=0; i<data.size(); i++){
	  counter++;
	  result_itr = result.begin();
	  if(data[i]=='\n')
	  	char_num=0;
	  else if(' ' <= data[i] && data[i] <= '~')
	  	char_num = data[i] - ' ' + 1;        // 正規化
	  else
		continue;
	  advance(result_itr, char_num);
	  result_itr->second++;                 // 登場回数をインクリメント
	}
  }
  
  // --- Root ---
  node* root = NULL;
  
  // --- Sort ---
  // 降順
  while(result.size()!=1){
  	sort(result.begin(), result.end(), sort_greater);	
  	node small;
  	node large;

  	small.val = result.back();
  	result.pop_back();
  	large.val = result.back();
  	result.pop_back();
  	if(small.val.second == large.val.second){
  	  if(small.val.first!=0 && large.val.second!=0){
  		if(small.val.first > large.val.first){
  		  node tmp = small;
  		  small = large;
  		  large = tmp;
  		}		  
  	  } else{
  		node tmp = small;
  		small = large;
  		large = tmp;
  	  } 
  	}
  	small.rch = small.lch = large.rch = large.lch = NULL;
  	root = insert(small, large);
  	result.push_back(root->val);
  }

  // 結果表示
  cout << "=== greater -> less ===" << endl;
  for(result_itr=result.begin(); result_itr!=result.end(); result_itr++){
  	if(result_itr->first==10)
  	  cout << "NL, " << result_itr->second << endl;
  	else if(result_itr->first==' ')
  	  cout << "SP, " << result_itr->second << endl;
  	else
  	  cout << result_itr->first << ", " << result_itr->second << endl;
  }

  // 全文字数
  cout << "All number of characters is : " << counter << "." << endl;

  
  return 0;
}
