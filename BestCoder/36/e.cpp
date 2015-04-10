#include <cstdio>
#include <map>
#define MOD 1000000007

using namespace std;

typedef pair<long long, long long> LL;

map<LL, long long> combi;

long long choose(long long n, long long m) {
  LL key = make_pair(n, m);
  if(combi.count(key))
    return combi[key];
  if(m == 0)
    return combi[key] = 1;
  if(m == 1)
    return combi[key] = n;
  if(m > n / 2)
    return combi[key] = choose(n, n - m);
  if(m > n)
    return combi[key] = 0;
  return combi[key] = (choose(n-1, m) + choose(n - 1, m - 1)) % MOD;
}

long long f(long long b, long long c, long long n) {
  if(n >= b)
    return choose(b+c - 1, c-1);
  if(n < b/c)
    return 0;
  long long ans = 0;
  for(long long k = 0; k <= n; k++) {
    ans += f(b-k, c-1, n);
    ans %= MOD;
  }
  return ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    long long ans = 0;
    for(long long i = 2; i <= n; i++) {
      long long left = n - i;
      if((m - 1) * (i - 1) < left) {
	continue;
      }
      ans += f(left, m - 1, i - 1);
      ans %= MOD;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
