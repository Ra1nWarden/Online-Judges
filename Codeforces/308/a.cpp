#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for(int i =0; i < n; i++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    ans += (x2 - x1 + 1) * (y2 - y1 + 1);
  }
  printf("%d\n", ans);
  return 0;
}
