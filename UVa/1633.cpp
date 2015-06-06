#include <cstdio>
#include <cstring>
#define MAXN 405
#define MAXM 1050
#define MOD 1000000007

using namespace std;
int n, k;
int dp[MAXN][MAXM];
bool palin[MAXM][2];

int f(int l, int mask) {
  if(dp[l][mask] != -1) {
    return dp[l][mask];
  }
  if(l == k)
    return dp[l][mask] = palin[mask][0] ? 0 : 1;
  else {
    if(palin[mask][0])
      return dp[l][mask] = 0;
    else if(!palin[mask][1]) {
      int ans = (f(l-1, mask >> 1) + f(l-1, (mask >> 1) | (1 << (k-1)))) % MOD;
      return dp[l][mask] = ans;
    }
    else {
      if(1 & mask) {
	int ans = f(l-1, mask >> 1);
	return dp[l][mask] = ans;
      } else {
	int ans =  f(l-1, (mask >> 1) | (1 << (k-1)));
	return dp[l][mask] = ans;
      }
    }
  }
}

bool bitat(int i, int j) {
  return (i & (1 << j)) != 0;
}

void init_palin() {
  for(int i = 0; i < (1 << k); i++) {
    bool ok = true;
    for(int j = 0; j < k / 2; j++) {
      if(bitat(i, j) != bitat(i, (k - 1 - j))) {
	ok = false;
	break;
      }
    }
    palin[i][0] = ok;
    ok = true;
    for(int j = 1; j <= (k - 1) / 2; j++) {
      if(bitat(i, j) != bitat(i, (k - j))) {
	ok = false;
	break;
      }
    }
    palin[i][1] = ok;
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &k);
    int ans = 0;
    if(n < k) {
      ans = ((1 << n)) % MOD;
    } else {
      memset(dp, -1, sizeof dp);
      memset(palin, false, sizeof palin);
      init_palin();
      for(int mask = 0; mask < (1 << k); mask++) {
	ans = (ans + f(n, mask)) % MOD;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
