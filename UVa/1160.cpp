#include <cstdio>

using namespace std;

const int maxn = 100000;
int fa[maxn+5];

int find_set(int u) {
  return u == fa[u] ? u : fa[u] = find_set(fa[u]);
}

void union_set(int u, int v) {
  fa[find_set(u)] = find_set(v);
}

bool same_set(int u, int v) {
  return find_set(u) == find_set(v);
}

void init() {
  for(int i = 1; i <= maxn; i++)
    fa[i] = i;
}

int main() {
  int a, b;
  while(true) {
    init();
    bool end = true;
    int ans = 0;
    while(scanf("%d", &a) != EOF) {
      end = false;
      if(a == -1)
	break;
      scanf("%d", &b);
      if(same_set(a, b))
	ans++;
      else
	union_set(a, b);
    }
    if(end)
      break;
    else
      printf("%d\n", ans);
  }
  return 0;
}
