#include <cstdio>

using namespace std;

int main() {
  int num;
  scanf("%d", &num);
  int ans = num / 3 * 2;
  if(num % 3 != 0) {
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
