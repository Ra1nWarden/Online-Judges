#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int ans = v[n-1];
  for(int i = n-k-1, idx = n-k; i > -1 && idx < n; i--, idx++) {
    ans = max(ans, v[idx] + v[i]);
  }
  printf("%d\n", ans);
  return 0;
}
