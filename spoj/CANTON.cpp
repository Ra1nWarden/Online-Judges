#include <cstdio>

using namespace std;

bool ok(int x, int y) {
  return (1 + x) * x >= y * 2;
}

int main() {
  int tc;
  scanf("%d", &tc);
  int x;
  while(tc--) {
    scanf("%d", &x);
    int l = 1, r = 10000;
    while(l != r) {
      int m = (l + r) >> 1;
      if(ok(m, x)) {
	r = m;
      } else {
	l = m + 1;
      }
    }
    int sum = l + 1;
    int offset = x - l * (l - 1) / 2;
    int denom, num;
    if(l & 1) {
      denom = offset;
      num = sum - denom;
    } else {
      num = offset;
      denom = sum - num;
    }
    printf("TERM %d IS %d/%d\n", x, num, denom);
  }
  return 0;
}
