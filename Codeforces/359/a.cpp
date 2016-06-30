#include <cstdio>

using namespace std;

const int maxl = 1000;
char str[maxl+5];

int main() {
  int n;
  long long x;
  scanf("%d%I64d\n", &n, &x);
  int num;
  int cnt = 0;
  while(n--) {
    scanf("%s %d\n", &str, &num);
    if(str[0] == '+') {
      x += num;
    } else {
      if(num <= x) {
	x -= num;
      } else {
	cnt++;
      }
    }
  }
  printf("%I64d %d\n", x, cnt);
  return 0;
}
