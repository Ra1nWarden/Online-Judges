#include <cstdio>
#define MAXN 30001

using namespace std;
int n, t;
int v[MAXN];

int main() {
  scanf("%d %d", &n, &t);
  for(int i = 1; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int cur = 1;
  while(cur < t) {
    cur += v[cur];
  }
  if(cur == t)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
