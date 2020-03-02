#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxd = 2000, maxn = 100, maxt = 20;
int dp[maxd+5][maxn+5];

struct Node {
  int t, d, p, i;
  const bool operator<(const Node& node) {
    return d < node.d;
  }
};

Node nodes[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d %d", &nodes[i].t, &nodes[i].d, &nodes[i].p);
    nodes[i].i = i+1;
  }
  sort(nodes, nodes+n);

  memset(dp, 0, sizeof dp);

  for(int i = 0; i < n; i++) {
    for(int t = 0; t < nodes[n-1].d; t++) {
      if(t+nodes[i].t < nodes[i].d) {
	dp[t+nodes[i].t][i+1] = max(dp[t+nodes[i].t][i+1], dp[t][i] + nodes[i].p);
      }
      dp[t][i+1] = max(dp[t][i+1], dp[t][i]);
    }
  }

  int ans = 0;
  int cur = 0;
  for(int t = 0; t < nodes[n-1].d; t++) {
    if(dp[t][n] > ans) {
      ans = dp[t][n];
      cur = t;
    }
  }

  printf("%d\n", ans);

  vector<int> items;
  int idx = n;
  while(cur > 0) {
    if(dp[cur][idx] == dp[cur][idx-1]) {
      idx--;
    } else {
      items.push_back(nodes[idx-1].i);
      cur -= nodes[idx-1].t;
      idx--;
    }
  }

  printf("%d\n", items.size());
  for(int i = items.size() - 1; i >= 0; i--) {
    printf("%d", items[i]);
    if(i)
      printf(" ");
  }
  printf("\n");
  
  return 0;
}
