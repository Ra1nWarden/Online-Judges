#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  long long n, a, b, c;
  scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
  long long ans = 0;
  if(n % 4 == 1) {
    ans = min(3 * a, a + b);
    ans = min(ans, c);
  } else if(n % 4 == 2) {
    ans = min(2 * a, b);
    ans = min(ans, 2 * c);
  } else if(n % 4 == 3) {
    ans = min(a, b + c);
    ans = min(ans, 3 * c);
  }
  printf("%I64d\n", ans);
  return 0;
}
