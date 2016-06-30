#include <cstdio>
#define MAXN 1005
#define MOD 1000000007LL

using namespace std;

int v[MAXN];
int n;

long long power_mod(long long a, long long b) {
  if(b == 0)
    return 1;
  if(b == 1)
    return a % MOD;
  long long ans = power_mod(a, b/2) * power_mod(a, b/2) % MOD;
  if (b % 2 == 1) {
    ans *= a;
    ans %= MOD;
  }
  return ans;
}

long long inverse(long long a) {
  return power_mod(a, MOD-2);
}

long long choose(long long a, long long b) {
  if(b > a / 2)
    return choose(a, a-b);
  long long numerator = 1;
  long long denom = 1;
  for(long long i = 1; i <= b; i++) {
    numerator *= (a-i+1);
    numerator %= MOD;
    denom *= i;
    denom %= MOD;
  }
  return numerator * inverse(denom) % MOD;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }
  long long sum = 0;
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    if (i == 1) {
      sum = v[i];
      ans = 1;
    } else {
      long long add = v[i] - 1;
      ans = (ans * choose(sum + add, add)) % MOD;
      sum += v[i];
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
