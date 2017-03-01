#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

struct Node {
  int l, r, i;
  bool operator<(const Node& rhs) const {
    if(l != rhs.l)
      return l < rhs.l;
    return r < rhs.r;
  }
};
typedef pair<int, int> II;

const int maxn = 300000;
Node v[maxn+5];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &v[i].l, &v[i].r);
    v[i].i = i + 1;
  }
  sort(v, v+n);
  int ans = 0;
  priority_queue<int, vector<int>, greater<int> > ppq;
  for(int i = 0; i < n; i++) {
    while(ppq.size() > k - 1) {
      ppq.pop();
    }
    ppq.push(v[i].r);
    if(ppq.size() < k)
      continue;
    int ll = v[i].l;
    int rr = ppq.top();
    if(rr - ll + 1 > ans)
      ans = rr - ll + 1;
  }
  printf("%d\n", ans);
  if(ans == 0) {
    for(int i = 1; i <= k; i++) {
      if(i > 1)
	printf(" ");
      printf("%d", i);
    }
    printf("\n");
    return 0;
  } else {
    priority_queue<II, vector<II>, greater<II> > pq;
    for(int i = 0; i < n; i++) {
      while(pq.size() > k - 1) {
	pq.pop();
      }
      pq.push(make_pair(v[i].r, v[i].i));
      if(pq.size() < k)
	continue;
      int ll = v[i].l;
      int rr = pq.top().first;
      if(rr - ll + 1 == ans) {
	bool start = true;
	while(!pq.empty()) {
	  if(!start)
	    printf(" ");
	  printf("%d", pq.top().second);
	  pq.pop();
	  start = false;
	}
	printf("\n");
	return 0;
      }
    }
  }
}
