#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100000;
const int maxb = 17;

struct Node {
  Node *children[2];
  int v;
  Node() {
    v = maxn + 5;
    children[0] = children[1] = NULL;
  }
};

Node* nodes[maxn+5];
vector<int> divs[maxn+5];

void init() {
  for(int i = 1; i <= maxn; i++) {
    for(int j = i; j <= maxn; j+=i) {
      divs[j].push_back(i);
    }
    nodes[i] = new Node();
  }
}

void add(int fac, int num) {
  Node* cur = nodes[fac];
  cur->v = min(cur->v, num);
  for(int i = maxb; i >= 0; i--) {
    if(num & (1 << i)) {
      if(!cur->children[1]) {
	cur->children[1] = new Node();
      }
      cur = cur->children[1];
    } else {
      if(!cur->children[0]) {
	cur->children[0] = new Node();
      }
      cur = cur->children[0];
    }
    cur->v = min(cur->v, num);
  }
}

int query(int x, int k, int s) {
  Node* cur = nodes[k];
  if(cur->v > s - x) {
    return -1;
  }
  int ans = 0;
  for(int i = maxb; i >= 0; i--) {
    if(x & (1 << i)) {
      if(cur->children[0] && cur->children[0]->v <= s - x) {
	cur = cur->children[0];
      } else {
	cur = cur->children[1];
	if(cur == NULL || cur->v > s - x) {
	  return -1;
	}
	ans |= (1 << i);
      }
    } else {
      if(cur->children[1] && cur->children[1]->v <= s - x) {
	cur = cur->children[1];
	ans |= (1 << i);
      } else {
	cur = cur->children[0];
	if(cur == NULL || cur->v > s - x) {
	  return -1;
	}
      }
    }
  }
  return ans;
}

int main() {
  init();
  int q;
  scanf("%d", &q);
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int num;
      scanf("%d", &num);
      for(int i = 0; i < divs[num].size(); i++) {
	int fac = divs[num][i];
	add(fac, num);
      }
    } else {
      int x, k, s;
      scanf("%d %d %d", &x, &k, &s);
      if(x % k) {
	printf("-1\n");
	continue;
      }
      printf("%d\n", query(x, k, s));
    }
  }
  return 0;
}
