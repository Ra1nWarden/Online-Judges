#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1505

using namespace std;

int n;
int adjMat[MAXN][MAXN];
int dp[MAXN][2];

int f(int r, int s) {
  if(dp[r][s] != -1)
    return dp[r][s];
  int res = s;
  for(int i = 0; i < n; i++) {
    if(adjMat[r][i]) {
      if(s == 0)
	res += f(i, 1);
      else
	res += min(f(i, 0), f(i, 1));
    }
  }
  return dp[r][s] = res;
}

int main() {
  while(scanf("%d", &n) != EOF) {
    int mr;
    memset(adjMat, false, sizeof adjMat);
    for(int i = 0; i < n; i++) {
      int root, branch;
      scanf("%d:(%d)", &root, &branch);
      for(int j = 0; j < branch; j++) {
	int child;
	scanf("%d", &child);
	adjMat[root][child] = true;
      }
      if(i == 0)
	mr = root;
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", min(f(mr, 0), f(mr, 1)));
  }
  return 0;
}
