#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class state{
public :
  state():
	arry(0),
	now(1),
	stay(true),
	time(0),
	customer(0){};
	
  int arry;
  int now;
  bool stay;
  int time;
  int customer;
};

struct request{
  int time;
  int from;
  int to;
};

int main(int argc, char** argv)
{
  vector<request> r;
  vector<request>::iterator r_p;

  // = file 読み込み ==========================================
  ifstream ifs(argv[1], ios::in);
  string buf;  
  getline(ifs, buf);
  r.resize(atoi(buf.c_str()));
  r_p = r.begin();
  while(1){
	if(ifs.eof())
	  break;
	// read by line
	getline(ifs, buf);
	// read by delimiter on reading "one" line
	const char delimiter = ' ';
	string spreat_buf;
	istringstream line_separater(buf);
	for(int i=0; ;i++){
	  if(line_separater.eof())
		break;
	  getline(line_separater, spreat_buf, delimiter);
	  switch(i){
	  case 0 : r_p->time = atoi(spreat_buf.c_str()); break;
	  case 1 : r_p->from = atoi(spreat_buf.c_str()); break;
	  case 2 : r_p->to = atoi(spreat_buf.c_str()); break;
	  default : break;
	  }
	}
	r_p++;
  }
  for(r_p=r.begin(); r_p<r.end(); r_p++)
	cout << r_p->time << ", " << r_p->from << ", " << r_p->to << endl;
  // = file 読み込み ========================================

  vector<int> wait_time(r.size());
  vector<int> on_board_time(r.size());

  int global_time[2] = {0};
  state s;

  for(r_p=r.begin(); r_p<r.end(); r_p++){
	global_time[1] = r_p->time;
	if(r_p->from == s.now){
	  
	} else{
	}
	global_time[0] = global_time[1];
  }
  
  
  
  
  return 0;
}
