#include <cstdio>
#include <algorithm>
#define MAXN 1005

using namespace std;

int v[MAXN];
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  int ans = 0;
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    ans += min(v[a], v[b]);
  }
  printf("%d\n", ans);
  return 0;
}
