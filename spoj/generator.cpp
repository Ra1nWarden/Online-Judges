#include <cstdio>

using namespace std;

int main() {
  int n = 10000;
  printf("%d\n", n);
  for(int i = 0; i < n - 1; i++) {
    printf("%d %d\n", i+1, i+2);
  }
  return 0;
}
