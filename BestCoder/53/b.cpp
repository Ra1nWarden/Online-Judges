#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
#define MAXN 1005

using namespace std;

vector<int> adjMat[MAXN];
int n;
int dist[MAXN];
int count[MAXN];

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 1; i <= n; i++) {
      adjMat[i].clear();
    }
    for(int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      adjMat[a].push_back(b);
      adjMat[b].push_back(a);
    }
    memset(dist, -1, sizeof dist);
    memset(count, 0, sizeof count);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(int i = 0; i < adjMat[u].size(); i++) {
	int v = adjMat[u][i];
	if(dist[v] != -1)
	  continue;
	dist[v] = dist[u] + 1;
	count[dist[v]]++;
	q.push(v);
      }
    }
    bool ok = true;
    for(int i = 1; i < n; i++) {
      if(count[i] > 0 && count[i-1] > 1) {
	ok = false;
	break;
      }
    }
    if(ok)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
