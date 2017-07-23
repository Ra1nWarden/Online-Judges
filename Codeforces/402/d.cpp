#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 200000;
char t[maxl+5];
char p[maxl+5];
int n;
int v[maxl+5];
bool vis[maxl+5];

int main() {
  scanf("%s\n", t);
  scanf("%s\n", p);
  int idx;
  n = strlen(t);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int l = 0, r = n;
  while(l != r) {
    memset(vis, false, sizeof vis);
    int m = ((l + r) >> 1) + 1;
    int ti = 0, pi = 0;
    for(int i = 0; i < m; i++) {
      vis[v[i] - 1] = true;
    }
    while(p[pi] != '\0' && ti < n) {
      if(!vis[ti] && p[pi] == t[ti]) {
	pi++;
      }
      ti++;
    }
    if(p[pi] != '\0') {
      r = m - 1;
    } else {
      l = m;
    }
  }
  printf("%d\n", l);
  return 0;
}
