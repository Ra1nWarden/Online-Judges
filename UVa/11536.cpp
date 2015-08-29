#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
#define MAXK 105

using namespace std;

int v[MAXN];
int kv[MAXK];
int n, m, k, cnt;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
      if(i <= 3)
	v[i] = i;
      else
	v[i] = (v[i-1] + v[i-2] + v[i-3]) % m + 1;
    }
    int i = 1, j = 1;
    memset(kv, 0, sizeof kv);
    cnt = 0;
    int ans = -1;
    while(j <= n) {
      int num = v[j];
      if(num <= k) {
	kv[num]++;
	if(kv[num] == 1)
	  cnt++;
      }
      while(cnt == k) {
	ans = ans == -1 ? j - i + 1 : min(j - i + 1, ans);
	num = v[i++];
	if(num <= k) {
	  kv[num]--;
	  if(kv[num] == 0)
	    cnt--;
	}
      }
      j++;
    }
    printf("Case %d: ", kase);
    if(ans == -1)
      printf("sequence nai\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
