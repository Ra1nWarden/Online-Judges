#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 20000;
int n, k;
int v[maxn+5];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    sort(v, v+n);
    int ans = v[n-1] - v[0];
    for(int i = 0; i <= n - k; i++)
      ans = min(ans, v[i+k-1] - v[i]);
    printf("%d\n", ans);
  }
  return 0;
}
