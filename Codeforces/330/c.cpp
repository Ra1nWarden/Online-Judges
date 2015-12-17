#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000;
int v[maxn];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n;i ++)
    scanf("%d", &v[i]);
  sort(v, v+n);
  int ans = 2000000000;
  for(int i = 0; i + n / 2 < n; i++) {
    ans = min(v[i+n/2] - v[i], ans);
  }
  printf("%d\n", ans);
  return 0;
}
