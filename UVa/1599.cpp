#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 100005
#define INF 2000000000

using namespace std;


struct Edge {
  int u, v, c;
  Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};

int n, m;
int min_dist[MAXN];
bool visited[MAXN];

vector<Edge> edges;
vector<int> graph[MAXN];

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    edges.clear();
    for(int i = 1; i <= n; i++)
      graph[i].clear();
    for(int i = 0; i < m; i++) {
      int x, y, d;
      scanf("%d %d %d", &x, &y, &d);
      edges.push_back(Edge(x, y, d));
      graph[x].push_back(edges.size() - 1);
      edges.push_back(Edge(y, x, d));
      graph[y].push_back(edges.size() - 1);
    }
    memset(visited, false, sizeof visited);
    queue<int> q;
    q.push(n);
    visited[n] = true;
    min_dist[n] = 0;
    while(!q.empty()) {
      int next = q.front();
      q.pop();
      for(int i = 0; i < graph[next].size(); i++) {
	int e = graph[next][i];
	int v = edges[e].v;
	if(!visited[v]) {
	  min_dist[v] = min_dist[next] + 1;
	  visited[v] = true;
	  q.push(v);
	}
      }
    }
    vector<int> ans;
    memset(visited, false, sizeof visited);
    vector<int> next_nodes;
    next_nodes.push_back(1);
    visited[1] = true;
    for(int i = 0; i < min_dist[1]; i++) {
      int min_color = INF;
      for(int j = 0; j < next_nodes.size(); j++) {
	int u = next_nodes[j];
	for(int k = 0; k < graph[u].size(); k++) {
	  int e = graph[u][k];
	  int v = edges[e].v;
	  int color = edges[e].c;
	  if(min_dist[v] == min_dist[u] - 1) {
	    min_color = min(min_color, color);
	  }
	}
      }
      ans.push_back(min_color);

      vector<int> next_v;
      for(int j = 0; j < next_nodes.size(); j++) {
	int u = next_nodes[j];
	for(int k = 0; k < graph[u].size(); k++) {
	  int e = graph[u][k];
	  int v = edges[e].v;
	  int color = edges[e].c;
	  if(min_dist[v] == min_dist[u] - 1 && !visited[v] && color == min_color) {
	    visited[v] = true;
	    next_v.push_back(v);
	  }
	}
      }
      next_nodes = next_v;
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
      if(i > 0)
	printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
