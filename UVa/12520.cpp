#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long removeAns(long long n, long long l) {
  n = l * l - n;
  long long dv[3] = {4, 2, 0};
  long long cv[3];
  memset(cv, 0, sizeof cv);
  if(l > 2) {
    long long square = (l - 2) * (l - 2);
    cv[0] = square - square / 2;
    cv[1] = ((l - 2) / 2) * 4;
    cv[2] = l % 2 ? 4 : 0;
  } else if(l == 2) {
    cv[2] = 2;
  }
  long long ans = l * 4;
  for(int i = 0; i < 3 && n > 0; i++) {
    long long used = min(n, cv[i]);
    ans += dv[i] * used;
    n -= used;
  }
  ans -= 4 * n;
  return ans;
}

long long addAns(long long n, long long l) {
  long long dv[2] = {0, -2};
  long long cv[2];
  cv[0] = l % 2 ? 0 : 2;
  cv[1] = l / 2 * 4 - (l % 2 ? 0 : 2);
  long long used = min(l * l - l * l / 2, n);
  long long ans = used * 4;
  n -= used;
  for(int i = 0; i < 2 && n > 0; i++) {
    used = min(cv[i], n);
    ans += dv[i] * used;
    n -= used;
  }
  ans -= 4 * n;
  return ans;
}

int main() {
  long long l, n;
  while(scanf("%lld %lld", &l, &n) != EOF && (l || n)) {
    printf("%lld\n", max(removeAns(n, l), addAns(n, l)));
  }
  return 0;
}
