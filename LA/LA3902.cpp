#include <bits/stdc++.h>
#define MAXN 1005

using namespace std;

vector<int> adj[MAXN], nodes[MAXN];
int n, s, k, parent[MAXN];
bool covered[MAXN];

void dfs(int node, int p, int depth) {
  parent[node] = p;
  if(adj[node].size() == 1 && depth > k) {
    nodes[depth].push_back(node);
  }
  for(int i = 0; i < adj[node].size(); i++) {
    if(adj[node][i] != p) {
      dfs(adj[node][i], node, depth+1);
    }
  }
}

void addServer(int server, int p, int depth) {
  covered[server] = true;
  if(depth + 1 <= k) {
    for(int i = 0; i < adj[server].size(); i++) {
      if(adj[server][i] == p)
	continue;
      addServer(adj[server][i], server, depth+1);
    }
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d %d", &n, &s, &k);
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
      nodes[i].clear();
    }
    for(int i = 0; i < n-1; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    dfs(s, -1, 0);
    int ans = 0;
    memset(covered, false, sizeof covered);
    for(int i = n-1; i > k; i--) {
      for(int j = 0; j < nodes[i].size(); j++) {
	if(!covered[nodes[i][j]]) {
	  int repeat = k;
	  int server = nodes[i][j];
	  while(repeat--) {
	    server = parent[server];
	  }
	  ans++;
	  addServer(server, -1, 0);
	}
      }
    }
    printf("%d\n", ans);
    
  }
  return 0;
}
