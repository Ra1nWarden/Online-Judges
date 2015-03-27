#include <cstdio>
#define MOD 3814697265625LL
#define MAXN 1000000000000000000

using namespace std;

long long v[MAXN];

int main() {
  v[0] = 0;
  for(int i = 1; i <= MAXN; i++) {
    v[i] = (v[i-1] * (4 * i - 2) / (i + 1)) % MOD;
  }
  int tc;
  scanf("%d", &tc);
  for(int i = 0; i < tc; i++) {
    long long n;
    scanf("%I64d", &n);
    printf("Case #%d: %I64d\n", i+1, v[n]);
  }
  return 0;
}
