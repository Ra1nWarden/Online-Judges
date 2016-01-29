#include <cstdio>

using namespace std;

const long long mod = 100000007;

int main() {
  long long number;
  while(scanf("%lld", &number) != EOF && number) {
    bool printed = false;
    for(long long y = 1; y * y * 6 < number; y++) {
      if(number % y)
      	continue;
      long long num = number / y;
      long long x = num - y * 6;
      if(x % 7)
      	continue;
      x /= 7;
      x %= mod;
      printf("Possible Missing Soldiers = %lld\n", x * x * 2 % mod);
      printed = true;
      // long long tmp = number - y * y * 6;
      // if(tmp % (7 * y) == 0) {
      // 	long long x = tmp / (7 * y) % mod;
      //   printf("Possible Missing Soldiers = %lld\n", x * x * 2 % mod);
      // 	printed = true;
      // }
    }
    if(!printed) {
      printf("No Solution Possible\n");
    }
    printf("\n");
  }
  return 0;
}
