#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 50;
int x_bit[maxl], s_bit[maxl];
int xn, sn;

int main() {
  memset(x_bit, 0, sizeof x_bit);
  memset(s_bit, 0, sizeof s_bit);
  xn = sn = 0;
  long long s, x;
  scanf("%I64d %I64d", &s, &x);
  bool same = x == s;
  if(x == 0) {
    if(s % 2 == 0) {
      printf("1\n");
    } else {
      printf("0\n");
    }
    return 0;
  }
  while(x) {
    if(x & 1LL) {
      x_bit[xn] = 1;
    }
    x >>= 1;
    xn++;
  }

  while(s) {
    if(s & 1LL) {
      s_bit[sn] = 1;
    }
    sn++;
    s >>= 1;
  }
  
  // printf("xn=%d sn=%d\n", xn, sn);
  // for(int i = 0; i < xn; i++) {
  //   printf("%d ", x_bit[i]);
  // }
  // printf("\n");
  // for(int i = 0; i < sn; i++) {
  //   printf("%d ", s_bit[i]);
  // }
  // printf("\n");

  if(xn > sn) {
    printf("0\n");
    return 0;
  }
  long long ans = 1;
  bool carry = false;
  for(int i = sn - 1; i > -1; i--) {
    if(s_bit[i]) {
      if(x_bit[i]) {
	if(carry) {
	  ans = 0;
	  break;
	} else {
	  ans *= 2;
	}
      } else {
	if(!carry) {
	  carry = true;
	}
      }
    } else {
      if(x_bit[i]) {
	if(carry) {
	  ans *= 2;
	} else {
	  ans = 0;
	}
      } else {
	if(carry) {
	  carry = false;
	}
      }
    }
  }
  if(carry) {
    printf("0\n");
  } else {
    if(same)
      ans -= 2;
    printf("%I64d\n", ans);
  }
  return 0;
}
