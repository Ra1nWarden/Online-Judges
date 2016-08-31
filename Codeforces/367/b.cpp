#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v, v+n);
  int q;
  scanf("%d", &q);
  while(q--) {
    int x;
    scanf("%d", &x);
    int ans = upper_bound(v, v+n, x) - v;
    printf("%d\n", ans);
  }
  return 0;
}
