#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

const int maxn = 200000; // use as max val as well
int cv[maxn+5];
int av[maxn+5];
int vis[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &cv[i]);
  for(int i = 1; i <= n; i++)
    scanf("%d", &av[i]);
  
  memset(vis, 0, sizeof vis);

  vector<vector<int> > cycles;

  int counter = 0;
  for(int i = 1; i <= n; i++) {
    if(vis[i])
      continue;
    ++counter;
    int u = i;
    vis[u] = counter;
    while(true) {
      int v = av[u];
      if(vis[v]) {
	if(vis[v] != counter)
	  break;
	vector<int> cycle;
	int cur = v;
	cycle.push_back(cur);
	while(cycle[0] != av[cur]) {
	  cur = av[cur];
	  cycle.push_back(cur);
	}
	cycles.push_back(cycle);
	break;
      }
      vis[v] = counter;
      u = v;
    }
  }

  memset(vis, 0, sizeof vis);

  int ans = 0;
  
  for(int i = 0; i < cycles.size(); i++) {
    int min_cost = maxn;
    for(int j = 0; j < cycles[i].size(); j++) {
      min_cost = min(min_cost, cv[cycles[i][j]]);
      vis[cycles[i][j]] = 1;
    }
    ans += min_cost;
  }

  printf("%d\n", ans);
  return 0;
}
