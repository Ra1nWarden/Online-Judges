#include <cstdio>
#include <algorithm>

using namespace std;

int calculate(long long n, long long sum) {
  if(sum > n + n - 1) {
    return 0;
  }
  long long mid = sum / 2;
  return min(mid, n - mid);
}

int main() {
  int n;
  scanf("%d", &n);
  if(n < 5) {
    printf("%d\n", (n - 1) * n / 2);
    return 0;
  }
  long long cur = 5LL;
  long long target = 9LL;
  long long base = 10LL;
  while(cur * 10 <= n) {
    cur *= 10;
    target = target * 10 + 9;
    base *= 10;
  }
  int ans = 0;
  for(int i = 0; i < 9; i++) {
    ans += calculate(n, target + base * i);
  }
  printf("%d\n", ans);
  return 0;
}
