#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  long long b, d, s;
  scanf("%I64d%I64d%I64d", &b, &d, &s);
  long long m = max(b, max(d, s));
  long long ans = 0;
  ans += min(max(0LL, m - b), max(0LL, m - 1 - b));
  ans += min(max(0LL, m - d), max(0LL, m - 1 - d));
  ans += min(max(0LL, m - s), max(0LL, m - 1 - s));
  printf("%I64d\n", ans);
  return 0;
}
