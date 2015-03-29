#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if(a != 1 && b != 1 && c != 1) {
    printf("%d\n", a * b * c);
  } else if(c == 1 && a == 1) {
    printf("%d\n", a+b+c);
  } else if(c == 1) {
    printf("%d\n", a*(b+c));
  } else if(a == 1) {
    printf("%d\n", (a+b)*c);
  } else {
    // b == 1
    printf("%d\n", max((a+b) * c, a * (b+c)));
  }
  return 0;
}
