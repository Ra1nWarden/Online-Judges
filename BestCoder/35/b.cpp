#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 100005

using namespace std;

vector<int> flist[MAXN];
int inDegree[MAXN];
int sorted[MAXN];
int c[MAXN];
int n, m, k, t;

void dfs(int u) {
  c[u] = -1;
  for(int i = 0; i < flist[u].size(); i++) {
    int v = flist[u][i];
    if(!c[v])
      dfs(v);
  }
  c[u] = 1;
  sorted[--t] = u;
}

void toposort() {
  t = n;
  for(int u = 1; u <= n; u++) {
    if(!c[u])
      dfs(u);
  }
}

int main() {
  while(scanf("%d %d %d", &n, &m, &k) != EOF) {
    for(int i = 1; i <= n; i++) {
      flist[i].clear();
    }
    memset(inDegree, 0, sizeof inDegree);
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      flist[a].push_back(b);
      inDegree[b]++;
    }
    memset(c, 0, sizeof c);
    int index = 0;
    for(int i = n; i >= 1 && k > 0; i--) {
      //printf("i = %d, k = %d, size = %d\n", i, k, inDegree[i]);
      if(inDegree[i] <= k) {
	//printf("erased end with %d\n", i);
	c[i] = 1;
	sorted[index++] = i;
	k -= inDegree[i];
      }
    }
    toposort();
    for(int i = 0; i < n; i++) {
      if(i != 0)
	printf(" ");
      printf("%d", sorted[i]);
    } 
    printf("\n");
  }
  return 0;
}
