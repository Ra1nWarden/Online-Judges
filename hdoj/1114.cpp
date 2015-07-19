#include <cstdio>
#include <algorithm>
#define MAXN 505
#define MAXW 10005
#define INF 2000000000

using namespace std;

int weights[MAXN];
int values[MAXN];
int n;
int w;
int dp[MAXW];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int e, f;
    scanf("%d %d", &e, &f);
    w = f - e;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &values[i], &weights[i]);
    }
    for(int i = 1; i <= w; i++)
      dp[i] = INF;
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
      for(int v = 0; v + weights[i] <= w; v++) {
	if(dp[v] == INF)
	  continue;
	dp[v+weights[i]] = min(dp[v+weights[i]], dp[v] + values[i]);
      }
    }
    if(dp[w] == INF) {
      printf("This is impossible.\n");
    } else {
      printf("The minimum amount of money in the piggy-bank is %d.\n", dp[w]);
    }
  }
  return 0;
}
