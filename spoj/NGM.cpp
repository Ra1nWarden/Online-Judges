#include <cstdio>

using namespace std;

int main() {
  int num;
  while(scanf("%d", &num) != EOF) {
    if(num % 10 == 0) {
      printf("2\n");
    } else {
      printf("1\n%d\n", num % 10);
    }
  }
  return 0;
}
