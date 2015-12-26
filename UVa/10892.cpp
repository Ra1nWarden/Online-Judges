#include <cstdio>

using namespace std;

int main() {
  int n;
  while(scanf("%d", &n) != EOF && n) {
    long long ans = 1LL;
    int ncpy = n;
    for(int i = 2; i * i <= n; i++) {
      int ri = 0;
      while(n % i == 0) {
	n /= i;
	ri++;
      }
      if(ri) {
	ans *= (ri * 1LL * 2) + 1;
      }
    }
    if(n > 1)
      ans *= 3;
    ans = (ans >> 1) + 1;
    printf("%d %lld\n", ncpy, ans);
  }
  return 0;
}
