#include <cstdio>

using namespace std;

int main() {
  for(int i =0; i < 100000; i++) {
    printf("%c", i % 26 + 'a');
  }
  printf("\n");
  printf("50000\n");
  for(int i = 1; i <= 50000; i++) {
    if(i > 1)
      printf(" ");
    printf("%d", i);
  }
  return 0;
}
