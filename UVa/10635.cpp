#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 250*250+5
#define INF 1e9

using namespace std;

int pos[MAXN];
int v[MAXN];
int g[MAXN];
int vi;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int i = 0; i < tc; i++) {
    int n, p, q;
    scanf("%d %d %d", &n, &p, &q);
    memset(pos, -1, sizeof pos);
    for(int j = 1; j <= p+1; j++) {
      int k;
      scanf("%d", &k);
      pos[k] = j;
    }
    vi = 0;
    for(int j = 1; j <= q+1; j++) {
      scanf("%d", &v[vi]);
      if(pos[v[vi]] != -1) {
	v[vi] = pos[v[vi]];
	vi++;
      }
    }

    for(int j = 1; j <= vi; j++)
      g[j] = INF;
    int res = 0;
    for(int j = 0; j < vi; j++) {
      int k = lower_bound(g+1, g+1+vi, v[j]) - g;
      g[k] = v[j];
      res = max(res, k);
    }
    printf("Case %d: %d\n", i+1, res);
  }
  return 0;
}
