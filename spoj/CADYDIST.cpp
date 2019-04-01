#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int cv[maxn+5];
int pv[maxn+5];
int n;

int main() {
  while(scanf("%d", &n) != EOF) {
    if(!n)
      break;
    for(int i = 0; i < n; i++)
      scanf("%d", &cv[i]);
    for(int i = 0; i < n; i++)
      scanf("%d", &pv[i]);
    sort(cv, cv+n);
    sort(pv, pv+n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      ans += cv[i] * 1LL * pv[n-1-i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
