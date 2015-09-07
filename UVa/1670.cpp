#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#define MAXN 100010

using namespace std;

vector<int> adjList[MAXN];
int n, root;
vector<int> leaves;
bool visited[MAXN];

int main() {
  while(~scanf("%d", &n)) {
    for(int i = 1; i <= n; i++)
      adjList[i].clear();
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    for(root = 1; root <= n; root++) {
      if(adjList[root].size() > 1) {
	break;
      }
    }
    leaves.clear();
    memset(visited, false, sizeof visited);
    stack<int> s;
    s.push(root);
    visited[root] = true;
    while(!s.empty()) {
      int u = s.top();
      s.pop();
      bool children = false;
      for(int i = 0; i < adjList[u].size(); i++) {
	int v  = adjList[u][i];
	if(visited[v])
	  continue;
	children = true;
	visited[v] = true;
	s.push(v);
      }
      if(!children) {
	leaves.push_back(u);
      }
    }
    int offset = leaves.size() / 2;
    printf("%d\n", (leaves.size() + 1) / 2);
    for(int i = 0; i < leaves.size() / 2; i++) {
      printf("%d %d\n", leaves[i], leaves[i + offset]);
    }
    if(leaves.size() % 2)
      printf("%d %d\n", leaves[leaves.size() - 1 - offset], leaves[leaves.size() - 1]);
  }
  return 0;
}
