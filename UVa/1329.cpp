#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 20000;
int p[maxn+5], d[maxn+5];
int n;
char line[5];

int find_set(int u) {
  if(p[u] == u)
    return p[u];
  else {
    int v = find_set(p[u]);
    d[u] += d[p[u]];
    return p[u] = v;
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d\n", &n);
    for(int i = 1; i <= n; i++) {
      p[i] = i;
      d[i] = 0;
    }
    while(scanf("%s", line) != EOF) {
      if(line[0] == 'O')
	break;
      if(line[0] == 'E') {
	int u;
	scanf("%d", &u);
	find_set(u);
	printf("%d\n", d[u]);
      }
      if(line[0] == 'I') {
	int u, v;
	scanf("%d%d", &u, &v);
	p[u] = v;
	d[u] += abs(u - v) % 1000;
      }
    }
  }
  return 0;
}
