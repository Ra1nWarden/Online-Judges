#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 500000;
const int maxv = 1000000;
int n, k;
int v[maxn+5];
int cnt[maxv+5];
int ll, rr, ans;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  int l = 1, r = 1;
  memset(cnt, 0, sizeof cnt);
  ll = -1;
  rr = -1;
  ans = 0;
  int total = 0;
  while(l <= n || r <= n) {
    while(total <= k && r <= n) {
      int num = v[r];
      if(cnt[num] == 0) {
	total++;
      }
      cnt[num]++;
      if(total <= k && ((ll == -1 && rr == -1) || r - l + 1 > rr - ll + 1)) {
	ll = l;
	rr = r;
      }
      r++;
    }
    if(r > n)
      break;
    while(total > k && l <= r) {
      int num = v[l++];
      cnt[num]--;
      if(cnt[num] == 0) {
	total--;
      }
    }
    if(l > r)
      r = l;
  }
  printf("%d %d\n", ll, rr);
  return 0;
}
