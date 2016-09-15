#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int a = 0, b = 0;
  while(n--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if(x > y)
      a++;
    else if(x < y)
      b++;
  }
  if(a > b) {
    printf("Mishka\n");
  } else if(a == b) {
    printf("Friendship is magic!^^\n");
  } else {
    printf("Chris\n");
  }
  return 0;
}
