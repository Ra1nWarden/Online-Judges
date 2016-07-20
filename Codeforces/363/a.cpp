#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000;
char str[maxn+5];
int v[maxn+5];
int n;
const int inf = 2000000000;

int main() {
  scanf("%d\n", &n);
  scanf("%s\n", str);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int ans = inf;
  for(int i = 0; i < n - 1; i++) {
    if(str[i] == 'R' && str[i+1] == 'L') {
      ans = min(ans, (v[i+1] - v[i]) / 2);
    }
  }
  printf("%d\n", ans == inf ? -1 : ans);
  return 0;
}
