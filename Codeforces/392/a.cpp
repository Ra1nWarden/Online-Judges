#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  int x = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    x = max(x, v[i]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += x - v[i];
  }
  printf("%d\n", ans);
  return 0;
}
