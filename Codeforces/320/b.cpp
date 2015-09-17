#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 810

using namespace std;

struct Node {
  int idx;
  int stren;
  Node(int idx, int stren) : idx(idx), stren(stren) {}
  bool operator<(const Node& rhs) const {
    return stren < rhs.stren;
  }
};

bool paired[MAXN];
int ans[MAXN];
int candidate[MAXN];
priority_queue<Node> pq[MAXN];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 2; i <= n * 2; i++) {
    for(int j = 1; j < i; j++) {
      int stren;
      scanf("%d", &stren);
      pq[i].push(Node(j, stren));
      pq[j].push(Node(i, stren));
    }
  }
  memset(paired, false, sizeof paired);
  int paired_cnt = 0;
  while(paired_cnt < n * 2) {
    for(int i = 1; i <= n * 2; i++) {
      if(paired[i])
	continue;
      int i_can;
      while(!pq[i].empty()) {
	Node u = pq[i].top();
	if(paired[u.idx]) {
	  pq[i].pop();
	  continue;
	}
	candidate[i] = u.idx;
	break;
      }
    }
    for(int i = 1; i <= n * 2; i++) {
      if(paired[i])
	continue;
      if(candidate[candidate[i]] == i) {
	ans[i] = candidate[i];
	ans[candidate[i]] = i;
	paired_cnt += 2;
	paired[i] = paired[candidate[i]] = true;
      }
    }
  }
  for(int i = 1; i<= n * 2; i++) {
    if(i > 1)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
