#include <cstdio>
#include <algorithm>

using namespace std;

long long f(int a, int d, int n) {
  long long sum = (long long)a + (a - (long long) n * d);
  sum *= (n + 1); 
  sum /= 2;
  return sum;
}

int main() {
  int n, k;
  while(scanf("%d %d", &n, &k) != EOF) {
    int i = 1;
    long long ans = 0;
    while(i <= n) {
      int r = k % i;
      int d = k / i;
      int cnt = n - i;
      if(d != 0)
	cnt = min(n - i, r / d);
      ans += f(r, d, cnt);
      i += cnt + 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
