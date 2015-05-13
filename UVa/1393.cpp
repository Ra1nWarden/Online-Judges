#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXN 305

using namespace std;

int gm[MAXN][MAXN];

int gcd(int a, int b) {
  if(gm[a][b] != -1)
    return gm[a][b];
  return gm[a][b] = gm[b][a] = b == 0 ? a : gcd(b, a%b);
}

int main() {
  memset(gm, -1, sizeof gm);
  int n, m;
  while(scanf("%d %d", &n, &m) != EOF && (n || m)) {
    int ans = 0;
    for(int i = 1; i < n; i++) {
      for(int j = 1; j < m; j++) {
	if(gcd(i, j) == 1) {
	  ans += (n - i) * (m - j) - max(0, n - 2 * i) * max(0, m - 2 * j);
	}
      }
    }
    ans *= 2;
    printf("%d\n", ans);
  }
  return 0;
}
