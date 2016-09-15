#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int win = 2;
  while(n--) {
    int num;
    scanf("%d", &num);
    num--;
    win += num;
    win %= 2;
    if(win == 0)
      win = 2;
    printf("%d\n", win);
  }
  return 0;
}
