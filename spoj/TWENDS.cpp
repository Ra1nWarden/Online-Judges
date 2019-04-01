#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int v[maxn+5];
int n;
int dp[maxn+5][maxn+5];
bool vis[maxn+5][maxn+5];

int f(int a, int b, bool first) {
  if(vis[a][b])
    return dp[a][b];
  vis[a][b] = true;
  if(first) {
    if(a==b) {
      return dp[a][b] = v[a];
    } else {
      return dp[a][b] = max(v[a] + f(a+1, b, !first), v[b] + f(a, b-1, !first));
    }
  } else {
    if(a==b) {
      return dp[a][b] = -v[a];
    } else {
      if(v[a] >= v[b]) {
	return dp[a][b] = f(a+1, b, !first) - v[a];
      } else {
	return dp[a][b] = f(a, b-1, !first) - v[b];
      }
    }
  }
}

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF) {
    memset(vis, false, sizeof vis);
    if(!n)
      break;
    for(int i = 0; i < n;i++) {
      scanf("%d", &v[i]);
    }
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n", kase++, f(0, n-1, true));
  }
  return 0;
}
