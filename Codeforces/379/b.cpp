#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int k2, k3, k5, k6;
  scanf("%d%d%d%d", &k2, &k3, &k5, &k6);
  long long ans = 0;
  int three = min(k2, min(k5, k6));
  int two = min(k2 - three, k3);
  ans = max(three, 0) * 1LL * 256 + max(two, 0) * 1LL * 32;
  printf("%I64d\n", ans);
  return 0;
}
