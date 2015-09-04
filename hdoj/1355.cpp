#include <cstdio>
#include <algorithm>
#define MAXN 2510

using namespace std;

struct Node {
  int x, y, num;
  bool operator<(const Node& rhs) const {
    return num > rhs.num;
  }
};

Node nodes[MAXN];
int m, n, k;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d%d", &m, &n, &k);
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
	int idx = i * n + j;
	nodes[idx].x = i;
	nodes[idx].y = j;
	scanf("%d", &nodes[idx].num);
      }
    }
    sort(nodes, nodes + (m * n));
    k -= 2;
    int ans = 0;
    int prev_x, prev_y;
    for(int i = 0; i < m * n; i++) {
      if(i == 0) {
	k -= (nodes[i].x + 1);
      } else {
	k -= (abs(nodes[i].x - prev_x) + abs(nodes[i].y - prev_y) + 1);
      }
      prev_x = nodes[i].x;
      prev_y = nodes[i].y;
      if(k >= prev_x) {
	ans += nodes[i].num;
      } else {
	break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
