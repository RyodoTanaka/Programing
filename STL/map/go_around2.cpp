#include <iostream>
#include <map>

using namespace std;

int main(void)
{
  // create map
  map<char, int> m;
  int i;

  // insert pair datas to the map
  for(i=0; i<26; i++)
	m.insert(pair<char, int>('A'+i, 65+i));

  // map iterator
  map<char, int>::reverse_iterator p;

  // go around in the map
  for(p=m.rbegin(); p!=m.rend(); p++){
	cout << p->first << ", ";
	cout << p->second << endl;
  }
	
  return 0;
}

