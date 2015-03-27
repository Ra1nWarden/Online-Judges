#include <cstdio>

using namespace std;

long long a, b;

int main() {
  scanf("%I64d %I64d", &a, &b);
  if(b - a < 2) {
    printf("-1\n");
  } else if(b - a == 2) {
    if(a % 2 == 0) {
      printf("%I64d %I64d %I64d\n", a, a+1, a+2);
    } else {
      printf("-1\n");
    }
  } else {
    if(a % 2 == 0) {
      printf("%I64d %I64d %I64d\n", a, a+1, a+2);
    } else {
      printf("%I64d %I64d %I64d\n", a+1, a+2, a+3);
    }
  }
  return 0;
}
