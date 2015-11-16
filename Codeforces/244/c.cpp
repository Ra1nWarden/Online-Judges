#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int maxn = 100000;
vector<int> graph[maxn+5];
int n, dfs_clock, scc_cnt;
int pre[maxn+5], lowlink[maxn+5], sccno[maxn+5];
stack<int> s;

void init() {
  for(int i = 1; i <= n; i++) {
    graph[i].clear();
  }
  dfs_clock = scc_cnt = 0;
  memset(sccno, 0, sizeof sccno);
  memset(pre, 0, sizeof pre);
}

void addEdge(int u, int v) {
  graph[u].push_back(v);
}

void dfs(int u) {
  pre[u] = lowlink[u] = ++dfs_clock;
  s.push(u);
  for(int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if(!pre[v]) {
      dfs(v);
      lowlink[u] = min(lowlink[u], lowlink[v]);
    } else if(!sccno[v]) {
      lowlink[u] = min(lowlink[u], pre[v]);
    }
  }
  if(lowlink[u] == pre[u]) {
    scc_cnt++;
    while(true) {
      int x = s.top();
      s.pop();
      sccno[x] = scc_cnt;
      if(x == u)
	break;
    }
  }
}

void tarjan() {
  for(int i = 1; i <= n; i++) {
    if(!pre[i])
      dfs(i);
  }
}

int cost[maxn+5];
int scc_min[maxn+5];
int scc_cost_min[maxn+5];
const int mod = 1e9 + 7;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &cost[i]);
  init();
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(u, v);
  }
  tarjan();
  memset(scc_min, -1, sizeof scc_min);
  memset(scc_cost_min, -1, sizeof scc_cost_min);
  for(int i = 1; i <= n; i++) {
    int scc = sccno[i];
    //printf("i=%d scc=%d\n", i, sccno[i]);
    if(scc_cost_min[scc] == -1 || cost[i] < scc_cost_min[scc]) {
      scc_cost_min[scc] = cost[i];
      scc_min[scc] = 1;
    } else if(scc_cost_min[scc] == cost[i]) {
      scc_min[scc]++;
    }
  }
  long long total_cost = 0;
  long long total_cnt = 1;
  //printf("scc_cnt is %d\n", scc_cnt);
  for(int i = 1; i <= scc_cnt; i++) {
    total_cost += scc_cost_min[i];
    total_cnt = total_cnt * scc_min[i];
    total_cnt %= mod;
  }
  printf("%I64d %I64d\n", total_cost, total_cnt);
  return 0;
}
