#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n, a, b, k;
const int maxk = 100000;
const int mod = 1000000009;
char str[maxk+5];

int mod_inv(int x) {
  if(x == 1LL)
    return 1LL;
  return mod_inv(mod % x) * 1LL * (mod - mod / x) % mod;
}

int pow_mod(int base, int pow) {
  if(pow == 0)
    return 1;
  int sub = pow_mod(base, pow >> 1);
  int squared = (sub * 1LL * sub) % mod;
  if(pow & 1)
    squared = (squared * 1LL * base) % mod;
  return squared;
}

int mult_mod(int x, int y) {
  return (x * 1LL * y) % mod;
}

int main() {
  scanf("%d%d%d%d\n", &n, &a, &b, &k);
  scanf("%s", str);
  int a_inv = mod_inv(a);
  int sub = 0;
  for(int i = 0; i < k; i++) {
    int each = mult_mod(pow_mod(a, n-i), pow_mod(b, i));
    if(str[i] == '+') {
      sub = (sub + each) % mod;
    } else {
      sub = (sub - each) % mod;
    }
  }
  int pow = pow_mod(mult_mod(b, a_inv), k);
  int denom = pow - 1;
  if(denom != 0) {
    denom = mod_inv(denom);
    int num = pow_mod(pow, (n+1) / k) - 1;
    int ans = mult_mod(mult_mod(sub, num), denom);
    if(ans < 0)
      ans += mod;
    printf("%d\n", ans);
  } else {
    int ans = mult_mod(sub, (n + 1) / k);
    if(ans < 0)
      ans += mod;
    printf("%d\n", ans);
  }
  return 0;
}
