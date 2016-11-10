#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long num = 2;
  for(int i = 1; i <= n; i++) {
    if(i == 1) {
      printf("2\n");
    } else {
      printf("%I64d\n", i * 1LL * (i + 1) * (i + 1) - i + 1);
    }
  }
  return 0;
}
