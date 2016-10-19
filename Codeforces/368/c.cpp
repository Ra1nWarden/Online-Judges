#include <cstdio>

using namespace std;

int main() {
  long long n;
  scanf("%I64d", &n);
  if(n < 3) {
    printf("-1\n");
  } else {
    if(n & 1LL) {
      long long p = n * n;
      printf("%I64d %I64d\n", p / 2, p / 2 + 1);
    } else {
      long long f = 1LL;
      while(!((n & 1LL) || n == 4)) {
	n >>= 1;
	f <<= 1;
      }
      if(n == 4) {
	printf("%I64d %I64d\n", 3LL * f, 5LL * f);
      } else {
	long long p = n * n;
	printf("%I64d %I64d\n", p / 2 * f, (p / 2 + 1) * f);
      }
    }
  }
  return 0;
}
