#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int maxn = 100000;
vector<int> adjMat[maxn+5];
bool vis[maxn+5];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      adjMat[i].clear();
    int m;
    scanf("%d", &m);
    while(m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      adjMat[u].push_back(v);
      adjMat[v].push_back(u);
    }
    int ans = 0;
    memset(vis, false, sizeof vis);
    for(int i = 0; i < n; i++) {
      if(vis[i])
	continue;
      ans++;
      vis[i] = true;
      stack<int> s;
      s.push(i);
      while(!s.empty()) {
	int u = s.top();
	s.pop();
	for(int j = 0; j < adjMat[u].size(); j++) {
	  int v = adjMat[u][j];
	  if(vis[v])
	    continue;
	  vis[v] = true;
	  s.push(v);
	}
      }
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
