#include <cstdio>
#include <algorithm>
#define MAXN 300005

using namespace std;

int v[MAXN];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v, v+n);
  if(n == 1) {
    printf("%d\n", v[0]);
    return 0;
  }
  long long ans = 0;
  int mult = 2;
  for(int i = 0; i < n; i++) {
    ans += mult * 1LL * v[i];
    if(i != n - 2)
      mult++;
  }
  printf("%I64d\n", ans);
  return 0;
}
