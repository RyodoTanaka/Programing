#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 3

class sprouts{
public:
  int liberty;
  vector<int> next;
  vector<int> area;
};


int main(int argc, char* argv[])
{ 
  // init
  vector<sprouts> data(N);
  vector<sprouts>::iterator p;

  for(int i=0; i<N; i++){
	data[i].liberty = 3;
	data[i].area.push_back(1);
  }

  // ------ add point ------
  // new point
  data.resize(data.size()+1);
  p = data.end();
  p->next.push_back(0);
  p->next.push_back(1);
  sort(p->next.begin(), p->next.end());
  p->liberty = 1;
  // renew old points
  p = data.begin();
  p->next.push_back(3);
  --p->liberty;
  p++;
  

  
  
  return 0;
}
