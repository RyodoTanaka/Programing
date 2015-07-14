#include <iostream>

using namespace std;

#define MAX_N 9

float heap[MAX_N];  // heap data
int sz = 0;         // arry size

float push(float data)
{
  // My node number
  int n = sz++;

  while(n > 0){
    // parents node number (number starts from 1. & data num starts from 0.)
    int p = (n - 1) / 2;

    // if heap is collect
    if(heap[p] <= data)
      break;
    else{
      // swap parents and children
      heap[n] = heap[p];
      n = p;
    }
  }

  heap[n] = data;  
}

float pop(){
  // minimum
  float ret = heap[0];

  // last data
  float last_data = heap[--sz];

  int n = 0;
  while(n*2 + 1 < sz){
    int l = n*2+1;
    int r = n*2+2;
    
    // check if left children & right children are collect heap. 
    if(r < sz && heap[l] > heap[r])
      l = r;
    
    // if it is collect heap
    if(heap[l] >= last_data)
      break;
    else{
      heap[n] = heap[l];
      n = l;
    }
  }
  heap[n] = last_data;
  return ret;
}

int main(int argc, char *argv[])
{
  ;
}
