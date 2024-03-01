#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 3e5;
const int mod = 1e9+7;

int v[maxn+5];
int n;
int dp[maxn+5];
int cnt[maxn+5];
int fact[maxn+5];
int inv[maxn+5];

int choose(int i, int j) {
  if(j > i)
    return 0;
  return (((fact[i] * 1LL * inv[i-j]) % mod) * 1LL * inv[j]) % mod;
}

int power(int i, int j) {
  int ret = 1;
  while(j) {
    if(j&1) {
      ret = (ret * 1LL * i) % mod;
    }
    j >>= 1;
    i = (i * 1LL * i) % mod;
  }
  return ret;
}

int main() {
  memset(cnt, 0, sizeof cnt);
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    cnt[v[i]]++;
  }

  fact[0] = 1;
  inv[0] = 1;
  for(int i = 1; i <= maxn; i++) {
    fact[i] = (fact[i-1] * 1LL * i) % mod;
    inv[i] = power(fact[i], mod - 2);
  }

  for(int i = 1; i <= maxn; i++) {
    for(int j = i + i; j <= maxn; j += i) {
      cnt[i] += cnt[j];
    }
  }

  bool ok = false;
  for(int i = 1; i <= 7; i++) {
    for(int j = maxn; j >= 1; j--) {
      dp[j] = choose(cnt[j], i);
      if(dp[j] == 0)
	continue;
      for(int k = j + j; k <= maxn; k += j) {
	dp[j] = ((dp[j] + mod) - dp[k]) % mod;
      }
    }
    if(dp[1] != 0) {
      printf("%d\n", i);
      ok = true;
      break;
    }
  }

  if(!ok)
    printf("-1\n");
  
  return 0;
}
