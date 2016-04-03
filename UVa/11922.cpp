#include <cstdio>
#include <vector>

using namespace std;

struct Node {
  Node* ch[2];
  // s is the size of subtree.
  // v is the value saved on the node.
  // flip is a marker which can be other things. (Here refers to reverse action.)
  int s, v, flip;
  int cmp(int k) const;
  void maintain();
  void pushdown();
  Node();
};

// Maximum number of nodes in the splay tree.
const int maxn = 100000;

struct SplayTree {
  int n;
  Node nodes[maxn+5];
  Node* root;
  // Build tree based on size and optionally an array.
  Node* build(int sz);
  // init calls build. Use this method to get a new tree.
  void init(int sz);
};

// Splay tree related operations.
void rotate(Node*& o, int d);
void splay(Node*& o, int k);
Node* merge(Node* left, Node* right);
void split(Node* o, int k, Node*& left, Node*& right);
// Traverse the tree in-order.
// If the values saved on nodes are not int, change the return type to vector<T>
void traverse(Node* o, std::vector<int>& ans);

SplayTree tree;

void debug(Node* o) {
  vector<int> v;
  traverse(o, v);
  for(int i = 0; i < v.size(); i++)
    printf("%d\n", v[i]);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  tree.init(n);
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    Node* left = NULL, *right = NULL;
    if(a > 1) {
      split(tree.root, a-1, left, right);
    } else {
      right = tree.root;
    }

    //printf("left is \n");
    //debug(left);
    //printf("right is \n");
    //debug(right);
    Node* rleft = NULL, *rright = NULL;
    split(right, b - a + 1, rleft, rright);
    //printf("rleft is \n");
    //debug(rleft);
    //printf("rright is \n");
    //debug(rright);
    rleft->flip ^= 1;
    if(left != NULL)
      tree.root = merge(merge(left, rright), rleft);
    else if(rright != NULL)
      tree.root = merge(rright, rleft);
    else
      tree.root = rleft;
  }
  vector<int> v;
  traverse(tree.root, v);
  for(int i = 0; i < v.size(); i++)
    printf("%d\n", v[i]);
  return 0;
}

Node::Node() {
  ch[0] = ch[1] = NULL;
  s = 1;
  flip = 0;
}

int Node::cmp(int k) const {
  int d = k - (ch[0] == NULL ? 0 : ch[0]->s);
  if(d == 1)
    return -1;
  return d <= 0 ? 0 : 1;
}

void Node::maintain() {
  s = 1;
  if(ch[0] != NULL)
    s += ch[0]->s;
  if(ch[1] != NULL)
    s += ch[1]->s;
}

void Node::pushdown() {
  if(flip) {
    flip = 0;
    swap(ch[0], ch[1]);
    if(ch[0] != NULL)
      ch[0]->flip = !ch[0]->flip;
    if(ch[1] != NULL)
      ch[1]->flip = !ch[1]->flip;
  }
}

void rotate(Node*& o, int d) {
  Node* k = o->ch[d^1];
  o->ch[d^1] = k->ch[d];
  k->ch[d] = o;
  o->maintain();
  k->maintain();
  o = k;
}

void splay(Node*& o, int k) {
  if(o == NULL)
    return;
  o->pushdown();
  int d = o->cmp(k);
  if(d == 1)
    k -= (o->ch[0] == NULL ? 1 : o->ch[0]->s + 1);
  if(d != -1) {
    Node* p = o->ch[d];
    if(p != NULL) {
      p->pushdown();
      int d2 = p->cmp(k);
      int k2;
      if(p->ch[0] == NULL) {
	k2 = (d2 == 0 ? k : k - 1);
      } else {
	k2 = (d2 == 0 ? k : k - p->ch[0]->s - 1);
      }
      if(d2 != -1) {
	splay(p->ch[d2], k2);
	if(d == d2)
	  rotate(o, d^1);
	else
	  rotate(o->ch[d], d);
      }
      rotate(o, d^1);
    }
  }
}

Node* merge(Node* left, Node* right) {
  splay(left, left->s);
  left->ch[1] = right;
  left->maintain();
  return left;
}

void split(Node* o, int k, Node*& left, Node*& right) {
  splay(o, k);
  left = o;
  right = o->ch[1];
  o->ch[1] = NULL;
  left->maintain();
}

Node* SplayTree::build(int sz) {
  if(!sz)
    return NULL;
  Node* left = build(sz / 2);
  Node* o = &nodes[++n];
  o->v = n; // If the tree is built on an array, set it here.
  o->ch[0] = left;
  o->ch[1] = build(sz - sz / 2 - 1);
  o->flip = o->s = 0;
  o->maintain();
  return o;
}

void SplayTree::init(int sz) {
  n = 0;
  root = build(sz);
}

void traverse(Node* o, vector<int>& ans) {
  if(o != NULL) {
    o->pushdown();
    traverse(o->ch[0], ans);
    ans.push_back(o->v);
    traverse(o->ch[1], ans);
  }
}
