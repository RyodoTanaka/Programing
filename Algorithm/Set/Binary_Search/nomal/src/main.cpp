#include <iostream>

using namespace std;

struct node {
  int val;
  node *lch, *rch;
};

// insert the number named 'x'.
node *insert(node *p, int x)
{
  if(p == NULL){  // if the node is empty.
    node *q = new node;
    q->val = x;
    q->lch = q->rch = NULL;
    return q;
  }
  else{  // if the node is not empty.
    if(x < p->val) // if the x is smaller than node parent.
      p->lch = insert(p->lch, x);
    else  // if the x is bigger than or equal to node parent.
      p->rch = insert(p->rch, x);
    return p;
  }
}

// find the number named 'x'.
bool find(node *p, int x)
{
  if(p == NULL)   // if the node is empty
    return NULL;
  else if(x == p->val) // if the node is equal to x.
    return true;
  else if(x < p->val)  // if x is smaller than node parent.
    return find(p->lch, x);
  else 
    return find(p->rch, x);  // it x is bigger than node parent.
}

// delete the number named 'x'.
node *remove(node *p, int x)
{
  if(p == NULL)   // if the node is empty.
    return NULL;
  else if(x < p->val)  // if x is smaller than node parent. 
    p->lch = remove(p->lch, x);
  else if(x > p->val)  // if x is bigger than node parent.
    p->rch = remove(p->rch,x);
  
  // found the number.
  else if(p->lch == NULL){ // if node does not have left. (want to bring right child.)
    node *q = p->rch; 
    delete p;
    return q;
  }
  else if(p->lch->rch == NULL){  // if node has left and the left does not have right.
                                 // (want to bring lecht child's left child.)
    node *q = p->lch;
    q->rch = p->rch;
    delete p;
    return q;
  }
  else{
    node *q;
    for(q = p->lch; q->rch->rch != NULL; q = q->rch);
    node *r = q->rch;
    q->rch = r->lch;
    r->lch = p->lch;
    r->rch = p->rch;
    delete p;
    return r;
  }
  return p;
}


int main(int argc, char* argv[])
{
  node *root = NULL;
  int find_num;

  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 6);
  root = insert(root, 8);
  root = insert(root, 5);
  root = insert(root, 3);

  cout << "input find number" << endl;
  cin >> find_num;
  cout << "the result is : " << find(root, find_num) << endl;

  cout << "smallest number is : " << root->val << endl;
  cout << "input delete number : " << endl;
  cin >> find_num;
  root = remove(root, find_num);
  cout << "delete the number. and smallest number is : " << root->val << endl;

  return 0;
}
