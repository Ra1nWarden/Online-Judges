#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 2000;
int vis[maxn+5];
int n, m;
vector<int> mat[maxn+5];

bool dfs(int u) {
  int color = 0;
  stack<int> s;
  s.push(u);
  vis[u] = color;
  while(!s.empty()) {
    int p = s.top();
    s.pop();
    for(int i = 0; i < mat[p].size(); i++) {
      int q = mat[p][i];
      if(vis[q] == -1) {
	vis[q] = vis[p] ^ 1;
	s.push(q);
      } else if(vis[q] != (vis[p] ^ 1)) {
	return false;
      }
    }
  }
  return true;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    memset(vis, -1, sizeof vis);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
      mat[i].clear();
    }
    int u, v;
    for(int i = 0; i < m; i++) {
      scanf("%d%d", &u, &v);
      mat[u].push_back(v);
      mat[v].push_back(u);
    }
    bool ok = true;
    for(int i = 1; i <= n; i++) {
      if(vis[i] == -1) {
	if(!dfs(i)) {
	  ok = false;
	  break;
	}
      }
    }
    printf("Scenario #%d:\n", kase);
    if(ok) {
      printf("No suspicious bugs found!\n");
    } else {
      printf("Suspicious bugs found!\n");
    }
  }
  return 0;
}
