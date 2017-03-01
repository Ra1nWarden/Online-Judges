#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

typedef pair<long long, long long> Pos;

const int maxn = 30;
vector<int> adjMat[maxn+5];
int depth[maxn+5];
Pos points[maxn+5];
int n;
int parent[maxn+5];

long long len(int d) {
  return 1LL << (n + 1 - d);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adjMat[a].push_back(b);
    adjMat[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) {
    if(adjMat[i].size() > 4) {
      printf("NO\n");
      return 0;
    }
  }
  set<Pos> vis;
  points[1] = make_pair(0, 0);
  vis.insert(points[1]);
  memset(depth, -1, sizeof depth);
  memset(parent, -1, sizeof parent);
  depth[1] = 0;
  queue<int> q;
  q.push(1);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int i = 0; i < adjMat[u].size(); i++) {
      int v = adjMat[u][i];
      if(depth[v] != -1)
	continue;
      q.push(v);
      depth[v] = depth[u] + 1;
      long long l = len(depth[u]);
      Pos top = make_pair(points[u].first, points[u].second + l);
      Pos btm = make_pair(points[u].first, points[u].second - l);
      Pos right = make_pair(points[u].first + l, points[u].second);
      Pos left = make_pair(points[u].first - l, points[u].second);
      if(parent[u] != 0 && !vis.count(top)) {
	vis.insert(top);
	points[v] = top;
	parent[v] = 1;
	continue;
      } else if(parent[u] != 1 && !vis.count(btm)) {
	vis.insert(btm);
	points[v] = btm;
	parent[v] = 0;
	continue;
      } else if(parent[u] != 2 && !vis.count(right)) {
	vis.insert(right);
	points[v] = right;
	parent[v] = 3;
	continue;
      } else if(parent[u] != 3 && !vis.count(left)) {
	vis.insert(left);
	points[v] = left;
	parent[v] = 2;
	continue;
      }
    }
  }
  printf("YES\n");
  for(int i = 1; i <= n; i++) {
    printf("%I64d %I64d\n", points[i].first, points[i].second);
  }
  return 0;
}
