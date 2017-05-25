#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 10000;
vector<int> adjMat[maxn+5];
int depth[maxn+5];
bool visited[maxn+5];
int n;

int dfs(int r) {
  visited[r] = true;
  int ans = 0;
  int a = -1, b = -1;
  for(int i = 0; i < adjMat[r].size(); i++) {
    int v = adjMat[r][i];
    if(visited[v])
      continue;
    ans = max(ans, dfs(v));
    int d = depth[v];
    if(d > a) {
      b = a;
      a = d;
    } else if(d > b) {
      b = d;
    }
  }
  depth[r] = max(a, b) + 1;
  ans = max(ans, a + b + 2);
  return ans;
}

int main() {
  scanf("%d", &n);
  memset(visited, false, sizeof visited);
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adjMat[u].push_back(v);
    adjMat[v].push_back(u);
  }
  printf("%d\n", dfs(1));
  return 0;
}
