#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2000000000;
const int maxm = 200000;
int x, s, n, m, k;
int bv[maxm+5];
int av[maxm+5];
int cv[maxm+5];
int dv[maxm+5];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d", &x, &s);
  for(int i = 0; i < m; i++) {
    scanf("%d", &av[i]);
  }
  for(int i = 0; i < m; i++) {
    scanf("%d", &bv[i]);
  }
  for(int i = 0; i < k; i++) {
    scanf("%d", &cv[i]);
  }
  for(int i = 0; i < k; i++) {
    scanf("%d", &dv[i]);
  }
  long long ans = n * 1LL * x;
  for(int i = 0; i < m; i++) {
    if(bv[i] > s)
      continue;
    int t = s - bv[i];
    int ci = upper_bound(dv, dv + k, t) - dv;
    ci--;
    int nn = n;
    if(ci >= 0)
      nn = n - cv[ci];
    long long cur = nn * 1LL * av[i];
    if(cur < ans)
      ans = cur;
  }
  int cci = upper_bound(dv, dv + k, s) - dv;
  cci--;
  if(cci >= 0)
    ans = min(ans, (n - cv[cci]) * 1LL * x);
  printf("%I64d\n", ans);
  return 0;
}
