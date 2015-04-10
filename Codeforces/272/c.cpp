#include <cstdio>
#define MOD 1000000007

using namespace std;

int main() {
  long long a, b;
  scanf("%I64d %I64d", &a, &b);
  long long lhs = (a * (a+1) / 2) % MOD;
  lhs *= b;
  lhs %= MOD;
  lhs += a;
  lhs %= MOD;
  long long rhs = (b * (b-1) / 2) % MOD;
  printf("%I64d\n", (lhs * rhs) % MOD);
  return 0;
}
