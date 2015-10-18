#include <cstdio>
#include <vector>
#define MAXN 505
#define MOD 1000007

using namespace std;

int choose[MAXN][MAXN];

int main() {
  for(int i = 0; i <= 500; i++) {
    for(int j = 0; j <= i; j++) {
      if(i == 0 || j == 0 || j == i) {
	choose[i][j] = 1;
      } else {
	choose[i][j] = (choose[i-1][j] + choose[i-1][j-1]) % MOD;
      }
    }
  }

  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    if(k > m * n) {
      printf("Case %d: 0\n", kase);
      continue;
    }
    int ans = 0;
    for(int mask = 1; mask < (1 << 4); mask++) {
      int r = m, c = n;
      int bit_count = 0;
      if(mask & 1) {
	r--;
	bit_count++;
      }
      if(mask & 2) {
	r--;
	bit_count++;
      }
      if(mask & 4) {
	c--;
	bit_count++;
      }
      if(mask & 8) {
	c--;
	bit_count++;
      }
      if(bit_count % 2) {
	ans = (ans + choose[r * c][k]) % MOD;
      } else {
	ans = (ans + MOD - choose[r * c][k]) % MOD;
      }
    }
    printf("Case %d: %d\n", kase, (choose[m * n][k] + MOD - ans) % MOD);
  }
  return 0;
}
