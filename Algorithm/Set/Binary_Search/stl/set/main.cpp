#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
  set<int> s;

  // insert 
  s.insert(1);
  s.insert(4);
  s.insert(3);
  s.insert(5);
  s.insert(7);

  // find
  set<int>::iterator ite;

  ite = s.find(1);
  if(ite == s.end())
    cout << "not foud" << endl;
  else 
    cout << "found" << endl;

  ite = s.find(2);
  if(ite == s.end())
    cout << "not foud" << endl;
  else
    cout << "foud" << endl;

  // delete
  s.erase(3);

  // another way to find
  if(s.count(3) != 0)
    cout << "foud" << endl;
  else 
    cout << "not found" << endl;
  
  // loop all elements
  for(ite = s.begin(); ite != s.end(); ++ite)
    cout << *ite << endl;

  return 0;
}
