#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 200000;
const int x = 123;

struct Node {
  Node* ch[2];
  // s is the size of subtree.
  // v is the value saved on the node.
  // flip is a marker which can be other things. (Here refers to reverse action.)
  int s, v, flip;
  unsigned long long h1, h2;
  int cmp(int k) const;
  void maintain();
  void pushdown();
  void reverse();
  Node();
};

unsigned long long power[maxn*2 + 5];

struct SplayTree {
  int n;
  Node nodes[maxn*2+5];
  Node* root;
  // Build tree based on size and optionally an array.
  Node* build(char* arr, int sz);
  // init calls build. Use this method to get a new tree.
  void init(char* arr, int sz);
  Node* newNode(int id);
};

// Splay tree related operations.
void rotate(Node*& o, int d);
void splay(Node*& o, int k);
Node* merge(Node* left, Node* right);
// k in split should be positive (non-zero).
void split(Node* o, int k, Node*& left, Node*& right);
void traverse(Node* o, vector<int>& v);

char str[maxn+5];
SplayTree tree;
int n, m;

void debug_node(Node* node) {
  vector<int> v;
  traverse(node, v);
  printf("hash is %llu reverse is %llu\n", node->h1, node->h2);
  for(int j = 0; j < v.size(); j++) {
    printf("%d ", v[j]);
  }
  printf("\n");
}

void debug() {
  printf("-------------------\n");
  for(int i = 0; i < tree.n; i++) {
    debug_node(&tree.nodes[i]);
  }
  printf("-------------------\n");
}

unsigned long long hash(Node*& root, int start, int len) {
  if(len == root->s) {
    return root->h1;
  }
  if(start == 1) {
    splay(root, len+1);
    return root->ch[0]->h1;
  } else {
    splay(root, start-1);
    if(start + len - 1 == root->s) {
      return root->ch[1]->h1;
    } else {
      splay(root->ch[1], len+1);
      return root->ch[1]->ch[0]->h1;
    }
  }
}

int lcp(Node*& root, int p1, int p2) {
  //printf("begin lcp\n");
  //debug();
  int total = root->s;
  int l = 0, r = min(total - p1 + 1, total - p2 + 1);
  //printf("l=%d r=%d\n", l, r);
  while(l < r) {
    int m = l + ((r - l) >> 1) + 1;
    //printf("lcp before testing %d size is %d\n", m, root->s);
    //debug();
    if(hash(root, p1, m) == hash(root, p2, m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return l;
}

int main() {
  power[0] = 1;
  for(int i = 1; i <= maxn*2; i++)
    power[i] = power[i-1] * x;
  while(~scanf("%d%d\n", &n, &m)) {
    scanf("%s\n", str);
    tree.init(str, n);
    for(int i = 0; i < m; i++) {
      int op;
      scanf("%d", &op);
      //printf("op=%d\n", op);
      //vector<int> v;
      //traverse(tree.root, v);
      //for(int i = 0; i < v.size(); i++)
      //printf("%d ", v[i]);
      //printf("\n");
      //debug();
      if(op == 1) {
	int p, c;
	scanf("%d%d", &p, &c);
	Node* node = tree.newNode(c);
	node->maintain();
	if(p == 0) {
	  tree.root = merge(node, tree.root);
	} else {
	  Node* left, *right;
	  split(tree.root, p, left, right);
	  tree.root = merge(merge(left, node), right);
	}
      } else if(op == 2) {
	int p;
	scanf("%d", &p);
	Node* left, *right;
	split(tree.root, p, left, right);
	if(p == 1) {
	  tree.root = right;
	} else {
	  Node* lleft, *lright;
	  split(left, p-1, lleft, lright);
	  tree.root = merge(lleft, right);
	}
      } else if(op == 3) {
	int p1, p2;
	scanf("%d%d", &p1, &p2);
	if(p1 == 1) {
	  if(p2 - p1 + 1 == tree.root->s) {
	    tree.root->reverse();
	    //tree.root->maintain();
	  } else {
	    splay(tree.root, p2-p1+2);
	    tree.root->ch[0]->reverse();
	    //tree.root->ch[0]->maintain();
	  }
	} else {
	  splay(tree.root, p1-1);
	  if(tree.root->ch[1]->s == p2 - p1 + 1) {
	    tree.root->ch[1]->reverse();
	    //tree.root->ch[1]->maintain();
	  }
	  else {
	    splay(tree.root->ch[1], p2 - p1 + 2);
	    tree.root->ch[1]->ch[0]->reverse();
	    //tree.root->ch[1]->ch[0]->maintain();
	  }
	}
      } else if(op == 4) {
	int p1, p2;
	scanf("%d%d", &p1, &p2);
	printf("%d\n", lcp(tree.root, p1, p2));
      }
    }
  }
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
  if(ch[0] != NULL && ch[1] != NULL) {
    s += ch[0]->s + ch[1]->s;
    h1 = ch[0]->h1 + v * power[ch[0]->s] + ch[1]->h1 * power[ch[0]->s + 1];
    h2 = ch[1]->h2 + v * power[ch[1]->s] + ch[0]->h2 * power[ch[1]->s + 1];
  } else if(ch[0] != NULL) {
    //printf("left not null\n");
    s += ch[0]->s;
    h1 = ch[0]->h1 + v * power[ch[0]->s];
    h2 = ch[0]->h2 * power[1] + v;
  } else if(ch[1] != NULL) {
    //printf("right not null\n");
    s += ch[1]->s;
    h1 = ch[1]->h1 * power[1] + v;
    h2 = ch[1]->h2 + v * power[ch[1]->s];
  } else {
    //printf("both null\n");
    h1 = h2 = v;
  }
 
  //debug_node(this);
  //printf("---maintain\n");
}

void Node::reverse() {
  flip ^= 1;
  swap(ch[0], ch[1]);
  swap(h1, h2);
}

void Node::pushdown() {
  if(flip) {
    flip = 0;
    if(ch[0] != NULL)
      ch[0]->reverse();
    if(ch[1] != NULL)
      ch[1]->reverse();
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

Node* SplayTree::build(char* arr, int sz) {
  if(!sz)
    return NULL;
  Node* left = build(arr, sz / 2);
  Node* o = &nodes[n];
  o->v = (int) arr[n++]; // If the tree is built on an array, set it here.
  o->ch[0] = left;
  o->ch[1] = build(arr, sz - sz / 2 - 1);
  o->flip = o->s = 0;
  o->maintain();
  return o;
}

Node* SplayTree::newNode(int id) {
  Node* ans = &nodes[n++];
  ans->v = id + '0';
  return ans;
}

void SplayTree::init(char* arr, int sz) {
  n = 0;
  root = build(arr, sz);
}

void traverse(Node* o, vector<int>& v) {
  if(o != NULL) {
    o->pushdown();
    traverse(o->ch[0], v);
    v.push_back(o->v);
    traverse(o->ch[1], v);
  }
}
