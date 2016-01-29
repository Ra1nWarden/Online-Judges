#include <cstdio>

using namespace std;

void gcd(int a, int b, int& d, int& x, int& y) {
  if(!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int x, k;
    scanf("%d%d", &x, &k);
    int a = x / k;
    int b = x % k == 0 ? x / k : x / k + 1;
    int xx, yy, d;
    gcd(a, b, d, xx, yy);
    printf("%d %d\n", xx * (x / d), yy * (x / d));
  }
  return 0;
}
