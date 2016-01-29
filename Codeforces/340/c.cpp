#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2000;
typedef long long LL;
struct Node {
  LL d1, d2;
  int idx;
  Node() {}
  Node(LL a, LL b) : d1(a), d2(b) {}
};
Node nodes[maxn+1];
bool check[maxn+1];
LL v[maxn+1];
int n;
int x1, y1, x2, y2;

bool cmp1(const Node& a, const Node& b) {
  if(a.d1 != b.d1)
    return a.d1 < b.d1;
  return a.d2 < b.d2;
}

bool cmp2(const Node& a, const Node& b) {
  if(a.d2 != b.d2)
    return a.d2 > b.d2;
  return a.d1 > b.d1;
}

int main() {
  scanf("%d", &n);
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  for(int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    nodes[i] = Node((x - x1) * 1LL * (x - x1) + (y - y1) * 1LL * (y - y1), (x - x2) * 1LL * (x - x2) + (y - y2) * 1LL * (y - y2));
  }
  sort(nodes, nodes + n, cmp2);
  for(int i = 0; i < n; i++) {
    nodes[i].idx = i;
    v[i] = nodes[i].d2;
  }
  sort(nodes, nodes + n, cmp1);
  memset(check, true, sizeof check);
  LL ans = v[0];
  int low_idx = 0;
  for(int i = 0; i < n; i++) {
    check[nodes[i].idx] = false;
    if(i + 1 < n && nodes[i+1].d1 == nodes[i].d1)
      continue;
    while(!check[low_idx])
      low_idx++;
    LL cur = nodes[i].d1 + v[low_idx];
    ans = min(ans, cur);
  }
  printf("%I64d\n", ans);
  return 0;
}
