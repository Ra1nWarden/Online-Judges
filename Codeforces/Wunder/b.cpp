#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 50;
int v[maxn+1][maxn+1];
int ans[maxn+1];
bool vis[maxn+1];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  memset(ans, -1, sizeof ans);
  memset(vis, false, sizeof vis);
  for(int target = 1; target <= n; target++) {
    for(int i = 0; i < n; i++) {
      if(vis[i])
	continue;
      bool ok = true;
      for(int j = 0; j < n && ok; j++) {
	if(i == j)
	  continue;
	if(vis[j])
	  continue;
	if(v[i][j] != target) {
	  ok = false;
	}
      }
      if(ok) {
	ans[i] = target;
	vis[i] = true;
	break;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
