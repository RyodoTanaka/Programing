#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define GET_SIZE 0
#define GET_BYTES 1
#define RESET 2

int producer(int what)
{
  static int data = rand() % 20 + 1;

  switch(what){
  case GET_SIZE : return data;
	break;
  case GET_BYTES : return data--;
	break;
  case RESET :
	data = rand() % 20 + 1;
	return data;
	break;
  }

  cerr << "Wrong argument !" << endl;
  return 0;
}

void consumer(vector<int> &v)
{
  int packet_size = producer(GET_SIZE);
  cout << "Producer sending : " << packet_size << " units." << endl;

  v.reserve(packet_size + v.size());
  do{
	v.push_back(producer(GET_BYTES));
	packet_size--;
  } while(packet_size);

  producer(RESET);
}
  
int main(int argv, char* argc[])
{
  char input;
  vector<int> v;

  do{
	consumer(v);
	cout << "Current size : " << v.size() << endl;
	cout << "Current capacity : " << v.capacity() << endl; 
	cout << "Current contents : ";
	for(int i=0; i<v.size(); i++){
	  cout << v[i] << " ";
	  if(!((i+1)%16)) cout << endl;
	}
	cout << endl;
	cout << "More ? (y/n) ";
	cin >> input;
  } while(input == 'y');
 
  return 0;
}
