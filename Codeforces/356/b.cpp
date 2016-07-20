#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
int v[maxn+5];
int n, a;

int main() {
  scanf("%d%d", &n, &a);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }
  int ans = v[a];
  int diff;
  for(diff = 1; diff < max(a, n + 1 - a); diff++) {
    if(a - diff < 1) {
      ans += v[a + diff];
    } else if(a + diff > n) {
      ans += v[a - diff];
    } else if(v[a - diff] && v[a + diff]) {
      ans += 2;
    }
  }
  printf("%d\n", ans);
  return 0;
}
