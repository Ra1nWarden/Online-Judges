#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#define MAXN 10005

using namespace std;

int color[MAXN];
vector<int> adjMat[MAXN];
int n, m, c;
bool used[MAXN];

int main() {
  bool init = true;
  while(scanf("%d %d", &n, &m) != EOF) {
    if(!init)
      printf("\n");
    memset(color, 0, sizeof color);
    for(int i = 1; i <= n; i++) {
      adjMat[i].clear();
    }
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      adjMat[a].push_back(b);
      adjMat[b].push_back(a);
    }
    c = 0;
    for(int i = 1; i <= n; i++)
      c = max(c, (int) adjMat[i].size());
    if(c % 2 == 0)
      c++;
    color[1] = 1;
    stack<int> s;
    s.push(1);
    while(!s.empty()) {
      int u = s.top();
      s.pop();
      for(int i = 0; i < adjMat[u].size(); i++) {
	int v = adjMat[u][i];
	if(!color[v]) {
	  memset(used, false, sizeof used);
	  for(int j = 0; j < adjMat[v].size(); j++) {
	    if(color[adjMat[v][j]] != 0)
	      used[color[adjMat[v][j]]] = true;
	  }
	  for(int j = 1; j <= c; j++) {
	    if(!used[j]) {
	      color[v] = j;
	      s.push(v);
	      break;
	    }
	  }
	}
      }
    }
    printf("%d\n", c);
    for(int i = 1; i <= n; i++)
      printf("%d\n", color[i]);
    init = false;
  }
  return 0;
}
