#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  string buf;
  string str[5];
  char ch;


  
  // cin は、改行, 空行までを取得する
  while(!cin.eof()){
	cin >> buf;
  }

  // そこで、while(!cin.eof()) で囲むことでファイル全部を読む

  cout << buf.size() << endl;
  
  int j=0;
  for(int i=0; i<buf.size(); i++){
	if(buf[i] == ','){
	  j++;
	  i++;
	}
	str[j].push_back(buf[i]);
  }

  int out;
  for(int k=0; k<=j; k++){
	cout << str[k] << endl;
	out = stoi(str[k]);
  	//cout << out << endl;
  }
  
  return 0;
}
