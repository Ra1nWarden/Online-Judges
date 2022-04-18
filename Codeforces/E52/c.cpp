#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000;
int v[maxn+5];
long long prefix[maxn+5];
int n, k;

long long calc(int h, long long sum) {
  int idx = upper_bound(v, v+n, h) - v;
  //printf("idx=%d %lld - %lld - %lld\n", idx, prefix[n-1], prefix[idx-1], h * 1LL * (n - idx));
  long long ans = prefix[n-1] - prefix[idx-1] - h * 1LL * (n - idx) - sum;
  //printf("ans=%lld\n", ans);
  return ans;
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v, v+n);
  for(int i = 0; i < n; i++) {
    prefix[i] = v[i];
    if(i)
      prefix[i] += prefix[i-1];
  }
  int h = v[n-1];
  int ans = 0;
  long long sum = 0;
  while(h > v[0]) {
    int l = v[0], r = h;
    while(l < r) {
      int m = (l + r) >> 1;
      //printf("m=%d\n", m);
      if(calc(m, sum) <= k) {
	r = m;
      } else {
	l = m+1;
      }
    }
    sum += calc(l, sum);
    ans++;
    h = l;
  }
  printf("%d\n", ans);
  return 0;
}
