#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n;
    scanf("%d", &n);
    long long prev_ans = 0;
    long long ans = 0;
    long long prev = 0;
    for(int i = 0; i < n; i++) {
      long long x;
      scanf("%lld", &x);
      if(i == 0) {
	prev = x;
	continue;
      }
      long long prev_ans_tmp = ans;
      ans += (ans - prev_ans);
      ans += (x - prev) * i;
      prev_ans = prev_ans_tmp;
      prev = x;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
