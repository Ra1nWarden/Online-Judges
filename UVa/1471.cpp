#include <cstdio>
#include <set>
#include <algorithm>
#define MAXN 200005

using namespace std;

struct Node {
  int num, l;
  Node() {}
  bool operator<(const Node& rhs) const {
    return num < rhs.num;
  }
};

Node nodes[MAXN];
set<Node> queue;
int n;
int f[MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &nodes[i].num);
      if(i == 0)
	nodes[i].l = 1;
      else
	nodes[i].l = nodes[i].num > nodes[i-1].num ? nodes[i-1].l + 1 : 1;
    }
    for(int i = n - 1; i > -1; i--) {
      if(i == n - 1)
	f[i] = 1;
      else {
	if(nodes[i].num < nodes[i+1].num)
	  f[i] = f[i+1] + 1;
	else
	  f[i] = 1;
      }
    }
    int ans = 1;
    queue.clear();
    queue.insert(nodes[0]);
    for(int i = 1; i < n; i++) {
      set<Node>::iterator itr = queue.lower_bound(nodes[i]);
      if(itr == queue.begin()) {
	ans = max(ans, f[i]);
	queue.insert(nodes[i]);
	continue;
      }
      itr--;
      ans = max(ans, itr->l + f[i]);
      if(itr->l >= nodes[i].l)
	continue;
      if(queue.count(nodes[i])) {
	itr = queue.find(nodes[i]);
	if(itr->l > nodes[i].l)
	  continue;
      }
      queue.erase(nodes[i]);
      queue.insert(nodes[i]);
      itr = queue.find(nodes[i]);
      itr++;
      while(itr != queue.end()) {
	if(itr->num > nodes[i].num && itr->l <= nodes[i].l) {
	  queue.erase(itr++);
	} else {
	  break;
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
