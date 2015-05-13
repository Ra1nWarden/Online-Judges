#include <cstdio>

using namespace std;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    int n, k;
    scanf("%d %d", &n, &k);
    long long denom = (1LL << k);
    long long num = denom - (k+1);
    long long d = gcd(num, denom);
    printf("Case #%d: %lld/%lld\n", kase, num / d, denom / d);
  }
  return 0;
}
