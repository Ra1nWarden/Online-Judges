#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 13
#define MAXE 1005
#define INF 2000000000

using namespace std;

int v[MAXN];
int dp[2][MAXE];
int hire, salary, fire;
int max_val;
int n;

int main() {
  while(scanf("%d", &n) != EOF && n) {
    scanf("%d%d%d", &hire, &salary, &fire);
    max_val = -1;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      max_val = max(max_val, v[i]);
    }
    for(int i = v[n]; i <= max_val; i++)
      dp[n&1][i] = i * salary;
    for(int i = n - 1; i >= 1; i--) {
      for(int j = v[i]; j <= max_val; j++) {
	int cost = j * salary;
	int min_transit = INF;
	for(int k = v[i+1]; k <= max_val; k++) {
	  if(k < j) {
	    min_transit = min(min_transit, dp[(i&1)^1][k] + fire * (j - k));
	  } else if(k == j) {
	    min_transit = min(min_transit, dp[(i&1)^1][k]);
	  } else {
	    // k > j
	    min_transit = min(min_transit, dp[(i&1)^1][k] + hire * (k - j));
	  }
	}
	dp[i&1][j] = cost + min_transit;
      }
    }
    int ans = INF;
    for(int j = v[1]; j <= max_val; j++) {
      ans = min(ans, hire * j + dp[1&1][j]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
