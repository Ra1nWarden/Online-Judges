#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    long long num;
    scanf("%lld", &num);
    long long ans = 0;
    long long fact = 5;
    while(fact <= num) {
      ans += num / fact;
      fact *= 5;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
