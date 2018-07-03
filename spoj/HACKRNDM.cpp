#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v, v+n);
  int li = 0, ri = 1;
  int ans = 0;
  while(ri < n) {
    if(v[ri] - v[li] > k) {
      li++;
    } else if(v[ri] - v[li] < k) {
      ri++;
    } else {
      ans++;
      ri++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
