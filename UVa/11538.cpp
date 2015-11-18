#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  long long m, n;
  while(scanf("%lld %lld", &m, &n) && (m || n)) {
    if(n > m)
      swap(n, m);
    long long ans = m * n * (m - 1 + n - 1);
    ans += 2 * n * (n - 1) * (3 * m - n - 1) / 3;
    printf("%lld\n", ans);
  }
  return 0;
}
