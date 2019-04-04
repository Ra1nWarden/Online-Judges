#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 200000;
int v[maxn+5], ans[maxn+5];
bool vis[maxn+5];
int n;
vector<int> adjMat[maxn+5];

int mod(int a, int b) {
  if(b == 0)
    return a;
  return mod(b, a % b);
}

void zero_root(int u) {
  vis[u] = true;
  for(int i = 0; i < adjMat[u].size(); i++) {
    int uu = adjMat[u][i];
    if(vis[uu])
      continue;
    ans[uu] = mod(ans[u], v[uu]);
    zero_root(uu);
  }
}

void non_zero_root(int u, int d, vector<int>& div, vector<int>& count) {
  vis[u] = true;
  for(int i = 0; i < div.size(); i++) {
    count[i] += (v[u] % div[i] == 0);
    if(count[i] >= d - 1) {
      ans[u] = max(ans[u], div[i]);
    }
  }
  for(int i = 0; i < adjMat[u].size(); i++) {
    int uu = adjMat[u][i];
    if(vis[uu])
      continue;
    non_zero_root(uu, d+1, div, count);
  }
  for(int i = 0; i < div.size(); i++)
    count[i] -= (v[u] % div[i] == 0);
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  int x, y;
  for(int i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    adjMat[x].push_back(y);
    adjMat[y].push_back(x);
  }
  memset(ans, 0, sizeof ans);
  memset(vis, false, sizeof vis);
  zero_root(1);
  vector<int> div;
  for(int i = 1; i * i <= v[1]; i++) {
    if(v[1] % i == 0) {
      div.push_back(i);
      if(i != v[1] / i)
	div.push_back(v[1] / i);
    }
  }
  vector<int> count(div.size(), 0);
  memset(vis, false, sizeof vis);
  non_zero_root(1, 1, div, count);
  for(int i = 1; i <= n; i++) {
    if(i > 1)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
}
