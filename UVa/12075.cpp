#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000;
long long prefix[maxn+1][maxn+1];

long long choose_three(long long n) {
  return n < 3 ? 0 : n * (n - 1) * (n - 2) / 6;
}

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  long long m, n;
  memset(prefix, 0, sizeof prefix);
  for(int i = 2; i <= maxn; i++) {
    for(int j = 2; j <= maxn; j++) {
      prefix[i][j] = gcd(i, j) - 1;
    }
  }
  for(int i = 2; i <= maxn; i++) {
    for(int j = 3; j <= maxn; j++) {
      prefix[i][j] += prefix[i][j-1];
    }
  }
  for(int i = 3; i <= maxn; i++) {
    for(int j = 2; j <= maxn; j++) {
      prefix[i][j] += prefix[i-1][j];
    }
  }
  int kase = 1;
  while(scanf("%lld%lld", &m, &n) != EOF && (n || m)) {
    long long ans = choose_three((m + 1) * 1LL * (n + 1));
    ans -= (m + 1) * 1LL * choose_three(n + 1);
    ans -= (n + 1) * 1LL * choose_three(m + 1);
    for(int i = 2; i <= m; i++) {
      for(int j = 0; j <= n; j++) {
	ans -= (prefix[i][j] + prefix[i][n - j]);
      }
    }
    printf("Case %d: %lld\n", kase++, ans);
  }
  return 0;
}
