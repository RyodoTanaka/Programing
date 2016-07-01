#include <iostream>
#include <vector>
using namespace std;

int main(int argv, char* argc[])
{
  vector<char> v(10);
  vector<char> v2;
  vector<char>::iterator p;
  char str[] = "<Vector>";
  int i;

  for(i=0; i<10; i++)
	v[i] = i + 'a';

  for(i=0; str[i]; i++)
	v2.push_back(str[i]);

  cout << "Original : " << endl;
  for(i=0; i<v.size(); i++)
	cout << v[i] << " ";
  cout << endl;

  p = v.begin();
  p += 2; // ３番目の要素を表す

  // vに10個のXを挿入する
  v.insert(p, 10, 'X');

  cout << "Size (Modified Insert) : " << v.size() << endl;
  cout << "Modified Insert : " << endl;
  for(i=0; i<v.size(); i++)
	cout << v[i] << " ";
  cout << endl;

  // 要素を削除刷る
  p = v.begin();
  p += 2;
  v.erase(p, p+10); // 10個の要素を削除する

  cout << "Size (Modified Erase) : " << v.size() << endl;
  cout << "Modified Erase : " << endl;
  for(i=0; i<v.size(); i++)
	cout << v[i] << " ";
  cout << endl;

  v.insert(p, v2.begin(), v2.end());
  cout << "Size Modified v2 Insert : ";
  cout << v.size() << endl;
  cout << "Modified v2 Insert : " << endl;;
  for(i=0; i<v.size(); i++)
	cout << v[i] << " ";
  cout << endl;
  
  return 0;
}
