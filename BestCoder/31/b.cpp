#include <cstdio>
#include <sstream>
#include <cstring>

using namespace std;

int dpv[10][10];

bool valid(int num) {
  int prev = 1;
  while(num != 0) {
    int lastdig = num % 10;
    num /= 10;
    if(lastdig % prev != 0)
      return false;
    if(lastdig == 0)
      return false;
    prev = lastdig;
  }
  return true;
}

int dp(int a, int len) {
  //printf("calling dp[%d][%d]\n", a, len);
  if(len == 1)
    return dpv[a][len] = a == 0 ? 0 : 1;
  int res = 0;
  for(int i = 1; i <= a; i++) {
    if(a % i == 0)
      res += dp(i, len - 1);
  }
  return dpv[a][len] = res;
}

int dph(int len) {
  //printf("in dph(%d)\n", len);
  int res = 0;
  for(int i = 1; i <= len; i++) {
    for(int j = 1; j <= 9; j++)
      res += dp(j, i);
  }
  //printf("returning dph(%d) = %d\n", len, res);
  return res;
}

int f(int num) {
  //printf("in f(%d)\n", num);
  int res = 0;
  stringstream ss;
  ss << num;
  string numstr = ss.str();
  res += dph(numstr.length() - 1);
  int prev;
  for(int i = 0; i <numstr.length(); i++) {
    int dig = numstr[i] - '0';
    for(int j = 1; j < dig; j++)
      if(i == 0 || prev % j == 0)
	res += dp(j, numstr.length() - i);
    if(dig == 0)
      break;
    if(i > 0 && prev % dig != 0)
      break;
    prev = dig;
  }
  if(valid(num))
    res++;
  //printf("returning f(%d) =%d\n", num, res);
  return res;
}

int main() {
  int tc;
  memset(dpv, -1, sizeof dpv);
  scanf("%d", &tc);
  while(tc--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", f(r) - f(l) + (valid(l) ? 1 : 0));
  }
  return 0;
}
