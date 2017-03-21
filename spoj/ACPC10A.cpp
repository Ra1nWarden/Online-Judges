#include <cstdio>

using namespace std;

int main() {
  int a, b, c;
  while(scanf("%d%d%d", &a, &b, &c)) {
    if(a == 0 && b == 0 && c == 0)
      break;
    if(c - b == b - a) {
      printf("AP %d\n", c + (b - a));
    } else {
      printf("GP %d\n", c * (b / a));
    }
  }
  return 0;
}
