#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
int p[1000], e[1000], n, i = -1;
int index(int x){
  for(int i = 0; i < n; i++)
    if(e[i] == x) return i;
  return -1;
}
Node* makeTree(int l = 0, int r = n - 1){
  //cout << l << " " << r << " " << " " << i << endl;
  i++;
  if(i >= n || l > r) return NULL;
  Node *a = new Node(p[i]);
  if(l == r) return a;
  //if(l == r || i >= n) return a;
  int in = index(p[i]);
  if(l < in) a -> left = makeTree(l, in - 1);
  if(r > in) a -> right = makeTree(in + 1, r);
  return a;
}
int main(){
  BST t = createRandom();
  //BST t;
  //t.insert(5);
  //t.insert(8);
  //t.insert(2);
  //t.insert(4);
  //t.insert(1);
  //t.insert(7);
  //t.insert(9);
  //t.insert(3);
  //t.insert(6);

  t.preOrden();
  cout << endl;
  t.enOrden();
  cout << endl;
  t.postOrden();
  cout << endl;
  n = en.size();
  for(int i = 0; i < n; i++)
    p[i] = pre[i], e[i] = en[i];
  BST ans(makeTree());
  cout << endl << endl;
  ans.preOrden();
  cout << endl;
  ans.enOrden();
  cout << endl;
  ans.postOrden();
  cout << endl;
  return 0;
}
