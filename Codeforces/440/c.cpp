#include <cstdio>

using namespace std;

const int base[] = {-1, -1, -1, 1, -1, 1, -1, 2, 1, 2, -1, 3, 2, 3, 2};

int main() {
  int q;
  scanf("%d", &q);
  int n;
  while(q--) {
    scanf("%d", &n);
    if(n < 16) {
      printf("%d\n", base[n-1]);
    } else {
      printf("%d\n", ((n - 12) / 4) + base[(n % 4) + 11]);
    }
  }
  return 0;
}
