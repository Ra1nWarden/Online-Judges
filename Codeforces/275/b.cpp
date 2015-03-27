#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

int main() {
  long long cnt1, cnt2, x, y;
  scanf("%I64d %I64d %I64d %I64d", &cnt1, &cnt2, &x, &y);
  long long start = cnt1 + cnt2;
  long long mult = lcm(x, y);
  long long end = (cnt1 / (x - 1) + 1) * x + (cnt2 / (y - 1) + 1) * y;
  while(start < end) {
    long long ans = (start + end) / 2;
    long long need1 = max(0LL, cnt1 - (ans / y - ans / mult));
    long long need2 = max(0LL, cnt2 - (ans / x - ans / mult));
    long long free = ans - ans / x - ans / y + ans / mult;
    if(need1 + need2 <= free) {
      end = ans;
    } else {
      start = ans + 1;
    }
  }
  printf("%I64d\n", start);
  return 0;
}
