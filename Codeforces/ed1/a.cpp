#include <cstdio>

using namespace std;

long long calc(long long n) {
  long long ans = 1LL;
  while(ans <= n) {
    ans <<= 1;
  }
  ans--;
  long long sum = (1 + n) * n / 2;
  sum -= 2 * ans;
  return sum;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%I64d", &n);
    printf("%I64d\n", calc(n));
  }
  return 0;
}
