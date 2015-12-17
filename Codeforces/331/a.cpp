#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int xmin, xmax, ymin, ymax;
  scanf("%d %d", &xmin, &ymin);
  xmax = xmin;
  ymax = ymin;
  for(int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    xmin = min(xmin, x);
    xmax = max(xmax, x);
    ymin = min(ymin, y);
    ymax = max(ymax, y);
  }
  int ans = (ymax - ymin) * (xmax - xmin);
  printf("%d\n", ans == 0 ? -1 : ans);
  return 0;
}
