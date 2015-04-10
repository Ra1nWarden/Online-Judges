#include <cstdio>

using namespace std;

bool printExcess(int n, int start) {
  int ones = 0;
  for(int i = start; i >= start - n + 1; i-=2) {
    printf("%d - %d = 1\n", i, i - 1);
    ones++;
  }
  if(ones == 0)
    return false;
  for(int i = 0; i < ones - 1; i++) {
    printf("1 * 1 = 1\n");
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  if(n <= 3) {
    printf("NO\n");
  } else {
    printf("YES\n");
    if((n - 4) % 2 == 0) {
      bool excessone = printExcess(n - 4, n);
      printf("1 * 2 = 2\n");
      printf("2 * 3 = 6\n");
      printf("6 * 4 = 24\n");
      if(excessone)
	printf("1 * 24 = 24\n");
    } else {
      bool excessone = printExcess(n - 5, n);
      printf("2 + 3 = 5\n");
      printf("5 * 4 = 20\n");
      printf("20 + 5 = 25\n");
      printf("25 - 1 = 24\n");
      if(excessone)
	printf("1 * 24 = 24\n");
    }
  }
  return 0;
}
