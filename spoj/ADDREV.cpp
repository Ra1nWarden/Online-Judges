#include <cstdio>
#include <cstring>

using namespace std;

long long rev(long long num) {
  long long ans = 0;
  while(num) {
    ans *= 10;
    ans += num % 10;
    num /= 10;
  }
  return ans;
}

int main() {
  int tc;
  scanf("%d\n", &tc);
  long long a, b;
  while(tc--) {
    scanf("%lld %lld\n", &a, &b);
    a = rev(a);
    b = rev(b);
    printf("%lld\n", rev(a + b));
  }
  return 0;
}
