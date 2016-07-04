#include <iostream>
#include <vector>

using namespace std;

int main(int argv, char* argc[])
{
  vector<char> v(10);

  cout << "Initial size : " << v.size() << endl;
  cout << "Initial capacity : " << v.capacity() << endl;

  // 更に10個分の容量を確保
  v.reserve(20);

  cout << "After size : " << v.size() << endl;
  cout << "After capacity : " << v.capacity() << endl;
  
  return 0;
}
