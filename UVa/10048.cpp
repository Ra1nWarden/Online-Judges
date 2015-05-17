#include <cstdio>
#include <algorithm>
#define INF 2000000000
#define MAXN 105

using namespace std;

int n, m, q;
int d[MAXN][MAXN];

int main() {
  int kase = 1;
  while(scanf("%d %d %d", &n, &m, &q) != EOF && (n || m || q)) {
    if(kase > 1)
      printf("\n");
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
	d[i][j] = i == j ? 0 : INF;
      }
    }
    for(int i = 0; i < m; i++) {
      int from, to, dist;
      scanf("%d %d %d", &from, &to, &dist);
      d[from][to] = min(d[from][to], dist);
      d[to][from] = min(d[to][from], dist);
    }
    for(int k = 1; k <= n; k++) {
      for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= n; j++) {
	  if(d[i][k] < INF && d[k][j] < INF)
	    d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
	}
      }
    }
    printf("Case #%d\n", kase++);
    for(int i = 0; i < q; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      if(d[a][b] != INF)
	printf("%d\n", d[a][b]);
      else
	printf("no path\n");
    }
  }
  return 0;
}
