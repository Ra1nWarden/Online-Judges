#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10000
#define INF 200000000

using namespace std;

bool check[MAXN+5];
int primes[MAXN];
int pi;
int num;
long long ans;

bool isprime(int n) {
  for(int i = 0; i < pi; i++) {
    if(primes[i] > n)
      break;
    if(n % primes[i] == 0)
      return false;
  }
  return true;
}

void dfs(int idx, long long res, int num) {
  if(idx == pi || primes[idx] - 1 > num) {
    if(num == 1 || isprime(num+1)) {
      ans = min(ans, num == 1 ? res : res * (num+1));
    }
    return;
  }
  if(num % (primes[idx] - 1) == 0) {
    int nn = num / (primes[idx] - 1);
    long long rr = res * primes[idx];
    dfs(idx+1, rr, nn);
    while(nn % primes[idx] == 0) {
      nn /= primes[idx];
      rr *= primes[idx];
      dfs(idx+1, rr, nn);
    }
  }
  dfs(idx+1, res, num);
}

int main() {
  pi = 0;
  memset(check, false, sizeof check);
  for(int i = 2; i <= MAXN; i++) {
    if(!check[i])
      primes[pi++] = i;
    for(int j = 0; j < pi; j++) {
      if(i * primes[j] > MAXN)
	break;
      check[i * primes[j]] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
  int kase = 1;
  while(scanf("%d", &num) != EOF && num) {
    ans = INF;
    dfs(1, 1LL, num);
    printf("Case %d: %d %lld\n", kase++, num, ans == INF ? 0 : ans);
  }
  return 0;
}
