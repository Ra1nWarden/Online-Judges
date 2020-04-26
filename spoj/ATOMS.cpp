#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    long long n, k, m;
    scanf("%lld %lld %lld", &n, &k, &m);
    int ans = 0;
    long long div = m / n;
    while(div >= k) {
      div /= k;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
