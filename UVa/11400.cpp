#include <cstdio>
#include <algorithm>
#define MAXN 1005
#define INF 2000000000

using namespace std;

int n;

struct Node {
  int v, k, c, l;
  Node() {}
  bool operator<(const Node& rhs) {
    return v < rhs.v;
  }
};

Node nodes[MAXN];
int dp[MAXN];
int s[MAXN];

int main() {
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++) {
      scanf("%d %d %d %d", &nodes[i].v, &nodes[i].k, &nodes[i].c, &nodes[i].l);
    }
    sort(nodes, nodes+n);
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
      s[i] = s[i-1] + nodes[i-1].l;
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
      dp[i] = INF;
      for(int j = 0; j < i; j++) {
	dp[i] = min(dp[i], dp[j] + (s[i] - s[j]) * nodes[i-1].c + nodes[i-1].k);
      }
    }
    printf("%d\n", dp[n]);
  }
  return 0;
}
