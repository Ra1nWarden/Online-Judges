#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#define MAXL 1005
#define INF 2e9

using namespace std;

char str[MAXL];
int dp[MAXL][26];
int k, n;
set<char> cs[MAXL];

int f(int l, int c) {
  if(dp[l][c] != -1)
    return dp[l][c];
  if(cs[l-1].count(c + 'a') == 0)
    return dp[l][c] = 0;
  if(l == 1) {
    return dp[l][c] = cs[l-1].size();
  }
  int res = INF;
  for(int i = 0; i < 26; i++) {
    int subres = f(l-1, i);
    if(subres != 0) {
      if(cs[l-1].count(i + 'a') && (i != c || cs[l-1].size() == 1)) {
	//printf("subtracing 1\n");
	res = min(res, subres + (int)cs[l-1].size() - 1);
      } else {
	//printf("not subtracing 1\n");
	res = min(res, subres + (int)cs[l-1].size());
      }
    }
  }
  return dp[l][c] = res;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %s", &k, str);
    memset(dp, -1, sizeof dp);
    n = strlen(str) / k;
    for(int i = 0; i < n; i++) {
      cs[i].clear();
      for(int j = 0; j < k; j++) {
	cs[i].insert(str[i * k + j]);
      }
    }
    int res = INF;
    for(int i = 0; i < 26; i++) {
      int subres = f(n, i);
      if(subres != 0)
	res = min(res, subres);
    }
    printf("%d\n", res);
  }
  return 0;
}
