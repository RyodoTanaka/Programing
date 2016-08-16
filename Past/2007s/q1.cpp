#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
  string key_buf(argv[2]);
  int key = stoi(key_buf.c_str());
  ifstream ifs(argv[1], ios::in);
  string raw_data;
  string trans_data;
  string buf;
  
  while(1){
	// Get the data
	if(!ifs.eof()){
	  buf.push_back('\n');
	  raw_data += buf;
	} else
	  break;
	getline(ifs, buf);

	// transform
	for(size_t i=0; i<buf.size(); i++){
	  char trans_buf;
	  if('a' <= buf[i] && buf[i] <= 'z'){
		trans_buf = (buf[i] - 'a' + key) % 26 + 'a';
		trans_data.push_back(trans_buf);
	  }
	  else if('A' <= buf[i] && buf[i] <= 'Z'){
		trans_buf = (buf[i] - 'A' + key) % 26 + 'A';
		trans_data.push_back(trans_buf);
	  }
	  else{
		trans_buf = buf[i];
		trans_data.push_back(trans_buf);
	  }
	}
	  
  }
  cout << "=== Key : " << key << " ===" << endl;
  
  cout << "---- before ---------------" << endl;
  cout << raw_data.c_str();
  cout << "---------------------------" << endl;

  cout << "---- after ----------------" << endl;
  cout << trans_data.c_str();
  cout << "---------------------------" << endl;
  
  return 0;
}
