#include <cstdio>
#include <cstring>
#define MAXN 17
#define MAXM ((1 << MAXN) - 1)

using namespace std;

int n;
char v[MAXN][MAXN];
long long dp[MAXM];

long long f(int mask) {
  if(dp[mask] != -1)
    return dp[mask];
  if(mask == 0)
    return dp[mask] = 1;
  int guns = 0;
  for(int i = 0; i < n; i++) {
    if(v[0][i] == '1')
      guns |= (1 << i);
  }
  for(int i = 0; i < n; i++) {
    if((mask & (1 << i)) == 0) {
      for(int j = 0; j < n; j++) {
	if(v[i+1][j] == '1')
	  guns |= (1 << j);
      }
    }
  }
  long long res = 0;
  for(int i = 0; i < n; i++) {
    if((guns & (1 << i)) != 0) {
      if((mask & (1 << i)) != 0) {
	int newmask = mask ^ (1 << i);
	res += f(newmask);
      }
    }
  }
  return dp[mask] = res;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int et = 1; et <= tc; et++) {
    scanf("%d\n", &n);
    for(int i =0; i <= n; i++)
      scanf("%s\n", v[i]);
    int bitmask = (1 << n) - 1;
    memset(dp, -1, sizeof dp);
    printf("Case %d: %lld\n", et, f(bitmask));
  }
  return 0;
}
