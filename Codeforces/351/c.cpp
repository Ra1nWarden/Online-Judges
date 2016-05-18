#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 5000;
int cnt[maxn+5];
int v[maxn+5];
int ans[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  memset(ans, 0, sizeof ans);
  for(int i = 0; i < n; i++) {
    memset(cnt, 0, sizeof cnt);
    int maxval = -1;
    int maxcnt = 0;
    for(int j = i; j < n; j++) {
      int num = v[j];
      cnt[num]++;
      if(cnt[num] > maxcnt || (cnt[num] == maxcnt && num < maxval)) {
	maxval = num;
	maxcnt = cnt[num];
      }
      ans[maxval]++;
    }
  }
  for(int i = 1; i <= n; i++) {
    if(i > 1)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
