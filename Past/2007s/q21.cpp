#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

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

  vector<pair<char, int>> result;				// pair型のvectorコンテナ
												// [<char, int>][<char, int>]...
												// charが文字、intは登場回数
  vector<pair<char, int>>::iterator result_itr; // 上記のイテレータ

  // resultの初期化 
  for(size_t i=0; i<26; i++)
	result.push_back(pair<char, int>('a'+i, 0));
  
  while(1){
	// Get the data
	if(!ifs.eof()){
	  data.push_back('\n');
	} else
	  break;
	getline(ifs, data);

	// count
	for(size_t i=0; i<data.size(); i++){
	  int char_num;
	  if('a' <= data[i] && data[i] <= 'z'){
		char_num = data[i] - 'a';             // 0~25に正規化
		result_itr = result.begin()+char_num; // イテレータを設定
		result_itr->second++;                 // 登場回数をインクリメント
	  }
	  else if('A' <= data[i] && data[i] <= 'Z'){
		char_num = data[i] - 'A';
		result_itr = result.begin()+char_num;
		result_itr->second++;
	  }
	  counter++;
	}
  }

  // --- Sort ---
  // 昇順
  sort(result.begin(), result.end(), sort_less);  
  // 結果表示
  cout << "=== less -> greater ===" << endl;
  for(result_itr=result.begin(); result_itr!=result.end(); result_itr++)
	cout << result_itr->first << ", " << result_itr->second << endl;

  // 降順
  sort(result.begin(), result.end(), sort_greater);  
  // 結果表示
  cout << "=== greater -> less ===" << endl;
  for(result_itr=result.begin(); result_itr!=result.end(); result_itr++)
	cout << result_itr->first << ", " << result_itr->second << endl;

  // 全文字数
  cout << "All number of characters is : " << counter << "." << endl;
  
  return 0;
}
