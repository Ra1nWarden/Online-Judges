#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int divide(int dividend, int divisor) {
  if(divisor == 0)
    return INT_MAX;
  else {
    bool same_sign = (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0);
    long long divi = abs((long long)dividend);
    long long divis = abs((long long)divisor);
    int base = 0;
    while(divi >= (divis << 1)) {
      divis <<= 1;
      base++;
    }
    long long res = 0;
    while(base >= 0) {
      while(divi < divis && base >= 0) {
	base--;
	divis >>= 1;
      }
      if(divi >= divis && base > -1) {
	divi -= divis;
	res |= (1LL << base);
      }
    }
    res = same_sign ? res : -res;
    if((int) res != res)
      return INT_MAX;
    else
      return res;
  }
}

int main() {
  printf("%d\n", divide(-1, -1));
  return 0;
}

