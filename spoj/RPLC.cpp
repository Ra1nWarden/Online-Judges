#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int tc, n;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d", &n);
    long long cur = 0LL;
    long long ans = 1LL;
    long long num;
    while(n--) {
      scanf("%lld", &num);
      cur += num;
      ans = max(ans, 1LL - cur);
    }
    printf("Scenario #%d: %lld\n", kase, ans);
  }
  return 0;
}
