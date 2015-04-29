#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n, s1, v1, s2, v2;
  int tc;
  scanf("%d", &tc);
  int kase = 1;
  while(tc--) {
    scanf("%d %d %d %d %d", &n, &s1, &v1, &s2, &v2);
    if(s1 > s2) {
      swap(s1, s2);
      swap(v1, v2);
    }
    long long ans = 0;
    if(n / s2 >= 1000000) {
      if(s1 * 1LL * v2 > s2 * 1LL * v1) {
	for(int i = 0; i < s2; i++) {
	  ans = max(ans, i * 1LL * v1 + (n - i * s1) / s2 * 1LL * v2);
	}
      } else {
	for(int i = 0; i < s1; i++) {
	  ans = max(ans, i * 1LL * v2 + (n - i * s2) / s1 * 1LL * v1);
	}
      }
    } else {
      for(int i = 0; i * 1LL * s2 <= n; i++) {
	ans = max(ans, i * 1LL * v2 + (n - i * s2) /  s1 * 1LL * v1);
      }
    }
    printf("Case #%d: %lld\n", kase++, ans);
  }
  return 0;
}
