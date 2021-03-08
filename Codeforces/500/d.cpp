#include <cstdio>
#include <set>

using namespace std;

const int maxn = 200000;
int fa[maxn*2+5];
int n, m;

int idx(int r, int c) {
  return r ? n + c : c;
}

int find_set(int a) {
  return fa[a] == a ? a : fa[a] = find_set(fa[a]);
}

void union_set(int a, int b) {
  fa[find_set(a)] = find_set(b);
}

int main() {
  int q;
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 1; i <= n + m; i++) {
    fa[i] = i;
  }
  while(q--) {
    int r, c;
    scanf("%d%d", &r, &c);
    union_set(idx(0, r), idx(1, c));
  }
  set<int> islands;
  for(int i = 1; i <= n + m; i++) {
    islands.insert(find_set(i));
  }
  printf("%d\n", islands.size() - 1);
  return 0;
}
