#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 200000;
vector<int> adjList[maxn+5];
int v[maxn+5];
bool visited[maxn+5];
int n, m, k;

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  for(int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }
  int ans = 0;
  memset(visited, false, sizeof visited);
  for(int i = 1; i <= n; i++) {
    if(visited[i])
      continue;
    queue<int> q;
    map<int, int> cnt;
    q.push(i);
    visited[i] = true;
    cnt[v[i]] = 1;
    int maxval = 1;
    int total = 0;
    while(!q.empty()) {
      int u = q.front();
      total++;
      q.pop();
      for(int j = 0; j < adjList[u].size(); j++) {
	int uu = adjList[u][j];
	if(visited[uu])
	  continue;
	if(cnt.count(v[uu]))
	  cnt[v[uu]] = cnt[v[uu]] + 1;
	else
	  cnt[v[uu]] = 1;
	maxval = max(maxval, cnt[v[uu]]);
	visited[uu] = true;
	q.push(uu);
      }
    }
    ans += total - maxval;
  }
  printf("%d\n", ans);
  return 0;
}
