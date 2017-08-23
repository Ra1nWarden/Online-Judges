#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  long long x, y, p, q;
  while(tc--) {
    scanf("%I64d%I64d%I64d%I64d", &x, &y, &p, &q);
    if(p == 0) {
      printf("%d\n", x == 0 ? 0 : -1);
      continue;
    }
    long long mult = max((y + q - 1) / q, (x + p - 1) / p);
    long long diff = q * mult - y - (p * mult - x);
    if(diff < 0) {
      if(p - q == 0) {
	printf("-1\n");
      } else {
	mult += (-diff + (q - p) - 1) / (q - p);
	printf("%I64d\n", q * mult - y);
      }
    } else {
      printf("%I64d\n", mult * q - y);
    }
  }
  return 0;
}
