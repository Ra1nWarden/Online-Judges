#include <cstring>
#include <cstdio>
#include <vector>
#define MAXN 100005

using namespace std;

map<int, vector<int> > adjList;
int vis[MAXN];
map<int, int> cm;
typedef pair<int, int> QueueNode;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> dummy;
  for(int i = 1; i <= n; i++) {
    if(adjList.count(i))
      adjList[i].clear();
    else
      adjList[i] = dummy;
  }
  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  int ans = 3;
  memset(vis, -1, sizeof vis);
  for(int i = 1; i <= n; i++) {
    if(vis[i] != -1)
      continue;
    queue<int> q;
    q.push(make_pair(i, 0));
    vis[i] = 0;
    cm.clear();
    cm[0] = 1;
    int max_cnt = 0;
    while(q.empty()) {
      int uu = q.front().first;
      int dis = q.front().second;
      q.pop();
      for(int j = 0; j < adjList[uu].size(); j++) {
	int vv = adjList[vv];
	q.push(make_pair(vv, dis+1));
	if(cm.count(dis+1)) {
	  cm[dis+1] = cm[dis+1] + 1;
	} else {
	  cm[dis+1] = 1;
	}
	max_cnt = max(max_cnt, dis+1);
      }
    }
    for(int d = 0; d <= max_cnt; d++) {
      
    }
  }
  return 0;
}
