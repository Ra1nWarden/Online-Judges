#include <cstdio>

using namespace std;

long long power(int base, int p) {
  if(p == 0)
    return 1LL;
  long long sub = power(base, p / 2);
  if(p & 1)
    return sub * sub * base;
  else
    return sub * sub;
}

long long f(long long num) {
  if(num == -1)
    return 0;
  long long ans = 1;
  long long prefix, postfix = 0;
  int k = 0;
  while(num) {
    prefix = num / 10;
    int digit = num % 10;
    if(digit == 0) {
      ans += (prefix - 1) * 1LL * power(10, k) + postfix + 1;
    } else {
      ans += prefix * 1LL * power(10, k);
    }
    num = prefix;
    postfix += digit * power(10, k);
    k++;
  }
  return ans;
}

int main() {
  long long m, n;
  while(scanf("%lld%lld", &m, &n) != EOF && (n >= 0 || m >= 0)) {
    printf("%lld\n", f(n) - f(m-1));
  }
  return 0;
}
