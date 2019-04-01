#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000000;
int v[maxn+5];
long long sum[maxn+5];
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v, v+n);
  long long cur = 0;
  for(int i = n-1; i >= 0; i--) {
    cur += v[i];
    sum[i] = cur;
  }
  int left = 0, right = v[n-1];
  while(left < right) {
    int mid = ((left + right) >> 1) + 1;
    int idx = upper_bound(v, v+n, mid) - v;
    long long total = sum[idx] - (mid * 1LL * (n - idx));
    if(total >= m) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  printf("%d\n", left);
  return 0;
}
