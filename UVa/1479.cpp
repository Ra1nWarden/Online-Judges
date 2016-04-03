#include <cstdio>
#include <cstring>
#include <utility>
#include <stack>
#include <vector>
#include <cstdlib>

using namespace std;

const int maxn = 20000;
const int maxm = 60000;
typedef pair<int, int> Edge;

struct Command {
  char cmd;
  int arg1, arg2;
};

Edge edges[maxm+5];
bool exist[maxm+5];
int values[maxn+5];
int n, m;
vector<Command> commands;

// Treap node
struct Node {
  // 0 -> left 1 -> right
  Node* ch[2];
  // r is random key that follows heap property.
  // v is value that follows BST property.
  // w weight of the node (number of copies of this value).
  // s is the total subtree size.
  int r, v, w, s;
  Node(int v);
  bool operator<(const Node& rhs) const;
  int cmp(int x) const;
  void maintain();
};

// Treap operations
void rotate(Node*& o, int d);
void insert(Node*& o, int x);
void remove(Node*& o, int x);
int kth(Node* o, int k);

// Memory management
void recycle(Node*& x);

Node* nodes[maxn+5];
int fa[maxn+5];

int find_set(int a) {
  //printf("find_set(%d) fa[%d]=%d\n", a, a, fa[a]);
  return a == fa[a] ? a : fa[a] = find_set(fa[a]);
}

void merge(Node*& src, Node*& dest) {
  if(src->ch[0] != NULL) {
    merge(src->ch[0], dest);
  }
  if(src->ch[1] != NULL) {
    merge(src->ch[1], dest);
  }
  insert(dest, src->v);
  delete src;
  src = NULL;
}

void add_edge(int x) {
  int u = find_set(edges[x].first);
  int v = find_set(edges[x].second);
  if(u != v) {
    if(nodes[u]->s < nodes[v]->s) {
      //printf("union %d with %d\n", u, v);
      fa[u] = v;
      merge(nodes[u], nodes[v]);
    } else {
      //printf("union %d with %d\n", v, u);
      fa[v] = u;
      //printf("fa[1]=%d\n", fa[1]);
      merge(nodes[v], nodes[u]);
    }
  }
}

void change(int x, int v) {
  //printf("change(%d)\n", x);
  int u = find_set(x);
  //printf("u = %d\n", u);
  remove(nodes[u], values[x]);
  insert(nodes[u], v);
  values[x] = v;
}

int main() {
  for(int i = 1; i <= maxn; i++)
    nodes[i] = NULL;
  int kase = 1;
  while(scanf("%d%d\n", &n, &m) != EOF && (n || m)) {
    for(int i = 1; i <= n; i++) {
      scanf("%d\n", &values[i]);
    }
    //printf("before edges\n");
    for(int i = 1; i <= m; i++)
      scanf("%d%d\n", &edges[i].first, &edges[i].second);
    commands.clear();
    char cmd;
    memset(exist, true, sizeof exist);
    //printf("before push\n");
    while(scanf("%c", &cmd) != EOF) {
      if(cmd == 'E')
	break;
      else if(cmd == 'Q') {
	int a, b;
	scanf("%d%d\n", &a, &b);
	commands.push_back((Command) {'Q', a, b});
      } else if(cmd == 'D') {
	int a;
	scanf("%d\n", &a);
	commands.push_back((Command) {'D', a, -1});
	exist[a] = false;
      } else if(cmd == 'C') {
	int a, b;
	scanf("%d%d\n", &a, &b);
	int orig = values[a];
	values[a] = b;
	commands.push_back((Command) {'C', a, orig});
      }
    }
    //printf("before init\n");
    for(int i = 1; i <= n; i++) {
      fa[i] = i;
      if(nodes[i] != NULL)
	recycle(nodes[i]);
      //printf("fa[%d]=%d\n", i, fa[i]);
      nodes[i] = new Node(values[i]);
    }
    //printf("here\n");
    for(int i = 1; i <= m; i++) {
      if(exist[i]) {
	add_edge(i);
      }
    }
    int query_cnt = 0;
    long long query_total = 0;
    //printf("before reverse traversal\n");
    for(int i = commands.size() - 1; i >= 0; i--) {
      if(commands[i].cmd == 'Q') {
	query_cnt++;
	query_total += kth(nodes[find_set(commands[i].arg1)], commands[i].arg2);
	//printf("cnt is %d total is %d\n", query_cnt, query_total);
      } else if(commands[i].cmd == 'C') {
	//printf("before change\n");
	change(commands[i].arg1, commands[i].arg2);
      } else if(commands[i].cmd == 'D') {
	//printf("before delete\n");
	add_edge(commands[i].arg1);
      }
    }
    printf("Case %d: %.6lf\n", kase++, query_total / (double) query_cnt);
  }
  return 0;
}

Node::Node(int v) : v(v) {
  ch[0] = ch[1] = NULL;
  r = rand();
  w = 1;
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
  s = w;
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
    //if(x == o->v) {
    //o->w++;
    //} else {
      int d = (x < o->v ? 0 : 1);
      insert(o->ch[d], x);
      if(o->ch[d]->r > o->r)
	rotate(o, d^1);
      //}
  }
  o->maintain();
}

void remove(Node*& o, int x) {
  int d = o->cmp(x);
  if(d == -1) {
    if(o->w == 1) {
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
    } else {
      o->w--;
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
  if(k > s && k <= s + o->w)
    return o->v;
  else if(k <= s) {
    return kth(o->ch[1], k);
  }
  else {
    return kth(o->ch[0], k - s - o->w);
  }
}

void recycle(Node*& x) {
  if(x->ch[0] != NULL)
    recycle(x->ch[0]);
  if(x->ch[1] != NULL)
    recycle(x->ch[1]);
  delete x;
  x = NULL;
}
