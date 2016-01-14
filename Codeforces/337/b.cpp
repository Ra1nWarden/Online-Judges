#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  int minval = 2000000000;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    minval = min(minval, v[i]);
  }
  int start = 0;
  int cnt = 0;
  int ans = 0;
  bool startflag = true;
  for(int i = 0; i < n; i++) {
    if(v[i] > minval) {
      if(startflag) {
	start++;
	ans++;
      } else {
	cnt++;
      }
    } else {
      if(!startflag) {
	ans = max(ans, cnt);
	cnt = 0;
      }
      startflag = false;
    }
    if(i == n - 1 && !startflag) {
      ans = max(ans, cnt + start);
    }
  }
  printf("%I64d\n", minval * 1LL * n + ans);
  return 0;
}
