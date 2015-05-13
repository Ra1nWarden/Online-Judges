#include <cstdio>
#define MAXN 12

using namespace std;

int pv[MAXN];
int lv[MAXN];
int vv[MAXN];
int n, d;

int main() {
  int kase = 1;
  while(scanf("%d %d", &n, &d) != EOF && (n || d)) {
    for(int i = 0; i < n; i++) {
      scanf("%d %d %d", &pv[i], &lv[i], &vv[i]);
    }
    double ans = d;
    for(int i = 0; i < n; i++) {
      ans += lv[i] * 2.0 / vv[i];
      ans -= lv[i];
    }
    printf("Case %d: %.3f\n\n", kase++, ans);
  }
  return 0;
}
