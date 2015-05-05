#include <cstdio>
#define MAXN 100005

using namespace std;

int cost[MAXN];
int p[MAXN];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  int kase = 1;
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &p[i]);
    }
    for(int i = 0; i < n; i++) {
      scanf("%d", &cost[i]);
    }
    int ans = -1;
    for(int i = 0; i < n; i++) {
      int oil = 0;
      bool ok = true;
      for(int j = i; j < i + n; j++) {
	oil += p[j%n];
	oil -= cost[j%n];
	if(oil < 0) {
	  ok = false;
	  i = j;
	  break;
	}
      }
      if(ok) {
	ans = i + 1;
	break;
      }
    }
    if(ans == -1)
      printf("Case %d: Not possible\n", kase++);
    else
      printf("Case %d: Possible from station %d\n", kase++, ans);
  }
  return 0;
}
