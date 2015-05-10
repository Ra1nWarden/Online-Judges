#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if(k > m - 1 + n - 1) {
    printf("-1\n");
    return 0;
  }
  if(k <= max(n, m) - 1) {
    printf("%lld\n", max(n * 1LL * (m / (k + 1)), m * 1LL * (n / (k + 1))));
  }  else {
    printf("%lld\n", max(n / (k - m + 2), m / (k - n + 2)));
  }
  return 0;
}
