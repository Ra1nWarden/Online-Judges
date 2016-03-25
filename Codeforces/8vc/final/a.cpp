#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10;
int prefix[maxn+2][maxn+2];
int r, c, n, k;

int main() {
  scanf("%d%d%d%d", &r, &c, &n, &k);
  memset(prefix, 0, sizeof prefix);
  for(int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    prefix[x][y]++;
  }
  for(int i = 1; i <= r; i++) {
    for(int j = 1; j <= c; j++) {
      prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
    }
  }
  int ans = 0;
  for(int i = 1; i <= r; i++) {
    for(int j = 1; j <= c; j++) {
      for(int ii = i; ii <= r; ii++) {
	for(int jj = j; jj <= c; jj++) {
	  if(prefix[ii][jj] - prefix[ii][j-1] - prefix[i-1][jj] + prefix[i-1][j-1] >= k)
	    ans++;
	}
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
