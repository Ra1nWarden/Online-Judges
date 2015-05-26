#include <cstdio>
#include <algorithm>
#define MAXN 100005

using namespace std;

int v[MAXN];
int n, l;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    sort(v, v+n);
    int ans = 0;
    int ai = 0, bi = n - 1;
    while(ai <= bi) {
      if(v[ai] + v[bi] <= l) {
	ai++;
	bi--;
      } else {
	bi--;
      }
      ans++;
    }
    printf("%d\n", ans);
    if(tc)
      printf("\n");
  }
  return 0;
}
