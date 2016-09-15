#include <cstdio>
#include <algorithm>

using namespace std;

long long l1, r1, l2, r2, k;

int main() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2, &k);
  long long ans = min(r1, r2) - max(l1, l2) + 1;
  ans = max(0LL, ans);
  if(ans > 0 && k >= max(l1, l2) && k <= min(r1, r2)) {
    ans--;
  }
  printf("%I64d\n", ans);
  return 0;
  
}
