#include <cstdio>

using namespace std;

const int maxn = 200;
char str[maxn+5];
int n;

bool ok(int a, int b) {
  int x = 0, y = 0;
  for(int i = a; i <= b; i++) {
    if(str[i] == 'U') {
      x--;
    } else if(str[i] == 'D') {
      x++;
    } else if(str[i] == 'L') {
      y--;
    } else if(str[i] == 'R') {
      y++;
    }
  }
  return x == 0 && y == 0;
}

int main() {
  scanf("%d\n%s", &n, str);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(ok(i, j))
	ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
