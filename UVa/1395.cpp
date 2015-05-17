#include <algorithm>
#include <cstdio>
#define MAXN 105
#define MAXM 5005
#define INF 2000000000

using namespace std;

int u[MAXM], v[MAXM], w[MAXM];
int idx[MAXM];
int p[MAXN];
int m, n;

int cmp(int i, int j) {
  return w[i] < w[j];
}

int find(int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
  while(scanf("%d %d", &n, &m) != EOF && (n || m)) {
    for(int i = 0; i < m; i++) {
      idx[i] = i;
      scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    sort(idx, idx+m, cmp);
    int ans = INF;
    int l, r;
    for(int i = 0; i < m; i++) {
      l = i;
      for(int j = 1; j <= n; j++)
	p[j] = j;
      int cnt = 0;
      for(r = l; r < m && cnt < n - 1; r++) {
	int x = find(u[idx[r]]);
	int y = find(v[idx[r]]);
	if(x != y) {
	  p[x] = y;
	  cnt++;
	}
      }
      if(cnt == n - 1) {
	ans = min(ans, w[idx[r-1]] - w[idx[l]]);
      }
    }
    if(ans == INF)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
