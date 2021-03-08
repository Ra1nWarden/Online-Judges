#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000;
int n, k, gvi;
int v[maxn+5];
int gv[maxn+5];
long long maxp = 2e18;

int main() {
  scanf("%d %d", &n, &k);
  gvi = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if(v[i] > 1) {
      //printf("gv[%d]=%d num is %d\n", gvi, i, v[i]);
      gv[gvi++] = i;
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    long long p = 1LL;
    int j_start = lower_bound(gv, gv+gvi, i) - gv;
    long long sum = 0;

    if(v[i] == 1 && k == 1) {
      ans++;
    }
    
    for(int j = j_start; j < gvi; j++) {
      long long div = maxp / p;
      if(div < v[gv[j]]) {
	break;
      }
      sum += v[gv[j]];
      p *= v[gv[j]];
      if(p % k) {
	continue;
      }
      div = p / k;
      int ii = j == gvi - 1 ? n : gv[j+1];
      if(div - sum >= 0 && div - sum + j - j_start + 1 + i <= ii && div - sum + j - j_start + 1 + i > gv[j]) {
	//printf("i=%d j=%d ii=%d p=%lld div=%lld sum=%lld\n", i, j, ii, p, div, sum);
	ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
