#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005

using namespace std;

int cnt[MAXN];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  int kase = 1;
  while(tc--) {
    memset(cnt, 0, sizeof cnt);
    scanf("%d", &n);
    int ans = 1;
    for(int i =0; i < n; i++) {
      int x;
      scanf("%d", &x);
      cnt[x]++;
      ans = max(ans, x);
    }
    int maxval = ans;
    for(; ans > 1; ans--) {
      int mult = 1;
      int total = 0;
      while(mult * ans <= maxval) {
	total += cnt[mult * ans];
	mult++;
	if(total >= 2)
	  break;
      }
      if(total >= 2)
	break;
    }
    printf("Case #%d: %d\n", kase++, ans);
  }
  return 0;
}
