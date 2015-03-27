#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005

using namespace std;

int v[MAXN];
int n, k;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    sort(v, v+n);
    long long res = 0;
    for(int i = 1; i < n; i++) {
      int add = v + i - lower_bound(v, v+n, v[i] - k);
      res += add > 0 ? add : 0;
    }
    printf("%I64d\n", res);
  }
  return 0;
}
