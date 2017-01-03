#include <cstdio>

using namespace std;

int main() {
  int k, r;
  scanf("%d%d", &k, &r);
  for(int i = 1; i <= 10; i++) {
    int total = k * i;
    if(total % 10 == 0 || total % 10 == r) {
      printf("%d\n", i);
      return 0;
    }
  }
}
