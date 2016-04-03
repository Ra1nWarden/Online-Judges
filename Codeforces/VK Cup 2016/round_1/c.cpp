#include <cstdio>

using namespace std;

int main() {
  int n, d, h;
  scanf("%d%d%d", &n, &d, &h);
  if(d == 1 && h == 1 && n > 2) {
    printf("-1\n");
    return 0;
  }
  if(d > 2 * h) {
    printf("-1\n");
  } else if(d == h) {
    for(int i = 1; i <= d; i++) {
      printf("%d %d\n", i, i + 1);
    }
    for(int i = d + 2; i <= n; i++) {
      printf("2 %d\n", i);
    }
  } else {
    for(int i = 1; i <= h; i++) {
      printf("%d %d\n", i, i + 1);
    }
    printf("1 %d\n", h + 2);
    for(int i = 1; i <= d - h - 1; i++) {
      printf("%d %d\n", h + 1 + i, h + 2 + i);
    }
    for(int i = d + 2; i <= n; i++) {
      printf("1 %d\n", i);
    }
  }
  return 0;
}
