#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 20
#define MAXB ((1<<16) - 1)

using namespace std;

int n;
int wid, len;
int v[MAXN];
int dp[105][MAXB];
int bitsum[MAXB];

int f(int w, int bitmask) {
  //printf("calling %d bits = %d\n", w, bitmask);
  if(dp[w][bitmask] != -1)
    return dp[w][bitmask];
  bool ok = false;
  int totaln = 0;
  for(int i = 0; i < n; i++) {
    if((bitmask & (1 << i)) != 0) {
      totaln++;
    }
  }
  if(totaln == 1) {
    return dp[w][bitmask] = 1;
  }
  int l = bitsum[bitmask] / w;
  for(int subbit = (bitmask - 1) & bitmask; subbit && !ok; subbit = (subbit - 1) & bitmask) {
    int leftbit = bitmask - subbit;
    if(bitsum[subbit] % w == 0) {
      ok = f(min(w, bitsum[subbit] / w), subbit) && f(min(w, bitsum[leftbit] / w), leftbit);
    }
    if(!ok && bitsum[subbit] % l == 0) {
      ok = f(min(l, bitsum[subbit] / l), subbit) && f(min(l, bitsum[leftbit] / l), leftbit);
    }
  }
  return dp[w][bitmask] = ok ? 1 : 0;
}

int main() {
  int tc = 1;
  while(scanf("%d", &n) != EOF && n) {
    int a, b;
    scanf("%d %d", &a, &b);
    wid = min(a, b);
    len = max(a, b);
    for(int i= 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    memset(bitsum, 0, sizeof bitsum);
    for(int i = 1; i < (1 << n); i++) {
      for(int j = 0; j < n; j++) {
	if((i & (1 << j)) != 0)
	  bitsum[i] += v[j];
      }
    }
    if(bitsum[(1<<n) - 1] != wid * len || bitsum[(1 << n) - 1] % wid != 0) {
      printf("Case %d: No\n", tc++);
    } else {
      memset(dp, -1, sizeof dp);
      printf("Case %d: %s\n", tc++, f(wid, (1 << n) - 1) == 1 ? "Yes" : "No");
    }
  }
  return 0;
}
