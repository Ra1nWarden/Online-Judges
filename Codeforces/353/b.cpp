#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n, a, b, c, d;
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  int minval = a + b;
  int maxval = a + b;
  minval = min(minval, a + c);
  maxval = max(maxval, a + c);
  minval = min(minval, b + d);
  maxval = max(maxval, b + d);
  minval = min(minval, c + d);
  maxval = max(maxval, c + d);
  long long ans = n * 1LL * max(n - (maxval - minval + 1) + 1, 0);
  printf("%I64d\n", ans);
  return 0;
}
