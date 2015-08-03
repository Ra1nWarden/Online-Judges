#include <cstdio>
#include <algorithm>
#define MAXN 200005

using namespace std;

typedef long long LL;

struct Edge {
  int a, b;
  long long w;
  bool operator<(const Edge& rhs) const {
    if(w != rhs.w) {
      return w > rhs.w;
    } else if(a != rhs.a) {
      return a < rhs.a;
    } else {
      return b < rhs.b;
    }
  }
};

LL sum[MAXN];
int cnt[MAXN];
int f[MAXN];
int n;
Edge edges[MAXN];

int findParent(int num) {
  return num == f[num] ? num : f[num] = findParent(f[num]);
}

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n - 1; i++) {
      scanf("%d %d %lld", &edges[i].a, &edges[i].b, &edges[i].w);
    }
    sort(edges, edges+n-1);
    for(int i = 1; i <= n; i++) {
      f[i] = i;
      sum[i] = 0;
      cnt[i] = 1;
    }
    for(int i = 0; i < n - 1; i++) {
      int a = findParent(edges[i].a);
      int b = findParent(edges[i].b);
      long long w = edges[i].w;
      if(sum[a] + w * cnt[b] > sum[b] + w * cnt[a]) {
	f[b] = a;
	sum[a] += w * cnt[b];
	cnt[a] += cnt[b];
      } else {
	f[a] = b;
	sum[b] += w * cnt[a];
	cnt[b] += cnt[a];
      }
    }
    printf("%lld\n", sum[findParent(1)]);
  }
  return 0;
}
