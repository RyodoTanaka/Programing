#include <iostream>
#include <map>

using namespace std;

int main(void)
{
  // Create Map data
  map<char, int> m;
  int i;

  // Insert a pair to the map
  for(i=0; i<26; i++)
	m.insert(pair<char, int>('A'+i, 65+i));

  // Get Key
  char ch;
  cout << "Enter key : ";
  cin >> ch;

  // Create iterator
  map<char, int>::iterator p;

  // Find the Value from the Key
  p = m.find(ch);
  if(p != m.end())
	cout << "The Value : " << p->first << " is " << p->second << endl;
  else
	cout << "The key does not found" << endl;

  return 0;
}

