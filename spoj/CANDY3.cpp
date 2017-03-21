#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    long long n;
    scanf("%lld", &n);
    long long ans = 0;
    long long num;
    for(long long i = 0; i < n; i++) {
      scanf("%lld", &num);
      ans += num % n;
      ans %= n;
    }
    printf("%s\n", ans == 0 ? "YES" : "NO");
  }
  return 0;
}
