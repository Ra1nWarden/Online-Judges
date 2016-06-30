#include <cstdio>
#include <algorithm>
#define MAXN 100005

using namespace std;

int n;
int v[MAXN];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int ans = 0;
  int cur = 1;
  for(int i = 1; i < n; i++) {
    if(v[i] >= v[i-1])
      cur++;
    else {
      ans = max(ans, cur);
      cur = 1;
    }
  }
  ans = max(ans, cur);
  printf("%d\n", ans);
  return 0;
}
