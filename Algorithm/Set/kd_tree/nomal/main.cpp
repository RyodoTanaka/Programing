#include <iostream>

using namespace std;

struct point {
  int x;
  int y;
};

struct node {
  point val;
  node *lch, *rch;
  bool x_or_y; // true : x, false : y
};

bool tmp = false;

node *insert(node *p, point data)
{
  if(p == NULL){ // if the node is empty.
	node *q = new node;
	q->val = data;
	q->lch = q->rch = NULL;
	q->x_or_y = tmp;
	tmp = !tmp;
	return q;
  }
  else{ // if the node is not empty
	if(p->x_or_y){ // use x value
	  if(data.x < p->val.x)
		p->lch = insert(p->lch, data);
	  else
		p->rch = insert(p->rch, data);
	  return p;
	} else {
	  if(data.y < p->val.y)
		p->lch = insert(p->lch, data);
	  else
		p->rch = insert(p->rch, data);
	  return p;
	}
  }
}

int main(int argc, char* argv[])
{
  node *root = NULL;
  point tmp;
  
  tmp.x = 2;
  tmp.y = 5;
  root = insert(root, tmp);
  tmp.x = 6;
  tmp.y = 3;
  root = insert(root, tmp);
  tmp.x = 10;
  tmp.y = 3;
  root = insert(root, tmp);
  tmp.x = 8;
  tmp.y = 9;
  root = insert(root, tmp);

  cout << "(" << root->rch->val.x << "," << root->rch->val.y << ")" << endl;
  cout << root->rch->x_or_y << endl;

  return 0;
}
