#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100000;
struct Edge {
  int s, t, v;
};
vector<Edge> edges;
vector<int> adjMat[maxn+5];
int n;
int v[maxn+5];
bool visited[maxn+5];
int sizes[maxn+5];

int f(int num) {
  int ans = 1;
  for(int i = 0; i < adjMat[num].size(); i++) {
    Edge& e = edges[i];
    int child = e.s == num ? e.t : e.s;
    if(visited[child])
      continue;
    ans += f(child);
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  for(int i = 1; i < n; i++) {
    int t, e;
    scanf("%d%d", &t, &e);
    int ei = edges.size();
    Edge edge{i+1, t, e};
    adjMat[i+1].push_back(ei);
    adjMat[t].push_back(ei);
    edges.push_back(edge);
  }
  memset(visited, false, sizeof visited);
  sizes[1] = f(1);
  memset(visited, false, sizeof visited);
  typedef pair<int, int> Node;
  queue<Node> q;
  visited[1] = true;
  Node start = make_pair(1, 0);
  q.push(start);
  int ans = 0;
  while(!q.empty()) {
    Node u = q.front();
    q.pop();
    for(int i = 0; i < adjMat[u.first].size(); i++) {
      Edge& e = edges[i];
      int t = e.s == u.first ? e.t : e.s;
      if(u.second + e.v > v[t]) {
	ans += sizes[t];
      } else {
	visited[t] = true;
	q.push(make_pair(t, u.second + e.v));
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
