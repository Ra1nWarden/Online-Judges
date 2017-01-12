#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  long long n;
  scanf("%lld", &n);
  long long prev1 = 2;
  long long prev2 = 1;
  int ans;
  for(ans = 1; ans > 0; ans++) {
    long long cur = prev1 + prev2;
    if(cur > n) {
      break;
    }
    prev2 = prev1;
    prev1 = cur;
  }
  printf("%d\n", ans);
  return 0;
}
