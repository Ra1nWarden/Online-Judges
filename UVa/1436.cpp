#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

map<int, vector<int> > adjList;
int n, m;
const int maxn = 500000;
int total[maxn+1];
typedef pair<int, int> Node;
Node nodes[maxn+1];
int dp[maxn+1];
map<Node, int> mods;

int cnt(int root) {
  if(total[root] != -1)
    return total[root];
  int ans = 1;
  for(int i = 0; i < adjList[root].size(); i++) {
    ans += cnt(adjList[root][i]);
  }
  return total[root] = ans;
}

int choose(int a, int b) {
  Node k = make_pair(a, b);
  if(b > a)
    return 0;
  if(b > a / 2)
    return choose(a, a - b);
  if(b == 0)
    return 1;
  if(b == 1)
    return a;
  if(mods.count(k))
    return mods[k];
  return mods[k] = (choose(a-1, b) + choose(a-1, b-1)) % m;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    adjList.clear();
    mods.clear();
    scanf("%d %d", &n, &m);
    for(int i = 2; i <= n; i++) {
      int p;
      scanf("%d", &p);
      adjList[p].push_back(i);
    }
    memset(total, -1, sizeof total);
    int all = cnt(1);
    for(int i = 1; i <= n; i++) {
      nodes[i] = make_pair(total[i], i);
    }
    sort(nodes + 1, nodes + n + 1);
    for(int i = 1; i <= n; i++) {
      int id = nodes[i].second;
      if(total[id] == 1) {
	dp[id] = 1;
	continue;
      }
      int ans = 1;
      int combi = 1;
      int left = total[id] - 1;
      for(int j = 0; j < adjList[id].size(); j++) {
	ans = (ans * 1LL * dp[adjList[id][j]]) % m;
	combi = (combi * 1LL * choose(left, total[adjList[id][j]])) % m;
	left -= total[adjList[id][j]];
      }
      dp[id] = (ans * 1LL * combi) % m;
    }
    printf("%d\n", dp[1]);
  }
  return 0;
}
