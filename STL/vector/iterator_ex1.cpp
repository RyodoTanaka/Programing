#include <iostream>
#include <vector>
using namespace std;

int main(int argv, char* argc[])
{
  vector<int> v(10);
  vector<int>::iterator p;
  int i;

  // ベクタ要素に値を代入
  p = v.begin();
  i = 0;
  while(p != v.end()){
	*p = i; // pを介してvにiを書き込む
	p++;
	i++;
  }

  cout << "Original : " << endl;
  p = v.begin();
  while(p != v.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;

  // ベクタの要素を変更
  p = v.begin();
  while(p != v.end()){
	*p = *p * 2;
	p++;
  }

  cout << "Changed : " << endl;
  p = v.begin();
  while(p != v.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;
  
  return 0;
}
