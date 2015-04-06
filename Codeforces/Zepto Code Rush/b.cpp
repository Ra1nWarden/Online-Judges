#include <cstdio>
#include <algorithm>
#define MAXN 2050

using namespace std;

int n;
int v[MAXN];
int ans;

int f(int root) {
  if((root >> n) > 0) {
    return 0;
  }
  int lans = f(root << 1);
  int rans = f((root << 1) | 1);
  lans += v[root << 1];
  rans += v[(root << 1)|1];
  int ret = max(lans, rans);
  ans += max(lans, rans) - min(lans, rans);
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 2; i < (1 << (n+1)); i++) {
    scanf("%d", &v[i]);
  }
  ans = 0;
  f(1);
  printf("%d\n", ans);
  return 0;
}
