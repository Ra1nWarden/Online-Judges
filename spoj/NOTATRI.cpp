#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2000;
int v[maxn+5];
int n;

int main() {
  while(scanf("%d", &n)) {
    if(n == 0)
      break;
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    sort(v, v+n);
    long long ans = 0;
    for(int i = 0; i < n - 2; i++) {
      int j = i + 1;
      while(j < n - 1) {
	int k = upper_bound(v, v+n, v[i] + v[j]) - v;
	ans += k - 1 - j;
	j++;
      }
    }
    printf("%lld\n", n * 1LL * (n - 1) * (n - 2) / 6 - ans);
  }
  return 0;
}
