#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 110
#define MAXM 10010
#define INF 2000000000

using namespace std;

typedef pair<int, int> II;

int n, m, k;
int v[MAXN][MAXM];
int t[MAXN][MAXM];
int dp[MAXN][MAXM];
II arr[MAXM];
int head, tail;

int main() {
  while(scanf("%d %d %d", &n, &m, &k) != EOF && (n || m || k)) {
    memset(v, 0, sizeof v);
    memset(t, 0, sizeof t);
    for(int i = 1; i <= n + 1; i++) {
      for(int j = 1; j <= m; j++) {
	scanf("%d", &v[i][j]);
	v[i][j] += v[i][j-1];
      }
    }
    for(int i = 1; i <= n + 1; i++) {
      for(int j = 1; j <= m; j++) {
	scanf("%d", &t[i][j]);
	t[i][j] += t[i][j-1];
      }
    }
    memset(dp, 0, sizeof dp);
    int ans = -INF;
    for(int i = n+1; i >= 0; i--) {  
      // backward monotonic queue
      head = tail = 0;
      int insertindex = 0;

      for(int j = 0; j <= m; j++) {
	while(insertindex <= m && t[i][insertindex] - t[i][j] <= k) {
	  int insertVal = v[i][insertindex] + (i == n+1 ? 0 : dp[i+1][insertindex]);
	  while(head < tail && arr[tail - 1].first < insertVal)
	    tail--;
	  arr[tail] = make_pair(insertVal, insertindex);
	  tail++;
	  insertindex++;
	}
	while(head < tail && arr[head].second < j)
	  head++;
	dp[i][j] = max(dp[i][j], arr[head].first - v[i][j]);
      }

      // forward monotonic queue
      head = tail = 0;
      insertindex = m;

      for(int j = m; j >= 0; j--) {
	while(insertindex > -1 && t[i][j] - t[i][insertindex] <= k) {
	  int insertVal = v[i][m] - v[i][insertindex] + (i == n+1 ? 0 : dp[i+1][insertindex]);
	  while(head < tail && arr[tail - 1].first < insertVal)
	    tail--;
	  arr[tail] = make_pair(insertVal, insertindex);
	  tail++;
	  insertindex--;
	}
	while(head < tail && arr[head].second > j)
	  head++;
	dp[i][j] = max(dp[i][j], arr[head].first - v[i][m] + v[i][j]);
	if(i == 0)
	  ans = max(ans, dp[i][j]);
      }



      // for(int j = 0; j <= m; j++) {
      // 	for(int k = j; k <= m; k++) {
      // 	  if(t[i][k] - t[i][j] > time)
      // 	    break;
      // 	  dp[i][j] = max(dp[i][j], v[i][k] - v[i][j] + (i == 0 ? 0 : dp[i-1][k]));
      // 	  dp[i][k] = max(dp[i][k], v[i][k] - v[i][j] + (i == 0 ? 0 : dp[i-1][k]));
      // 	}	
      // 	if(i == n + 1) {
      // 	  ans = max(ans, dp[i][j]);
      // 	}
      // }
    }
    printf("%d\n", ans);
  } 
  return 0;
}
