#include <cstdio>
#include <algorithm>
#define MAXN 510

using namespace std;

int vw[MAXN];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &vw[i]);
  }
  double ans = 0.0;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    ans = max(ans, (vw[u] + vw[v]) * 1.0 / w);
  }
  printf("%.15lf\n", ans);
  return 0;
}
