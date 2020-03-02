#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 998244353;
const int maxn = 5000;
int mem[maxn+5];
int memc[maxn+5][maxn+5];

int fact(int m) {
  if(mem[m] != -1)
    return mem[m];
  if(m == 0)
    return mem[m] = 1;
  return mem[m] = (fact(m-1) * 1LL * m) % mod;
}

int choose(int m, int n) {
  if(memc[m][n] != -1)
    return memc[m][n];
  if(n == 0)
    return memc[m][n] = 1;
  if(n == 1)
    return memc[m][n] = m;
  if(m == n)
    return memc[m][n] = 1;
  return memc[m][n] = (choose(m-1, n-1) + choose(m-1, n)) % mod;
}

int calc(int a, int b) {
  int ans = 0;
  for(int i = 0; i <= min(a, b); i++) {
    ans = (ans + (((choose(a, i) * 1LL * choose(b, i)) % mod) * 1LL * fact(i)) % mod) % mod;
  }
  return ans;
}

int main() {
  memset(mem, -1, sizeof mem);
  memset(memc, -1, sizeof memc);
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int x = calc(a, b);
  int y = calc(b, c);
  int z = calc(a, c);
  printf("%d\n", (((x * 1LL * y) % mod) * 1LL * z) % mod);
  return 0;
}
