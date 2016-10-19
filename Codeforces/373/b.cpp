#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int n;
char str[maxn+5];

int main() {
  scanf("%d\n", &n);
  scanf("%s", str);
  int ans = n;
  int x = 0, y = 0;
  for(int i = 0; i < n; i+=2) {
    if(str[i] != 'b') {
      x++;
    }
  }
  for(int i = 1; i < n; i+=2) {
    if(str[i] != 'r') {
      y++;
    }
  }
  ans = min(ans, max(x, y));
  x = y = 0;
  for(int i = 0; i < n; i+=2) {
    if(str[i] != 'r') {
      x++;
    }
  }
  for(int i = 1; i < n; i+=2) {
    if(str[i] != 'b') {
      y++;
    }
  }
  ans = min(ans, max(x, y));
  printf("%d\n", ans);
  return 0;
}
