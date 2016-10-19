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
struct Node {
  int i;
  long long s, m;
};

int f(int num) {
  int ans = 1;
  visited[num] = true;
  for(int i = 0; i < adjMat[num].size(); i++) {
    Edge& e = edges[adjMat[num][i]];
    int child = e.s == num ? e.t : e.s;
    if(visited[child])
      continue;
    ans += f(child);
  }
  return sizes[num] = ans;
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
  f(1);
  memset(visited, false, sizeof visited);
  queue<Node> q;
  visited[1] = true;
  Node start = Node{1, 0LL, 0LL};
  q.push(start);
  int ans = 0;
  while(!q.empty()) {
    Node u = q.front();
    q.pop();
    if(u.s - u.m > v[u.i]) {
      ans += sizes[u.i];
      continue;
    }
    for(int i = 0; i < adjMat[u.i].size(); i++) {
      Edge& e = edges[adjMat[u.i][i]];
      int t = e.s == u.i ? e.t : e.s;
      if(visited[t])
	continue;
      visited[t] = true;
      q.push(Node{t, u.s + e.v, min(u.m, u.s + e.v)});
    }
  }
  printf("%d\n", ans);
  return 0;
}
