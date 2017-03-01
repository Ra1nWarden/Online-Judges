#include <cstdio>

using namespace std;

int color(int x, int y) {
  if(x < 0)
    x = -x;
  if(y < 0)
    y = -y;
  if(x & 1)
    return (y & 1) ? 2 : 3;
  else
    return (y & 1) ? 1 : 4;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("YES\n");
  for(int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", color(x1, y1));
  }
  return 0;
}
