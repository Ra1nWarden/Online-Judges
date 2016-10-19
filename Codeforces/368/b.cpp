#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Edge {
  int u, v, l;
  bool operator<(const Edge& other) const {
    return l > other.l;
  }
};

const int maxn = 100000;
bool storage[maxn+5];
int n, m, k;

int main() {
  scanf("%d%d%d", &n, &m, &k);
  memset(storage, false, sizeof storage);
  priority_queue<Edge> pq;
  for(int i = 0; i < m; i++) {
    int u, v, l;
    scanf("%d%d%d", &u, &v, &l);
    pq.push(Edge{u, v, l});
  }
  for(int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    storage[x] = true;
  }
  int ans = -1;
  while(!pq.empty()) {
    Edge u = pq.top();
    pq.pop();
    int cnt = storage[u.u] ? 1 : 0;
    cnt += storage[u.v] ? 1 : 0;
    if(cnt == 1) {
      ans = u.l;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
