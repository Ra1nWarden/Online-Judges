#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 400;
bool road[maxn+5][maxn+5];
int vis[maxn+5];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  memset(road, false, sizeof road);
  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    road[u][v] = road[v][u] = true;
  }
  memset(vis, -1, sizeof vis);
  vis[1] = 0;
  queue<int> q;
  q.push(1);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v = 1; v <= n; v++) {
      if(road[u][v] && vis[v] == -1) {
	vis[v] = vis[u] + 1;
	q.push(v);
      }
    }
  }
  int train = vis[n];
  memset(vis, -1, sizeof vis);
  vis[1] = 0;
  q.push(1);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v = 1; v <= n; v++) {
      if(!road[u][v] && vis[v] == -1) {
	vis[v] = vis[u] + 1;
	q.push(v);
      }
    }
  }
  int car = vis[n];
  if(train == -1 || car == -1)
    printf("-1\n");
  else
    printf("%d\n", max(train, car));
  return 0;
}
