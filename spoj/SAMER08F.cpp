#include <cstdio>

using namespace std;

const int maxn = 100;
int ans[maxn+5];

int main() {
  ans[0] = 0;
  for(int i = 1; i <= maxn; i++) {
    ans[i] = ans[i-1] + i * i;
  }
  int x;
  while(scanf("%d", &x)) {
    if(x == 0)
      break;
    printf("%d\n", ans[x]);
  }
  return 0;
}
