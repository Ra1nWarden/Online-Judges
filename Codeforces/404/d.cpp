#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 1000000007;
const int maxl = 200000;
char str[maxl+5];
int l;
int left[maxl+5], right[maxl+5];
int factorial[maxl*2+5];

void extendedGcd(long long a, long long b, long long& d, long long& x, long long& y) {
  if(!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    extendedGcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}

int modDiv(int a, int b) {
  long long x, y, d;
  extendedGcd((long long) b, (long long) mod, d, x, y);
  if(d != 1LL) {
    return -1;
  }
  x = (x % mod + mod) % mod;
  return (x * a) % mod;
}

int choose(int a, int b) {
  if(b > a) {
    return 0;
  }
  return modDiv(factorial[a], (factorial[b] * 1LL * factorial[a-b]) % mod);
}

void init() {
  factorial[0] = 1;
  for(int i = 1; i <= maxl*2; i++) {
    factorial[i] = (factorial[i-1] * 1LL * i) % mod;
  }
}

int main() {
  init();
  scanf("%s", str);
  l = strlen(str);
  int cnt = 0;
  for(int i = 0; i < l; i++) {
    if(str[i] == '(') {
      cnt++;
    }
    left[i] = cnt;
  }
  cnt = 0;
  for(int i = l - 1; i >= 0; i--) {
    if(str[i] == ')') {
      cnt++;
    }
    right[i] = cnt;
  }
  int ans = 0;
  for(int i = 0; i < l - 1; i++) {
    if(str[i] == '(') {
      ans = (ans + choose(left[i] + right[i+1] - 1, left[i])) % mod;
    }
  }
  printf("%d\n", ans);
  return 0;
}
