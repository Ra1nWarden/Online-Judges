#include <cstdio>

using namespace std;

typedef long long LL;
const int maxn = 51;
int n, t;
LL pow[maxn];

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int n, t;
  while(scanf("%d%d", &n, &t) != EOF) {
    pow[0] = 1;
    for(int i = 1; i <= n; i++)
      pow[i] = pow[i-1] * t;
    LL a = 0;
    for(int i = 0; i < n; i++)
      a += pow[gcd(i, n)];
    LL b = 0;
    if(n % 2) {
      b = n * 1LL * pow[(n + 1) / 2];
    } else {
      b = (n / 2) * 1LL * (pow[n / 2] + pow[n / 2 + 1]);
    }
    printf("%lld %lld\n", a / n, (a + b) / (2 * n));
  }
  return 0;
}
