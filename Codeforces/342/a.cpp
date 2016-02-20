#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  long long n;
  long long a, b, c;
  scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
  long long ans = n / a;
  if(n >= b) {
    long long other = (n - c) / (b - c);
    other += (n - other * (b - c)) / a;
    ans = max(ans, other);
  }
  printf("%I64d\n", ans);
  return 0;
}
