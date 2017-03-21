#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int x[maxn+5];
int y[maxn+5];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &x[i]);
    sort(x, x+n);
    for(int i = 0; i < n; i++)
      scanf("%d", &y[i]);
    sort(y, y+n);
    int ans = 0;
    for(int i = 0; i <  n; i++) {
      ans += x[i] * y[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
