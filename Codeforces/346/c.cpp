#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int ans[maxn+5];
int n, m, ai;

int main() {
  scanf("%d%d", &n,&m);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v, v+n);
  int vi = 0;
  ai = 0;
  for(int i = 1; i <= 1000000000; i++) {
    if(v[vi] == i) {
      vi++;
      continue;
    }
    if(m < i) {
      break;
    }
    ans[ai++] = i;
    m -= i;
  }
  printf("%d\n", ai);
  for(int i = 0; i < ai; i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
