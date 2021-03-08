#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for(int i = 0; i <= min(8, n); i++) {
    for(int j = 0; j <= 8 && i + j <= n; j++) {
      if(j >= 5 && i >= 1) {
	continue;
      }
      ans += n - i - j + 1;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
