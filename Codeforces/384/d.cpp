#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int dfs_white = 0;
const int dfs_grey = 1;
const int dfs_black = 2;
const int maxn = 200000;
const long long inf = 2000000000000000LL;
int v[maxn+5];
long long dp[maxn+5];
long long sum[maxn+5];
vector<int> adjList[maxn+5];
int n;
int visited[maxn+5];
long long ans = -inf;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  int uu, vv;
  for(int i = 0; i < n - 1; i++) {
    scanf("%d%d", &uu, &vv);
    adjList[uu].push_back(vv);
    adjList[vv].push_back(uu);
  }
  memset(dp, -1, sizeof dp);
  memset(sum, 0, sizeof sum);
  memset(visited, 0, sizeof visited);
  stack<int> s;
  s.push(1);
  visited[1] = dfs_grey;
  while(!s.empty()) {
    int x = s.top();
    bool done = true;
    long long sub = v[x];
    long long subopt = -inf;
    long long maxa = -inf;
    long long maxb = -inf;
    for(int i = 0; i < adjList[x].size(); i++) {
      int y = adjList[x][i];
      if(visited[y] == dfs_white) {
	done = false;
	s.push(y);
	visited[y] = dfs_grey;
      } else if(visited[y] == dfs_black) {
	sub += sum[y];
	subopt = max(subopt, dp[y]);
	if(dp[y] > maxa) {
	  maxb = maxa;
	  maxa = dp[y];
	} else if(dp[y] > maxb) {
	  maxb = dp[y];
	}
      }
    }
    if(done) {
      sum[x] = sub;
      dp[x] = max(subopt, sub);
      s.pop();
      visited[x] = dfs_black;
      if(maxa != -inf && maxb != -inf)
	ans = max(ans, maxa + maxb);
    }
  }
  if(ans == -inf) {
    printf("Impossible\n");
  } else {
    printf("%I64d\n", ans);
  }
  return 0;
}
