#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 30
#define INF (1LL << 60)

using namespace std;

long long v[MAXN][MAXN][MAXN];
int a, b, c;

void getDir(int dir, int& dx, int& dy, int& dz) {
  dx = dir & 1;
  dir >>= 1;
  dy = dir & 1;
  dir >>= 1;
  dz = dir & 1;
}

int sgn(int dx, int dy, int dz) {
  return (dx + dy + dz) % 2 == 1 ? 1 : -1;
}

long long sum(int i1, int i2, int j1, int j2, int k1, int k2) {
  int di = i2 - i1 + 1;
  int dj = j2 - j1 + 1;
  int dk = k2 - k1 + 1;
  long long res = 0;
  for(int i = 0; i < 8; i++) {
    int x, y, z;
    getDir(i, x, y, z);
    res -= v[i2 - x * di][j2 - y * dj][k2 - z * dk] * sgn(x, y, z);
  }
  return res;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d%d", &a, &b, &c);
    memset(v, 0, sizeof v);
    for(int i = 1; i <= a; i++) {
      for(int j = 1; j <= b; j++) {
	for(int k = 1; k <= c; k++) {
	  scanf("%lld", &v[i][j][k]);
	}
      }
    }
    for(int i = 1; i <= a; i++) {
      for(int j = 1; j <= b; j++) {
	for(int k = 1; k <= c; k++) {
	  for(int dir = 1; dir < 8; dir++) {
	    int di, dj, dk;
	    getDir(dir, di, dj, dk);
	    v[i][j][k] += v[i-di][j-dj][k-dk] * sgn(di, dj, dk);
	  }
	}
      }
    }
    long long ans = -INF;
    for(int i1 = 1; i1 <= a; i1++) {
      for(int i2 = i1; i2 <= a; i2++) {
	for(int j1 = 1; j1 <= b; j1++) {
	  for(int j2 = j1; j2 <= b; j2++) {
	    long long min_val = 0;
	    for(int k = 1; k <= c; k++) {
	      long long s = sum(i1, i2, j1, j2, 1, k);
	      ans = max(ans, s - min_val);
	      min_val = min(min_val, s);
	    }
	  }
	}
      }
    }
    printf("%lld\n", ans);
    if(tc)
      printf("\n");
  }
  return 0;
}
