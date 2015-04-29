#include <cstdio>
#include <algorithm>
#define MAXN 10005
#define INF 2000000000

using namespace std;

int pos[MAXN];
int v[MAXN];

int main() {
  int n;
  while(scanf("%d", &n) != EOF) {
    memset(pos, 0, sizeof pos);
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      pos[v[i]] = i;
    }
    int ans = 0;
    for(int i = 1; i < n; i++) {
      int num = v[i];
      int mult = 2;
      int added = INF;
      while(num * mult <= 10000) {
	if(pos[num * mult] != 0 && pos[num * mult] > i) {
	  added = min(added, pos[num * mult]);
	}
	mult++;
      }
      if(added != INF) {
	ans += added;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
