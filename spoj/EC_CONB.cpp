#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    int x;
    scanf("%d", &x);
    if(1 & x) {
      printf("%d\n", x);
    } else {
      int y = 0;
      while(x) {
	y <<= 1;
	y |= (1 & x);
	x >>= 1;
      }
      printf("%d\n", y);
    }
  }
  return 0;
}
