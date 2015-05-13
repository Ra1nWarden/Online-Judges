#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int pow10[10], cnt[10];

int f(int n, int d) {
  char num[11];
  sprintf(num, "%d", n);
  int len = strlen(num);
  int ans = 0;
  for(int i = 1; i < len; i++) {
    ans += 9 * cnt[i-1];
    if(d > 0)
      ans += pow10[i-1];
  }
  
  int pre[10];
  for(int i = 0; i < len; i++) {
    pre[i] = num[i] - '0' == d ? 1 : 0;
    if(i > 0)
      pre[i] += pre[i-1];
  }
  
  for(int i = 0; i < len; i++) {
    int start = 1;
    if(i > 0)
      start = 0;
    for(int digit = start; digit <= num[i] - '0' - 1; digit++) {
      ans += cnt[len - i - 1];
      if(digit == d)
	ans += pow10[len - i - 1];
      if(i > 0)
	ans += pre[i-1] * pow10[len - i - 1];
    }
  }
  return ans;
}

int main() {
  pow10[0] = 1;
  cnt[0] = 0;
  for(int i = 1; i < 10; i++) {
    pow10[i] = pow10[i-1] * 10;
    cnt[i] = pow10[i-1] * i;
  }
  int a, b;
  while(scanf("%d %d", &a, &b) != EOF && (a || b)) {
    if(a > b)
      swap(a, b);
    for(int i = 0; i < 10; i++) {
      if(i > 0)
	printf(" ");
      printf("%d", f(b+1, i) - f(a, i));
    }
    printf("\n");
  }
  return 0;
}
