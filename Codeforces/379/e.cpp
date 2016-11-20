#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int maxn = 200000;
int visited[maxn+5];
int color[maxn+5];
vector<int> adjList[maxn+5];
vector<int> adjList2[maxn+5];
int height[maxn+5];
int dp[maxn+5];
int n;

int diameter(int p, int f) {
  if(dp[p] != -1)
    return dp[p];
  int ans = 0;
  int h = 0;
  int h1 = 0, h2 = 0;
  for(int i = 0; i < adjList2[p].size(); i++) {
    int q = adjList2[p][i];
    if(q == f)
      continue;
    ans = max(ans, diameter(q, p));
    int hh = height[q] + 1;
    if(hh > h1) {
      h2 = h1;
      h1 = hh;
    } else if(hh > h2) {
      h2 = hh;
    }
    h = max(h, hh);
  }
  ans = max(ans, h1 + h2);
  height[p] = h;
  return dp[p] = ans;
}

void dfs_color() {
  memset(visited, -1, sizeof visited);
  int c = 0;
  stack<int> s;
  s.push(1);
  visited[1] = c++;
  while(!s.empty()) {
    int u = s.top();
    s.pop();
    for(int i = 0; i < adjList[u].size(); i++) {
      int v = adjList[u][i];
      if(visited[v] != -1)
	continue;
      if(color[v] == color[u]) {
	visited[v] = visited[u];
      } else {
	visited[v] = c;
	adjList2[visited[u]].push_back(c);
	adjList2[c].push_back(visited[u]);
	c++;
      }
      s.push(v);
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &color[i]);
  }
  int u, v;
  for(int i = 0; i < n - 1; i++) {
    scanf("%d%d", &u, &v);
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  dfs_color();
  memset(dp, -1, sizeof dp);
  printf("%d\n", (diameter(0, -1) + 1) >> 1);
  return 0;
}
