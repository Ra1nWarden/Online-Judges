#include <cstdio>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long ans = 0;
  for(int i = 0; i < 5; i++) {
    long long x, y;
    if(i == 0) {
      x = n / 5;
      y = m / 5;
    } else {
      x = n / 5 + ((n % 5) >= i ? 1 : 0);
      y = m / 5 + ((m % 5) >= (5 - i) ? 1 : 0);
    }
    //printf("i=%d x=%I64d y=%I64d\n", i, x, y);
    ans += x * y;
  }
  printf("%I64d\n", ans);
  return 0;
}
