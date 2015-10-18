#include <cstdio>

using namespace std;

const int mod = 1e9 + 7;

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 1;
  for(int i = 0; i < 3 * n; i++) {
    ans *= 3;
    ans %= mod;
  }
  long long sub = 1;
  for(int i = 0; i < n; i++) {
    sub *= 7;
    sub %= mod;
  }
  ans -= sub;
  if(ans < 0) {
    ans += mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
