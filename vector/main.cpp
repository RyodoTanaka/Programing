#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
  // vector<int> A(5);
  int A[5] = {3,5,12,2,1};

  // raw
  cout << "raw\t: ";
  for (size_t i=0; i<5; ++i)
	cout << A[i] << " ";
  cout << endl;

  // sort
  sort(A, A+5);
  cout << "sortt: ";
  for (size_t i=0; i<5; ++i)
	cout << A[i] << " ";
  cout << endl;
  
  // reverse
  reverse(A, A+5);
  cout << "reverse\t: ";
  for (size_t i=0; i<5; ++i)
	cout << A[i] << " ";
  cout << endl;

  cout << "permitation\t: ";
  sort(A, A+5);
  do {
	for (size_t i=0; i<5; ++i)
	  cout << A[i] << " ";
	cout << endl;
  } while (next_permutation(A,A+5));
  

  // 木の下が謎
  // for (vector<int>::const_iterator p=0; p!=A.end(); ++p)
  // 	cout << *p << endl;
  return 0;
}
