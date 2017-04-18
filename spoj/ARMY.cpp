#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

int n, m;
typedef pair<int, int> Node;
priority_queue<Node, vector<Node>, greater<Node> > pq;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &n, &m);
    int x = -1, y = -1;
    int z;
    for(int i = 0; i < n; i++) {
      scanf("%d", &z);
      x = max(x, z);
    }
    for(int i = 0; i < m; i++) {
      scanf("%d", &z);
      y = max(y, z);
    }
    printf("%s\n", x < y ?  "MechaGodzilla" : "Godzilla");
  }
  return 0;
}
