#include <cstdio>
#include <map>
#include <string>
#include <cctype>
#include <cstring>
#define MAXL 400000
#define MAXN 50005

using namespace std;

char str[MAXL];
char* itr;
struct Node {
  string op;
  int left, right;
  int hash;
  Node() {}
  bool operator<(const Node& rhs) const {
    if(hash != rhs.hash)
      return hash < rhs.hash;
    if(left != rhs.left) {
      return left < rhs.left;
    }
    return right < rhs.right;
  }
};
Node nodes[MAXN];
int ni;
map<Node, int> m;
int done[MAXN];
int kase;

int build_tree() {
  int idx = ni++;
  nodes[idx].left = nodes[idx].right = nodes[idx].hash = 0;
  nodes[idx].op.clear();
  while(isalpha(*itr)) {
    nodes[idx].op.push_back(*itr);
    nodes[idx].hash = nodes[idx].hash * 27 + (*itr) - 'a' + 1;
    itr++;
  }
  if(*itr == '(') {
    itr++;
    nodes[idx].left = build_tree();
    itr++;
    nodes[idx].right = build_tree();
    itr++;
  }
  if(m.count(nodes[idx]) == 0)
    return m[nodes[idx]] = idx;
  else {
    ni--;
    return m[nodes[idx]];
  }
}

void print_tree(int root) {
  if(done[root] == kase) {
    printf("%d", root);
  } else {
    done[root] = kase;
    if(nodes[root].left == 0 && nodes[root].right == 0) {
      printf("%s", nodes[root].op.c_str());
    } else {
      printf("%s(", nodes[root].op.c_str());
      print_tree(nodes[root].left);
      printf(",");
      print_tree(nodes[root].right);
      printf(")");
    }
  }
}

int main() {
  int tc;
  memset(done, 0, sizeof done);
  scanf("%d\n", &tc);
  kase = 1;
  while(tc--) {
    m.clear();
    ni = 1;
    scanf("%s\n", str);
    int len = strlen(str);
    itr = str;
    build_tree();
    print_tree(1);
    printf("\n");
    kase++;
  }
  return 0;
}
