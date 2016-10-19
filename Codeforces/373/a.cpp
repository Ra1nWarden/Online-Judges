#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int num;
  int a, b;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &num);
    if(i == n-1) {
      a = num;
    } else if(i == n) {
      b = num;
    }
  }
  if(n == 1) {
    if(num == 0)
      printf("UP\n");
    else if(num == 15)
      printf("DOWN\n");
    else
      printf("-1\n");
  } else {
    if(b > a) {
      printf("%s\n", b == 15 ? "DOWN" : "UP");
    } else {
      printf("%s\n", b == 0 ? "UP" : "DOWN");
    }
  }
  return 0;
}
