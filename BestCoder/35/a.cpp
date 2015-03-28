#include <cstdio>
#include <algorithm>

using namespace std;

long long n, m;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

long long choose(long long a, long long b) {
  if(b > a / 2)
    return choose(a, a - b);
  long long res = 1;
  for(long long j = 0; j < b; j++) {
    res *= (a - j);
    res /= (1 + j);
  }
  return res;
}

long long solven() {
  long long res = 0;
  for(long long i = 1; i <= min(n, m); i++) 
    res += i * choose(n, i) * choose(m , m - i);
  return res;
}

long long solved() {
  return choose(m+n, n);
}

int main() {
  while(scanf("%I64d %I64d", &n, &m) != EOF) {
    long long num = solven();
    long long denom = solved();
    long long fact = gcd(num, denom);
    printf("%I64d/%I64d\n", num / fact, denom / fact);
  }
  return 0;
}
