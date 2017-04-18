#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int v[maxn+5];
int x, n;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d %d", &x, &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    sort(v, v+n);
    int i;
    for(i = n-1; i >= 0; i--) {
      x -= v[i];
      if(x <= 0)
	break;
    }
    if(x <= 0)
      printf("Scenario #%d:\n%d\n\n", kase, n - i);
    else
      printf("Scenario #%d:\nimpossible\n\n", kase);
  }
  return 0;
}
