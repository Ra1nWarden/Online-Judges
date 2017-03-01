#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 15;
int wv[maxn+1];
int hv[maxn+1];
int qv[maxn+1];
long long dp[1 << 15][maxn+1];
int n, k;

pair<int, int> find_fit(int mask) {
  int min_w = 0;
  int min_h = 0;
  for(int i = 0; i < n; i++) {
    if(mask & (1 << i)) {
      min_w = max(min_w, wv[i]);
      min_h = max(min_h, hv[i]);
    }
  }
  return make_pair(min_w, min_h);
}

long long find_cost(pair<int, int> env, int mask) {
  long long total = 0;
  for(int i = 0; i < n; i++) {
    if(mask & (1 << i)) {
      total += (env.first * 1LL * env.second - wv[i] * 1LL * hv[i]) * qv[i];
    }
  }
  return total;
}

long long f(int mask, int cnt) {
  if(dp[mask][cnt] != -1) {
    return dp[mask][cnt];
  }
  if(__builtin_popcount(mask) <= cnt) {
    return 0;
  }
  if(cnt == 1) {
    pair<int, int> fit = find_fit(mask);
    return dp[mask][cnt] = find_cost(fit, mask);
  }
  long long ans = -1;
  for(int sub = mask - 1; sub; sub = (sub - 1) & mask) {
    int comple = mask ^ sub;
    long long cur =  f(sub, 1) + f(comple, cnt - 1);
    if(ans == -1 || cur < ans) {
      ans = cur;
    }
  }
  return dp[mask][cnt] = ans;
}

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d%d%d", &wv[i], &hv[i], &qv[i]);
  }
  memset(dp, -1, sizeof dp);
  printf("%lld\n", f((1 << n) - 1, k));
  return 0;
}
