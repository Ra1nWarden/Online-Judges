#include <cstdio>
#include <cstdlib>

using namespace std;

// Treap node
struct Node {
  // 0 -> left 1 -> right
  Node* ch[2];
  // r is random key that follows heap property.
  // v is value that follows BST property.
  // s is the total subtree size.
  int r, v, s;
  Node(int v);
  bool operator<(const Node& rhs) const;
  int cmp(int x) const;
  void maintain();
};

// Treap operations
void rotate(Node*& o, int d);
void insert(Node*& o, int x);
// Call find(o, x) before calling remove.
void remove(Node*& o, int x);
bool find(Node* o, int x);
int kth(Node* o, int k);
// Duplicates are allowed and the rank is calcualted as the worst one.
// For example, 5, 4, 4, 3, 2, 1. Rank of 4 is 2.
// To make rank of 4 become 3, change the insert judging condition to < instead of <=.
int rank(Node* o, int x);

// Memory management
void recycle(Node*& x);

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    Node* root = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
      insert(root, i);
    for(int i = 0; i < n; i++) {
      if(i)
	printf(" ");
      int r;
      scanf("%d", &r);
      int num = kth(root, n-i-r);
      printf("%d", num);
      remove(root, num);
    }
    printf("\n");
  }

  return 0;
}

Node::Node(int v) : v(v) {
  ch[0] = ch[1] = NULL;
  r = rand();
  s = 1;
}

bool Node::operator<(const Node& rhs) const {
  return r < rhs.r;
}

int Node::cmp(int x) const {
  if(x == v)
    return -1;
  return x < v ? 0 : 1;
}

void Node::maintain() {
  s = 1;
  if(ch[0] != NULL)
    s += ch[0]->s;
  if(ch[1] != NULL)
    s += ch[1]->s;
}

void rotate(Node*& o, int d) {
  Node* k = o->ch[d^1];
  o->ch[d^1] = k->ch[d];
  k->ch[d] = o;
  o->maintain();
  k->maintain();
  o = k;
}

void insert(Node*& o, int x) {
  if(o == NULL)
    o = new Node(x);
  else {
    int d = (x <= o->v ? 0 : 1); // Switch this to < for another rank() for duplicates.
    insert(o->ch[d], x);
    if(o->ch[d]->r > o->r)
      rotate(o, d^1);
  }
  o->maintain();
}

void remove(Node*& o, int x) {
  int d = o->cmp(x);
  if(d == -1) {
    Node* u = o;
    if(o->ch[0] != NULL && o->ch[1] != NULL) {
      int d2 = (o->ch[0]-> r > o->ch[1]->r ? 1 : 0);
      rotate(o, d2);
      remove(o->ch[d2], x);
    } else {
      if(o->ch[0] == NULL)
	o = o->ch[1];
      else
	o = o->ch[0];
      delete u;
    }
  } else
    remove(o->ch[d], x);
  if(o != NULL)
    o->maintain();
}

int kth(Node* o, int k) {
  if(o == NULL || k <= 0 || k > o->s)
    return 0; // An error occurred.
  int s = (o->ch[1] == NULL ? 0 : o->ch[1]->s);
  if(k == s + 1)
    return o->v;
  else if(k <= s) {
    return kth(o->ch[1], k);
  }
  else {
    return kth(o->ch[0], k - s - 1);
  }
}

int rank(Node* o, int x) {
  if(o == NULL)
    return 0;
  if(o->v == x) {
    return o->ch[1] == NULL ? 1 : o->ch[1]->s + 1;
  } else if(o->v < x) {
    return rank(o->ch[1], x);
  } else {
    int sub = rank(o->ch[0], x);
    if(sub == 0)
      return 0;
    else
      return (o->ch[1] == NULL ? 1 : o->ch[1]->s + 1) + sub;
  }
}

bool find(Node* o, int x) {
  while(o != NULL) {
    int d = o->cmp(x);
    if(d == -1)
      return true;
    o = o->ch[d];
  }
  return false;
}

void recycle(Node*& x) {
  if(x->ch[0] != NULL)
    recycle(x->ch[0]);
  if(x->ch[1] != NULL)
    recycle(x->ch[1]);
  delete x;
  x = NULL;
}
