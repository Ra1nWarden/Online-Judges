#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  int diff = 0;
  int l, r;
  for(int i = 1; i <= n; i++) {
    scanf("%d%d", &l, &r);
    v[i] = r - l;
    diff += l - r;
  }
  int mindiff = diff;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(abs(diff + 2 * v[i]) > abs(mindiff)) {
      mindiff = diff + 2 * v[i];
      ans = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
