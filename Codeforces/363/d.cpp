#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200000;
int n;
int p[maxn+5];
int color[maxn+5];
int cut[maxn+5];
int root;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  root = -1;
  memset(color, -1, sizeof color);
  memset(cut, -1, sizeof cut);
  int c = 0;
  for(int i = 1; i <= n; i++) {
    if(color[i] == -1) {
      int cur = i;
      while(true) {
	color[cur] = c;
	if(cur == p[cur]) {
	  if(root == -1)
	    root = cur;
	  break;
	} else if(color[p[cur]] != -1) {
	  break;
	}
	cur = p[cur];
      }
      cut[c++] = cur;
    }
  }
  int ans = 0;
  for(int i = 0; i < c; i++) {
    if(color[cut[i]] != color[p[cut[i]]])
      continue;
    if(root == -1) {
      root = cut[i];
      p[root] = root;
      ans++;
    } else if(p[cut[i]] != root) {
      p[cut[i]] = root;
      ans++;
    }
  }
  printf("%d\n", ans);
  for(int i = 1; i <= n; i++) {
    if(i > 1)
      printf(" ");
    printf("%d", p[i]);
  }
  printf("\n");
  return 0;
}
