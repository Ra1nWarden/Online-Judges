#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int sum;
    scanf("%d %d", &n, &sum);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    int ans = 0, anst = 0, l = 0, r = 0, cur = 0;
    while(r < n) {
      while(cur <= sum && r < n) {
	if(r - l > anst) {
	  anst = r - l;
	  ans = cur;
	} else if(r - l == anst) {
	  ans = min(ans, cur);
	}
	cur += v[r++];
      }
      while(cur > sum && l < r) {
	cur -= v[l++];
      }
      if(r - l > anst) {
	anst = r - l;
	ans = cur;
      } else if(r - l == anst) {
	ans = min(ans, cur);
      }
    }
    printf("%d %d\n", ans, anst);
  }
  return 0;
}
