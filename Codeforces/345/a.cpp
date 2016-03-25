#include <cstdio>

using namespace std;

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int time = 0;
  while(a > 0 && b > 0) {
    if(a <= b) {
      a += 1;
      b -= 2;
    } else {
      b += 1;
      a -= 2;
    }
    if(a < 0 || b < 0) {
      break;
    }
    time++;
  }
  printf("%d\n", time);
  return 0;
}
