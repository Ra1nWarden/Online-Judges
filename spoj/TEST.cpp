#include <cstdio>

using namespace std;

int main() {
  int num;
  while(scanf("%d", &num)) {
    if(num == 42)
      break;
    printf("%d\n", num);
  }
  return 0;
}
