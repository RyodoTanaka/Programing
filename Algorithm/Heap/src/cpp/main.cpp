#include <queue>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  priority_queue<int> pque;

  // push datas
  pque.push(3);
  pque.push(5);
  pque.push(1);

  // loop by empty
  while(!pque.empty()){
    // get maximum data and delete that
    cout << pque.top() << endl;  // get max data
    pque.pop();                  // delete max data
  }
  
  return 0;
}
