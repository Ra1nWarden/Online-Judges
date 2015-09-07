#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <queue>
#define MAXN 1005

using namespace std;

set<int> adjList[MAXN];
int n;
int visited[MAXN];

bool dfs(int u) {
  if(visited[u] == n)
    return true;
  for(set<int>::iterator itr = adjList[u].begin(); itr != adjList[u].end(); itr++) {
    int v = *itr;
    if(visited[v] != 0)
      continue;
    visited[v] = visited[u] + 1;
    if(dfs(v))
      return true;
    visited[v] = 0;
  }
  return false;
}

bool checkConnected() {
  memset(visited, 0, sizeof visited);
  bool connected = true;
  bool start = false;
  for(int i = 1; i <= n; i++) {
    if(visited[i] == 0) {
      if(start) {
	connected = false;
	break;
      }
      start = true;
      queue<int> q;
      q.push(i);
      while(!q.empty()) {
	int u = q.front();
	q.pop();
	for(set<int>::iterator itr = adjList[u].begin(); itr != adjList[u].end(); itr++) {
	  int v = *itr;
	  if(visited[v] != 0)
	    continue;
	  visited[v] = 1;
	  q.push(v);
	}
      }
    }
  }
  return connected;
}

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 1; i <= n; i++) {
      adjList[i].clear();
    }
    for(int i = 0; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      if(a != b) {
	adjList[a].insert(b);
	adjList[b].insert(a);
      }
    }
    bool ans = true;
    if(checkConnected()) {
      int min_vertex = -1;
      int min_val = n + 1;
      for(int i = 1; i <= n; i++) {
	if(adjList[i].size() < min_val) {
	  min_val = adjList[i].size();
	  min_vertex = i;
	}
      }
      memset(visited, 0, sizeof visited);
      visited[min_vertex] = 1;
      ans = dfs(min_vertex);
    } else {
      ans = false;
    }
    if(ans)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
