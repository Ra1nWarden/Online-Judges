#include <cstring>
#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>
#define MAXN 105
#define MAXFLIGHTS 5010

using namespace std;

int interests[MAXN];
int dp[MAXN];
int pv[MAXN];
typedef pair<int, int> Flight;
Flight flights[MAXFLIGHTS];
int n, m;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
      scanf("%d", &interests[i]);
    interests[n+1] = 0;
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
      scanf("%d%d", &flights[i].first, &flights[i].second);
    sort(flights, flights + m);
    memset(dp, -1, sizeof dp);
    dp[1] = 0;
    memset(pv, -1, sizeof pv);
    for(int i = 0; i < m; i++) {
      Flight f = flights[i];
      if(dp[f.first] == -1)
	continue;
      if(dp[f.first] + interests[f.second] > dp[f.second]) {
	dp[f.second] = dp[f.first] + interests[f.second];
	pv[f.second] = f.first;
      }
    }

    if(kase > 1)
      printf("\n");
    printf("CASE %d#\n", kase);
    printf("points : %d\n", dp[n+1]);
    int stop = n+1;
    stack<int> route;
    while(stop != -1) {
      route.push(stop);
      stop = pv[stop];
    }
    printf("circuit : ");
    while(!route.empty()) {
      int u = route.top();
      route.pop();
      printf("%d", route.empty() ? 1 : u);
      if(!route.empty())
	printf("->");
    }
    printf("\n");
  }
  return 0;
}
