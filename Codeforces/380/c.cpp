#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, s, t;
const int maxn = 200000;
int cv[maxn+5];
int vv[maxn+5];
int v[maxn+5];
int presum[maxn+5];
int postsum[maxn+5];

int main() {
  scanf("%d%d%d%d", &n, &k, &s, &t);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &cv[i], &vv[i]);
  }
  for(int i = 1; i <= k; i++) {
    scanf("%d", &v[i]);
  }
  v[0] = 0;
  v[k+1] = s;
  sort(v, v+k+2);
  for(int i = 0; i <= k; i++) {
    v[i] = v[i+1] - v[i];
  }
  sort(v, v+k+1);
  int sum = 0;
  for(int i = k; i >= 0; i--) {
    sum += v[i];
    postsum[i] = sum;
  }
  sum = 0;
  for(int i = 0; i <= k; i++) {
    sum += v[i];
    presum[i] = sum;
  }
  int ans = -1;
  for(int i = 0; i < n; i++) {
    if(vv[i] < v[k])
      continue;
    int total = 0;
    int d = upper_bound(v, v+k+1, vv[i] / 2) - v;
    if(d - 1 <= k) {
      total += presum[d - 1];
    }
    //printf("i=%d total=%d d=%d\n", i, total, d);
    if(d <= k) {
      //printf("%d * 2 - (%d - %d + 1) * %d + %d\n", postsum[d], k, d, vv[i], postsum[d]);
      total += postsum[d] * 2 - (k - d + 1) * vv[i] + postsum[d];
    }
    //printf(" total=%d\n", total);
    if(total <= t) {
      if(ans == -1 || cv[i] < ans) {
	ans = cv[i];
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
