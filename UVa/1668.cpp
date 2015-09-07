#include <cstdio>
#include <vector>
#define MAXN 100010

using namespace std;

struct Edge {
  int u, v, w;
};

Edge edges[MAXN];
int n;
vector<int> adjList[MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
      adjList[i].clear();
    for(int i = 0; i < n - 1; i++) {
      scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
      adjList[edges[i].u].push_back(i);
      adjList[edges[i].v].push_back(i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      int max_val = -1;
      int sum = 0;
      for(int j = 0; j < adjList[i].size(); j++) {
	sum += edges[adjList[i][j]].w;
	max_val = max(max_val, edges[adjList[i][j]].w);
      }
      if(2 * max_val > sum)
	ans += (2 * max_val - sum);
      else if(sum % 2)
	ans++;
    }
    printf("Case #%d: %d\n", kase, ans / 2);
  }
  return 0;
}
