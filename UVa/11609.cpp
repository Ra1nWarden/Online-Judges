#include <cstdio>

using namespace std;

const int mod = 1e9+7;

int calc(int n) {
  if(n == 0)
    return 1;
  int base = calc(n / 2);
  if(n & 1)
    return (base * 2LL * base) % mod;
  else
    return (base * 1LL * base) % mod;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    int n;
    scanf("%d", &n);
    printf("Case #%d: %d\n", kase, (calc(n-1) * 1LL * n) % mod);
  }
  return 0;
}
