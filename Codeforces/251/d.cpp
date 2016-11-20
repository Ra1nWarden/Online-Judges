#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int a[maxn+5];
int b[maxn+5];
long long sa[maxn+5];
long long sb[maxn+5];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  sort(a, a+n);
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    sum += a[i];
    sa[i] = sum;
  }
  for(int i = 0; i < m; i++)
    scanf("%d", &b[i]);
  sort(b, b+m);
  sum = 0;
  for(int i = m - 1; i >= 0; i--) {
    sum += b[i];
    sb[i] = sum;
  }
  int ai = 0, bi = lower_bound(b, b + m, a[0]) - b;
  long long ans = 2000000000000000000LL;
  while(ai < n || bi < m) {
    int cur;
    if(ai == n) {
      cur = b[bi++];
    } else if(bi == m) {
      cur = a[ai++];
    } else if(a[ai] < b[bi]) {
      cur = a[ai++];
    } else {
      cur = b[bi++];
    }
    long long sum = 0;
    int am = lower_bound(a, a + n, cur) - a;
    if(am > 0) {
      sum += (cur * 1LL * am) - sa[am - 1];
    }
    int bm = upper_bound(b, b + m, cur) - b;
    if(bm < m) {
      sum += sb[bm] - (cur * 1LL * (m - bm));
    }
    ans = min(ans, sum);
  }
  printf("%I64d\n", ans);
  return 0;
}
