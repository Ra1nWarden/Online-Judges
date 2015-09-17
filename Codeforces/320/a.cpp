#include <cstdio>

using namespace std;

int main() {
  int num;
  scanf("%d", &num);
  int ans = 0;
  while(num) {
    if(num&1) {
      ans++;
    }
    num >>= 1;
  }
  printf("%d\n", ans);
  return 0;
}
