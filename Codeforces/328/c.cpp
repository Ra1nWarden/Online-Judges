#include <cstdio>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return a * (b / gcd(a, b));
}

long long t, w, b;

int main() {
  scanf("%I64d %I64d %I64d", &t, &w, &b);
  long long mult = lcm(w, b);
  long long cap = min(w, b);
  long long denom = t;
  long long num;
  if(mult <= 0 || mult % w != 0 || mult % b != 0) {
    num = cap - 1 - (cap - min(cap, t + 1));
  } else {
    num = (t / mult + 1) * cap - 1 - (cap - min(cap, t % mult + 1));
  }
  long long factor = gcd(denom, num);
  printf("%I64d/%I64d\n", num / factor, denom / factor);
  return 0;
}
