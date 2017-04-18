#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    long long a, b, s;
    scanf("%lld %lld %lld", &a, &b, &s);
    long long n = s * 2 / (a + b);
    long long diff = (b - a) / (n - 5);
    long long start = a - (diff * 2);
    printf("%lld\n", n);
    for(long long i = 0; i < n; i++) {
      if(i)
	printf(" ");
      printf("%lld", start);
      start += diff;
    }
    printf("\n");
  }
  return 0;
}
