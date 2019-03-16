#include <cstdio>

using namespace std;

const int mod = 10000007;

int pow(int a, int b) {
  if(b == 0)
    return 1;
  int sub = pow(a, b / 2);
  int ans = (sub * 1LL * sub) % mod;
  if(b & 1)
    ans = (ans * 1LL * a) % mod;
  return ans;
}

int main() {
  int n, k;
  while(scanf("%d%d", &n, &k)) {
    if(n == 0 && k == 0) {
      break;
    }
    int ans = (pow(n-1, k) + pow(n-1, k)) % mod;
    ans = (ans + pow(n, k)) % mod;
    ans = (ans + (pow(n-1,n-1) * 2LL) % mod) % mod;
    ans = (ans + pow(n, n)) % mod;
    printf("%d\n", ans);
  }
  return 0;
}
