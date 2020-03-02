#include <cstdio>

using namespace std;

const int max = 1 << 17;

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  if(n == 1) {
    printf("YES\n");
    printf("%d\n", x);
    return 0;
  }
  if(n == 2) {
    if(x == 0) {
      printf("NO\n");
      return 0;
    } else {
      printf("YES\n");
      printf("0 %d\n", x);
      return 0;
    }
  }
  printf("YES\n");
  int cur = 0;
  for(int i = 1; i <= n - 3; i++) {
    printf("%d ", i);
    cur ^= i;
  }
  if(cur == x) {
    printf("%d %d %d\n", max, max << 1, max ^ (max << 1));
  } else {
    printf("%d %d %d\n", 0, max, max ^ cur ^ x);
  }
  return 0;
}
