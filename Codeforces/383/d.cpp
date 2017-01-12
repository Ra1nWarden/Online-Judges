#include <cstdio>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1000;
int dp[maxn+5][2];
int p[maxn+5];
int wv[maxn+5];
int bv[maxn+5];
int n, m, w;
map<int, vector<int> > groups;

int find_set(int x) {
  return p[x] == x ? x : p[x] = find_set(p[x]);
}

void union_set(int x, int y) {
  p[find_set(x)] = find_set(y);
}

int main() {
  scanf("%d%d%d", &n, &m, &w);
  for(int i = 1; i <= n; i++)
    scanf("%d", &wv[i]);
  for(int i = 1; i <= n; i++)
    scanf("%d", &bv[i]);
  for(int i = 1; i <= n; i++)
    p[i] = i;
  for(int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    union_set(x, y);
  }
  for(int i = 1; i <= n; i++) {
    groups[find_set(i)].push_back(i);
  }
  memset(dp, 0, sizeof dp);
  int ii = 0;
  int ans = 0;
  for(map<int, vector<int> >::iterator itr = groups.begin(); itr != groups.end(); itr++) {
    int ww = 0, bb = 0;
    for(int i = 0; i < itr->second.size(); i++) {
      int j = itr->second[i];
      ww += wv[j];
      bb += bv[j];
      for(int x = 0; x <= w; x++) {
	if(x < wv[j]) {
	  dp[x][ii] = max(dp[x][ii], dp[x][ii^1]);
	  ans = max(ans, dp[x][ii]);
	  continue;
	}
	dp[x][ii] = max(dp[x][ii], max(dp[x][ii^1], dp[x-wv[j]][ii^1] + bv[j]));
	ans = max(dp[x][ii], ans);
      }
    }
    for(int x = ww; x <= w; x++) {
      dp[x][ii] = max(dp[x][ii], max(dp[x][ii^1], dp[x-ww][ii^1] + bb));
      ans = max(dp[x][ii], ans);
    }
    ii ^= 1;
  }
  printf("%d\n", ans);
  return 0;
}
