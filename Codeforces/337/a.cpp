#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if(n & 1) {
    printf("0\n");
  } else {
    n >>= 1;
    printf("%d\n", (n - 1) >> 1);
  }
  return 0;
}
