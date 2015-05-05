#include <cstdio>
#include <algorithm>
#define MAXN 4005

using namespace std;

int v[4][MAXN];
int sums[MAXN * MAXN], si;
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 4; j++) {
	scanf("%d", &v[j][i]);
      }
    }
    si = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	sums[si++] = v[0][i] + v[1][j];
      }
    }
    sort(sums, sums + si);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	int negsum = -(v[2][i]) - (v[3][j]);
	ans += upper_bound(sums, sums+si, negsum) - lower_bound(sums, sums+si, negsum);
      }
    }
    printf("%d\n", ans);
    if(tc != 0)
      printf("\n");
  }
  return 0;
}
