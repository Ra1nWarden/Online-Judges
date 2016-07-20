#include <cstdio>
#include <algorithm>

using namespace std;

long long cnt(long long n) {
  long long ans = 0;
  for(long long i = 2; i * i * i <= n; i++) {
    ans += (n / (i * i * i));
  }
  return ans;
}

long long find_max(long long n) {
  long long ans = 0;
  for(long long i = 1; i * i * i <= n; i++) {
    ans = max(ans, n / (i * i * i) * (i * i * i));
  }
  return ans;
}

int main() {
  long long n;
  scanf("%I64d", &n);
  long long l = 1, r = 8000000000000000;
  while(l < r) {
    long long m = (l + r) >> 1;
    if(cnt(m) < n) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  if(cnt(l) == n) {
    printf("%I64d\n", find_max(l));
  } else {
    printf("-1\n");
  }
  return 0;
}
