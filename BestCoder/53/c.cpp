#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 1005

using namespace std;

int visited[MAXN];
vector<int> adjList[MAXN];
int n;

bool dfs(int u) {
  if(visited[u] == n)
    return true;
  for(int i = 0; i < adjList[u].size(); i++) {
    int v = adjList[u][i];
    if(visited[v] != 0)
      continue;
    visited[v] = visited[u] + 1;
    if(dfs(v))
      return true;
    visited[v] = 0;
  }
  return false;
}

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 1; i <= n; i++)
      adjList[i].clear();
    for(int i = 1; i <= n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }
    bool found = false;
    for(int i = 1; i <= n; i++) {
      memset(visited, 0, sizeof visited);
      visited[i] = 1;
      if(dfs(i)) {
	found = true;
	break;
      }
    }
    if(found)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
