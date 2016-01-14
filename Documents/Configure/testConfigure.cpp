#include <iostream>

#include "Configure.hpp"

using namespace std;

int main(){
  PATH confpath("/Users/nao/workspace/work/conffile.txt");
  DECS::common::Configure conf(confpath);
  conf.parse();
  cout << conf.param(DECS::common::Configure::VARNAME_CFPATH) << endl;
  cout << conf.param("aaa") << endl;
  cout << conf.param("OPTION") << endl;
  cout << conf.param("AUTHOR") << endl;
  cout << conf.param("PATH") << endl;
  cout << conf.param("DIRPATH", 0) << endl;
  cout << conf.param("PARAMETER") << endl;
  cout << conf.param("VERSION") << endl;
  cout << conf.param("TEST") << endl;
  return 0;
}
