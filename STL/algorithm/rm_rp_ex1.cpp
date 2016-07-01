#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argv, char* argc[])
{
  char str[] = "Algorithms operate on containers through iterators";
  vector<char> v, v2(100);
  vector<char>::iterator p;
  int i;

  for(i=0; str[i]; i++)
	v.push_back(str[i]);

  // ------- remove_copy() --------
  cout << "Input sequence : " << endl;
  for(i=0; i<v.size(); i++)
	cout << v[i];
  cout << endl;

  // すべての空白文字を削除する
  p = remove_copy(v.begin(), v.end(), v2.begin(), ' ');

  cout << "Result remove : " << endl;
  for(i=0; i<p-v2.begin(); i++)
	cout << v2[i];
  cout << endl;

  // -------- replace_copy() --------
  cout << "Input sequence : " << endl;
  for(i=0; i<v.size(); i++)
	cout << v[i];
  cout << endl;

  // 空白文字を+記号に置換する
  p = replace_copy(v.begin(), v.end(), v2.begin(), ' ', '+');

  cout << "Result replace : " << endl;
  for(i=0; i<p-v2.begin(); i++)
	cout << v2[i];
  cout << endl;
  
  return 0;
}
