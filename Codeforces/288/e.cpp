#include <cstdio>
#include <cstring>
#include <string>
#define MAXN 605

using namespace std;

int n;
int v[MAXN][2];
int dp[MAXN][MAXN];

int f(int x, int y) {
  //printf("calling f(%d, %d)\n", x, y);
  if(dp[x][y] != -1)
    return dp[x][y];
  if(x == y) {
    return dp[x][y] = (v[x][0] == 1 ? 1 : 0);
  }
  if(x > y)
    return dp[x][y] = 0;
  for(int l = v[x][0]; l <= v[x][1]; l++) {
    if(l % 2 == 0)
      continue;
    int mid = (l - 1) / 2;
    if(mid == 0) {
      if(f(x+1, y))
	return dp[x][y] = 1;
    }
    else if(f(x+1, x+mid)) {
      if(x + mid == y)
	return dp[x][y] = 1;
      else
	return dp[x][y] = f(x+mid+1, y);
    }
  }
  return dp[x][y] = 0;
}

string printRes(int x, int y) {
  //printf("printres %d %d\n", x, y);
  if(x == y && dp[x][y])
    return "()";
  if(x > y)
    return "";
  for(int l = v[x][0]; l <= v[x][1]; l++) {
    if(l % 2 == 0)
      continue;
    int mid = (l - 1) / 2;
    if(mid == 0) {
      if(dp[x+1][y])
	return "()" + printRes(x+1, y);
    }
    else if(dp[x+1][x+mid]) {
      if(x+mid == y)
	return "(" + printRes(x+1, x+mid) + ")";
      else if(dp[x+mid+1][y])
	return "(" + printRes(x+1, x+mid) + ")" + printRes(x+mid+1, y);
    }
  }
  return "";
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &v[i][0], &v[i][1]);
  }
  memset(dp, -1, sizeof dp);
  if(f(0, n-1)) {
    //printf("yes\n");
    printf("%s\n", printRes(0, n-1).c_str());
  } else {
    printf("IMPOSSIBLE\n");
  }
  return 0;
}
