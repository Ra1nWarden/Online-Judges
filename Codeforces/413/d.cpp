#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 100000;
long long a, b, h, w, n;
priority_queue<long long> pq;
long long dp[maxn+5];

bool check(long long aa, long long bb) {
  return max(aa, bb) >= a && min(aa, bb) >= b;
}

int main() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &a, &b, &h, &w, &n);
  while(n--) {
    long long x;
    scanf("%I64d", &x);
    pq.push(x);
  }
  if(a < b)
    swap(a, b);
  if(h < w)
    swap(h, w);
  memset(dp, -1, sizeof dp);
  dp[w] = h;
  int ans = 0;
  while(!pq.empty()) {
    long long u = pq.top();
    pq.pop();
    for(int i = maxn; i >= 0; i--) {
      if(dp[i] == -1LL)
	continue;
      if(check(i, dp[i])) {
	printf("%d\n", ans);
	return 0;
      }
      if(i < max(a, b))
	dp[min(u * i, (long long) maxn)] = max(dp[min(u * i, (long long) maxn)], dp[i]);
      dp[i] = min(dp[i] * u, (long long) maxn);
    }
    ans++;
  }

  for(int i = maxn; i >= 0; i--) {
    if(dp[i] == -1LL)
      continue;
    if(check(i, dp[i])) {
      printf("%d\n", ans);
      return 0;
    }
  }
  printf("-1\n");
}
