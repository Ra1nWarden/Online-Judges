#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000;
const int maxm = 300000;

struct Edge {
  int a, b, c;
  bool operator<(const Edge& rhs) const {
    return c < rhs.c;
  }
};

Edge edges[maxm+5];
int parent[maxn+5];
int p, n, m;

void init() {
  for(int i = 1; i <= n; i++)
    parent[i] = i;
}

int find_set(int a) {
  return parent[a] == a ? a : parent[a] = find_set(parent[a]);
}

void union_set(int a, int b) {
  parent[find_set(a)] = find_set(b);
}

bool same_set(int a, int b) {
  return find_set(a) == find_set(b);
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d%d%d", &p, &n, &m);
    for(int i = 0; i < m; i++) {
      scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].c);
    }
    sort(edges, edges + m);
    init();
    int added = 0;
    int ans = 0;
    for(int i = 0; i < m && added < n - 1; i++) {
      const Edge& edge = edges[i];
      if(same_set(edges[i].a, edges[i].b)) {
	continue;
      }
      added++;
      ans += edges[i].c;
      union_set(edges[i].a, edges[i].b);
    }
    printf("%d\n", ans * p);
  }
  return 0;
}
