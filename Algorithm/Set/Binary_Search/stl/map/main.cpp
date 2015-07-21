#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
  map<int, const char*> m;

  // insert
  m.insert(make_pair(1, "ONE"));
  m.insert(make_pair(10, "TEN"));
  m[100] = "HUNDRED";

  // find
  map<int, const char*>::iterator ite;
  ite = m.find(1);
  cout << ite->second << endl;
  
  ite = m.find(2);
  if(ite == m.end())
    cout << "not found" << endl;
  else
    cout << ite->second <<endl;

  // another way but danger, because if it not exists, it will be error without error message.
  cout << m[10] << endl;

  // delete
  m.erase(10);

  // loop all elements
  cout << "number : charactor" << endl;
  for(ite = m.begin(); ite != m.end(); ++ite)
    cout << ite->first << " : " << ite->second << endl;
  
  return 0;
}
