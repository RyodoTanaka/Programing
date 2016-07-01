#include <iostream>
#include <list>
#include <functional>
#include <algorithm>

using namespace std;

int main(int argv, char* argc[]){
  list<double> vals;
  int i;

  for(i=1; i<10; i++)
	vals.push_back((double)i);

  cout << "Original : " << endl;
  list<double>::iterator p = vals.begin();
  while(p != vals.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;

  // negate関数オブジェクトを使用する
  // negateは値を反転する単項関数オブジェクト
  p = transform(vals.begin(), vals.end(),
				vals.begin(), negate<double>()); // 関数オブジェクトを使用する

  cout << "Transformed : " << endl;
  p = vals.begin();
  while(p != vals.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;

  return 0;
}
