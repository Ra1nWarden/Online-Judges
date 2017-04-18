#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1 << 10;
int v[2][maxn+5];
int n, k, x;

int main() {
  scanf("%d%d%d", &n, &k, &x);
  int m;
  memset(v, 0, sizeof v);
  for(int i = 0; i < n; i++) {
    scanf("%d", &m);
    v[0][m]++;
  }
  for(int i = 0; i < k; i++) {
    int ii = i & 1;
    int jj = ii ^ 1;
    memcpy(v[jj], v[ii], sizeof v[ii]);
    int cur = 0;
    for(int j = 0; j <= maxn; j++) {
      if(v[ii][j] == 0)
	continue;
      int cnt = v[ii][j];
      if(cur & 1) {
	cnt >>= 1;
      } else {
	cnt = (cnt + 1) >> 1;
      }
      v[jj][j] -= cnt;
      v[jj][j ^ x] += cnt;
      cur += v[ii][j];
    }
  }
  for(int i = maxn; i >= 0; i--) {
    if(v[k & 1][i] > 0) {
      printf("%d ", i);
      break;
    }
  }
  for(int i = 0; i <= maxn; i++) {
    if(v[k & 1][i] > 0) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
