#include <iostream>
#include <vector>

using namespace std;

// ベクトルを定義する4つの方法
int main(int argv, char* argc[])
{
  vector<char> a;
  vector<char> b(5, 'X');
  vector<char> c(b); //他のベクタで初期化
  int i;

  for(i=0; i<5; i++)
	a.push_back('A' + i);

  vector<char> d(a.begin()+1, a.end());

  for(i=0; i<a.size(); i++)
	cout << "a[" << i << "]: " << a[i] << "  ";
  cout << endl;

  for(i=0; i<b.size(); i++)
	cout << "b[" << i << "]: " << b[i] << "  ";
  cout << endl;

  for(i=0; i<c.size(); i++)
	cout << "c[" << i << "]: " << c[i] << "  ";
  cout << endl;
  
  for(i=0; i<d.size(); i++)
	cout << "d[" << i << "]: " << d[i] << "  ";
  cout << endl;

  return 0;
  
}
