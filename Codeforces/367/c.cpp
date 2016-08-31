#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000;
long long dp[2][2];
int v[maxn+5];
int n;
const int maxl = 100000;
char str[2][maxl+5];
const long long inf = 1000000000000000000LL;

bool check(int curr, int otherr, int cur, int other) {
  int curlen = strlen(str[cur]);
  int otherlen = strlen(str[other]);
  int curi = curr == 0 ? 0 : curlen-1;
  int curd = curr == 0 ? 1 : -1;
  int otheri = otherr == 0 ? 0 : otherlen-1;
  int otherd = otherr == 0 ? 1 : -1;
  while(curi >= 0 && curi < curlen && otheri >= 0 && otheri < otherlen) {
    if(str[cur][curi] == str[other][otheri]) {
      curi += curd;
      otheri += otherd;
    } else {
      return str[cur][curi] > str[other][otheri];
    }
  }
  return curlen >= otherlen;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  scanf("\n");
  for(int i = 0; i < n; i++) {
    int cur = i&1;
    int other = cur^1;
    scanf("%s\n", str[cur]);
    if(i == 0) {
      dp[cur][0] = 0;
      dp[cur][1] = v[i];
    } else {
      dp[cur][0] = dp[cur][1] = inf;
      if(check(0, 0, cur, other)) {
	dp[cur][0] = min(dp[cur][0], dp[other][0]);
      }
      if(check(0, 1, cur, other)) {
	dp[cur][0] = min(dp[cur][0], dp[other][1]);
      }
      if(check(1, 1, cur, other)) {
	dp[cur][1] = min(dp[cur][1], dp[other][1] + v[i]);
      }
      if(check(1, 0, cur, other)) {
	dp[cur][1] = min(dp[cur][1], dp[other][0] + v[i]);
      }
      if(dp[cur][0] == inf && dp[cur][1] == inf) {
	printf("-1\n");
	return 0;
      }
    }
  }
  long long ans = min(dp[(n-1)&1][0], dp[(n-1)&1][1]);
  if(ans == inf)
    ans = -1;
  printf("%I64d\n", ans);
  return 0;
}
