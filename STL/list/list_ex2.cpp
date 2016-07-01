#include <iostream>
#include <list>

using namespace std;

int main(int argv, char* argc[])
{
  list<char> lst1, lst2, lst3;
  list<char>::iterator p;
  int i;

  for(i=0; i<10; i+=2) lst1.push_back(i + 'A');
  for(i=1; i<11; i+=2) lst2.push_back(i + 'A');

  cout << "Contents lst1 : " << endl;
  p = lst1.begin();
  while(p != lst1.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;

  cout << "Contents lst2 : " << endl;
  p = lst2.begin();
  while(p != lst2.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;


  // ２つのリストをマージする
  lst1.merge(lst2);
  if(lst2.empty())
	cerr << "lst2 is Empty" << endl;

  cout << "Modified lst1 : " << endl;
  p = lst1.begin();
  while(p != lst1.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;

  // push_back()を使って他のリストを作る
  char str[] = "-splicing-";
  for(i=0; str[i]; i++) lst3.push_back(str[i]);
  cout << "Contents lst3 : " << endl;
  p = lst3.begin();
  while(p != lst3.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;

  // 2つのリストをスプライスする
  p = lst1.begin();
  while(p != lst1.end()){
	if(*p == 'F') lst1.splice(p, lst3);
	p++;
  }

  cout << "Modified lst1 spriced : " << endl;
  p = lst1.begin();
  while(p != lst1.end()){
	cout << *p << " ";
	p++;
  }
  cout << endl;
  
  
  return 0;
}
