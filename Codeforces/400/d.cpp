#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100000;
bool v[maxn+5];
int side[maxn+5][2];
int status[maxn+5];
vector<int> adjMat[maxn+5];
int n, m;

bool test(int node, int x) {
  memset(status, -1, sizeof status);
  status[node] = x;
  queue<int> q;
  q.push(node);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int i = 0; i < adjMat[u].size(); i++) {
      int uu = adjMat[u][i];
      int nu = side[uu][0] == u ? side[uu][1] : side[uu][0];
      int ans;
      if(v[uu]) {
	ans = status[u] ? 1 : 0; 
      } else {
	ans = status[u] ? 0 : 1;
      }
      if(status[nu] == -1) {
	status[nu] = ans;
	q.push(nu);
      } else if(ans != status[nu]) {
	return false;
      }
    }
  }
  return true;
}

void bfs(int node) {
  queue<int> q;
  q.push(node);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int i = 0; i < adjMat[u].size(); i++) {
      int uu = adjMat[u][i];
      int v = side[uu][0] == u ? side[uu][1] : side[uu][0];
      if(status[v])
	continue;
      q.push(v);
      status[v] = 1;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    v[i] = x == 1;
  }
  memset(side, -1, sizeof side);
  for(int i = 1; i <= m; i++) {
    int cnt;
    scanf("%d", &cnt);
    int x;
    for(int j = 0; j < cnt; j++) {
      scanf("%d", &x);
      if(side[x][0] == -1) {
	side[x][0] = i;
      } else {
	side[x][1] = i;
	adjMat[i].push_back(x);
	adjMat[side[x][0]].push_back(x);
      }
    }
  }
  memset(status, 0, sizeof status);
  vector<int> parts;
  for(int i = 1; i <= m; i++) {
    if(status[i])
      continue;
    parts.push_back(i);
    bfs(i);
  }
  bool ans = true;
  for(int i = 0; i < parts.size(); i++) {
    int node = parts[i];
    if(test(node, 0) || test(node, 1)) {
      continue;
    } else {
      ans = false;
      break;
    }
  }
  printf("%s\n", ans ? "YES" : "NO");
  return 0;
}
