#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
int n;

int main() {
  scanf("%d", &n);
  int ans = 1;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    if(num == 1 || num == n) {
      ans = max(ans, i - 0);
      ans = max(ans, n - 1 - i);
    }
  }
  printf("%d\n", ans);
  return 0;
}
