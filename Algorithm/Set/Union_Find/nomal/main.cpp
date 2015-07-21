#include <iostream>

using namespace std;

#define MAX_N 5000
#define MAX_K 1000

int parent[MAX_N];  // parents
int rank[MAX_N];    // depth of the tree

int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K], Wrong[MAX_K];

// initialize with n
void init(int n)
{
  for(int i=0; i<n; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}

// get the root of the tree
// example
// 1-4-5-6
// if we want to know what is the parent of 6.
// the answer is 1.
// this function get such a parent.
int find(int x){
  if(parent[x] == x)
    return x;
  else
    return parent[x] = find(parent[x]);
}

// make the set includes x, and set includes y together.
void unite(int x, int y)
{
  x = find(x);
  y = find(y);
  if(x==y) return;
  
  if(rank[x] < rank[y]){
    parent[x] = y;
  }
  else{
    parent[y] = x;
    if(rank[x] == rank[y])
      rank[x]++;
  }
}

// check if x and y is in same group
bool same(int x, int y)
{
  return find(x) == find(y);
}


int main(int argc, char* argv[])
{
  int type, x, y;
  int ans=0;

  cout << "Input N" << endl;
  cin >> N;
  cout << "Input K" << endl;
  cin >> K;

  // Initialize Union-Find Tree
  // x, x*N, x+2*N を x-a x-b x-c の要素とする
  init(N*3);

  for(int i=0; i<K; i++){

    // Get Data
    cout << endl << "Question " << i+1 << endl;
    cout << "type ? : ";
    cin >> type;
    cout << "x ? : ";
    cin >> x;
    cout << "y ? : ";
    cin >> y;
    
    // if it is error
    if(x<0 || N<=x || y<0 || N<=y){
      cout << "It is wrong Input..." << endl;
      Wrong[ans] = i+1;
      ans++;
      continue;
    }

    // type 1 that x and y is same type.
    if(type==1){
      if(same(x, y+N) || same(x, y+2*N)){ // if x-a and x-b or x-c is same group. (type 1)(wrong)
	Wrong[ans] = i+1;	
	ans++;
      }
      else{  // make x and y same type.(collect)
	unite(x,y);
	unite(x+N, y+N);
	unite(x+N*2, y+N*2);
      }
    }
    
    // type 2 that x eats y.
    else{
      if(same(x,y) || same(x,y+2*N)){  // if x-a eats x-a or x-c. (type 2)(wrong)
	Wrong[ans] = i+1;
	ans++;
      }
      else{
	unite(x,y+N);
	unite(x+N,y+N*2);
	unite(x+N*2,y);
      }
    }
  }
  
  cout << "The result is : " << ans << endl;
  cout << "Wrong question is :";
  for(int j=0; j<ans; j++)
    cout << " " << Wrong[j] << ",";
  cout << endl;

  return 0;
}
