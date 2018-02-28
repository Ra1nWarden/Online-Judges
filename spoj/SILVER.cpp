#include <cstdio>

using namespace std;

int main() {
  int x;
  while(true) {
    scanf("%d", &x);
    if(x == 0)
      break;
    int ans = 0;
    while(x) {
      x >>= 1;
      ans++;
    }
    printf("%d\n", ans - 1);
  }
  return 0;
}
