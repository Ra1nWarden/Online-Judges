#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 1005
#define INF 2e9

using namespace std;

int n, v, x;

struct Node {
  int pos, c, delta;
  Node() {}
  bool operator<(const Node& rhs) const {
    return pos < rhs.pos;
  }
};

Node nodes[MAXN];
int prefix_sum[MAXN];
double dp[MAXN][MAXN][2];
bool dpv[MAXN][MAXN][2];

double f(int i, int j, int s) {
  if(dpv[i][j][s])
    return dp[i][j][s];
  dpv[i][j][s] = true;
  if(i == 0 && j == n - 1)
    return dp[i][j][s] = 0;
  double ans = INF;
  if(i > 0) {
    ans = min(ans, f(i-1, j, 0) + (s == 0 ? (double) (nodes[i].pos - nodes[i-1].pos) / v : (double) (nodes[j].pos - nodes[i-1].pos) / v) * (prefix_sum[n] - prefix_sum[j+1] + prefix_sum[i]));
  }
  if(j < n - 1) {
    ans = min(ans, f(i, j+1, 1) + (s == 1 ? (double) (nodes[j+1].pos - nodes[j].pos) / v : (double) (nodes[j+1].pos - nodes[i].pos) / v) * (prefix_sum[n] - prefix_sum[j+1] + prefix_sum[i]));
  }
  return dp[i][j][s] = ans;
}

int main() {
  while(scanf("%d %d %d", &n, &v, &x) == 3 && (n || v || x)) {
    double base_cost = 0;

    for(int i = 0; i < n; i++) {
      scanf("%d %d %d", &nodes[i].pos, &nodes[i].c, &nodes[i].delta);
      base_cost += nodes[i].c;

    }
    sort(nodes, nodes + n);
    
    prefix_sum[0] = 0;
    for(int i = 0; i < n; i++)
      prefix_sum[i+1] = prefix_sum[i] + nodes[i].delta;
    
    Node dummy;
    dummy.pos = x;
    int start = lower_bound(nodes, nodes+n, dummy) - nodes;
    double ans = INF;
    memset(dpv, false, sizeof dpv);
    if(start > 0)
      ans = min(ans, base_cost + f(start - 1, start - 1, 0) + (double) (x - nodes[start - 1].pos) / v * prefix_sum[n]);
    if(start < n)
      ans = min(ans, base_cost + f(start, start, 0) + (double) (nodes[start].pos - x) / v * prefix_sum[n]);
    printf("%.0lf\n", floor(ans));
  }
  return 0;
}
