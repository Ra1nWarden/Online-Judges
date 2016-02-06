#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for(int i = 1; n - 2 - i > 0; i++) {
      int j = n - 2 - i;
      ans += (i * 1LL * j);
    }
    long long mult = n;
    int quota = 2;
    while(quota) {
      if(mult % 2 == 0) {
	mult >>= 1;
	quota--;
      }
      else if(ans % 2 == 0) {
	ans >>= 1;
	quota--;
      }
    }
    ans *= mult;
    ans += n;
    printf("%I64d\n", ans);
  }
  return 0;
}
