#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1000;
vector<int> adjMat[maxn+5];
int n, m, k;
int v[maxn+5];
int s[maxn+5];
bool visited[maxn+5];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < k; i++)
    scanf("%d", &v[i]);
  for(int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adjMat[x].push_back(y);
    adjMat[y].push_back(x);
  }
  memset(visited, false, sizeof visited);
  int all = 0;
  for(int i = 0; i < k; i++) {
    int cnt = 1;
    queue<int> q;
    visited[v[i]] = true;
    q.push(v[i]);
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(int j = 0; j < adjMat[u].size(); j++) {
	int uu = adjMat[u][j];
	if(visited[uu])
	  continue;
	visited[uu] = true;
	q.push(uu);
	cnt++;
      }
    }
    s[i] = cnt;
    all += cnt;
  }
  sort(s, s + k);
  int total = 0;
  for(int i = 0; i < k; i++) {
    if(i == k - 1) {
      s[i] += n - all;
    }
    total += s[i] * (s[i] - 1) / 2;
  }
  printf("%d\n", total - m);
  return 0;
}
