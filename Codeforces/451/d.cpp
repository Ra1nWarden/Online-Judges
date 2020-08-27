#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000;
int v[maxn+5];
int prefix[maxn+5];

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  v[0] = 0;
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  sort(v+1, v+n+1);
  prefix[0] = 0;
  for(int i = 1; i <= n; i++) {
    prefix[i] = prefix[i-1] + 1;
    int prev = v[i] - m;
    int idx = upper_bound(v, v+n+1, prev) - v - 1;
    int start = idx >= 0 ? prefix[idx] : 0;
    if(prefix[i] - start >= k) {
      prefix[i]--;
    }
  }
  printf("%d\n", n - prefix[n]);
  return 0;
}
