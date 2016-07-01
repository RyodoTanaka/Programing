#include <iostream>
#include <list>
#include <functional>
#include <algorithm>

using namespace std;

int main(int argv, char* argc[]){
  list<double> vals;
  list<double> divisors;
  int i;

  for(i=10; i<100; i+=10)
	vals.push_back((double)i);
  for(i=1; i<10; i++)
	divisors.push_back(3.0);

  cout << "Original : " << endl;
  list<double>::iterator p = vals.begin();
  while(p != vals.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;

  // divides関数オブジェクトを使用する
  // dividesは割り算をする２項関数オブジェクト
  p = transform(vals.begin(), vals.end(),
				divisors.begin(), vals.begin(),
				divides<double>()); // 関数オブジェクトを使用する

  cout << "Transformed : " << endl;
  p = vals.begin();
  while(p != vals.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;

  return 0;
}
