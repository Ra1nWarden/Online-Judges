#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if(x != y && y != x - 2) {
      printf("No Number\n");
    } else if (x == y) {
      printf("%d\n", (x & 1) ? x * 2 - 1 : x * 2);
    } else {
      printf("%d\n", (x & 1) ? x * 2 - 3 : x * 2 - 2);
    }
  }
  return 0;
}
