#include <cstdio>

using namespace std;

int main() {
  printf("10000\n");
  for(int i = 1; i <= 10000; i++) {
    printf("%d%c", i, (i == 10000 ? '\n' : ' '));
  }
  return 0;
}
