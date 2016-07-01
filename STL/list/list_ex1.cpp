#include <iostream>
#include <list>

using namespace std;

int main(int argv, char* argc[])
{
  list<int> lst;
  list<int>::iterator p;
  int i;

  for(i=0; i<10; i++)
	lst.push_back(i);

  cout << "Size = " << lst.size() << endl;

  cout << "Contents : " << endl;
  p = lst.begin();
  while(p != lst.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;

  // listの要素を変更する
  p = lst.begin();
  while(p != lst.end()){
	*p = *p + 100;
	p++;
  }

  cout << "Modified : " << endl;
  p = lst.begin();
  while(p != lst.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;
  
  return 0;
}
