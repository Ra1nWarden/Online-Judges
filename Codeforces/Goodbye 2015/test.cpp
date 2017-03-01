#include <cstdio>

using namespace std;

int main() {
  printf("5000\n");
  for(int i = 0; i < 5000; i++) {
    printf("%d", (i+1)%10);
  }
  printf("\n");
  return 0;
}
