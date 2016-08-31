#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 1000000;
char str[maxn+5];

long long de(long long num) {
  num  = num * 2;
  if(num == 0)
    return 0;
  long long left = 1;
  long long right = num;
  while(left < right) {
    long long mid = ((left + right) >> 1) + 1;
    if(mid * mid <= num) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  if(left * (left + 1) != num) {
    return -1;
  } else {
    return left + 1;
  }
}

int main() {
  long long a00, a01, a10, a11;
  scanf("%I64d%I64d%I64d%I64d", &a00, &a01, &a10, &a11);
  long long one = de(a11);
  long long zero = de(a00);
  if(one == 0 && zero == 0) {
    if(a01 + a10 > 1) {
      printf("Impossible\n");
    } else if(a01 == 0 && a10 == 0) {
      printf("1\n");
    } else if(a01 == 0) {
      printf("10\n");
    } else {
      printf("01\n");
    }
    return 0;
  }
  if(one == 0 && a01 + a10 == zero) {
    for(int i = 0; i < a01; i++) {
      printf("0");
    }
    printf("1");
    for(int i = 0; i < a10; i++) {
      printf("0");
    }
    printf("\n");
    return 0;
  }
  if(zero == 0 && a01 + a10 == one) {
    for(int i = 0; i < a10; i++) {
      printf("1");
    }
    printf("0");
    for(int i = 0; i < a01; i++) {
      printf("1");
    }
    printf("\n");
    return 0;
  }
  if(one == -1 || zero == -1 || a01 + a10 != zero * one) {
    printf("Impossible\n");
    return 0;
  }
  long long total = zero + one;
  for(long long i = 0; i < total; i++) {
    if(a01 >= one && zero > 0 && one >= 0) {
      str[i] = '0';
      a01 -= one;
      zero--;
    } else if(a10 >= zero && zero >= 0 && one > 0) {
      str[i] = '1';
      a10 -= zero;
      one--;
    } else {
      printf("Impossible\n");
      return 0;
    }
  }
  str[total] = '\0';
  printf("%s\n", str);
  return 0;
}
