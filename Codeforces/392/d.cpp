#include <cstdio>
#include <cstring>

using namespace std;

int n;
const int maxl = 60;
char num[maxl+5];

int main() {
  scanf("%d\n%s", &n, num);
  long long ans = 0;
  int i = strlen(num) - 1;
  int ii = strlen(num);
  int base = 1;
  long long mult = 0;
  long long power = 1LL;
  while(i >= 0) {
    int digit = num[i] - '0';
    mult += digit * 1LL * base;
    if(mult >= n || base >= n) {
      while(mult >= n) {
	int dig = num[i] - '0';
	mult -= dig * 1LL * base;
	base /= 10;
	i++;
      }
      ans += power * mult;
      if(mult != 0) {
	while(num[i] == '0') {
	  i++;
	}
      } else {
	i = ii - 1;
      }
      ii = i--;
      power *= n;
      base = 1;
      mult = 0;
    } else {
      base *= 10;
      i--;
    }
  }
  ans += power * mult;
  printf("%I64d\n", ans);
  return 0;
}
