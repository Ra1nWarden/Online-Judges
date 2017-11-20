#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 1000;
const int maxk = 2000;
const long long inf = 2000000000000000000LL;
int vn[maxn+5];
int vk[maxk+5];
int n, k, p;

long long calc(int a, int b) {
  long long ans = (long long) abs(a - b);
  ans += (long long) abs(b - p);
  return ans;
}

int main() {
  scanf("%d%d%d", &n, &k, &p);
  for(int i = 0; i < n; i++)
    scanf("%d", &vn[i]);
  sort(vn, vn + n);
  for(int i = 0; i < k; i++)
    scanf("%d", &vk[i]);
  sort(vk, vk + k);
  long long ans = inf;
  for(int i = 0; i + n <= k; i++) {
    long long cur = 0;
    for(int j = 0; j < n; j++) {
      cur = max(cur, calc(vn[j], vk[i+j]));
    }
    ans = min(ans, cur);
  }
  printf("%I64d\n", ans);
  return 0;
}
