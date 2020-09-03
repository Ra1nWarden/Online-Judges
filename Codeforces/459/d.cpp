#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

const int maxn = 100;
int n, m;
typedef pair<char, int> Edge;
set<Edge> edges[maxn+5];
char val[maxn+5][maxn+5];
int dp[maxn+5][maxn+5][maxn+5];

int f(int i, int j, int k) {
  if(dp[i][j][k] != -1) {
    return dp[i][j][k];
  }
  char prev = val[i][k];
  bool win = false;
  for(auto ii = lower_bound(edges[j].begin(), edges[j].end(), make_pair(prev, 0)); ii != edges[j].end(); ii++) {
    if(f(j, k, ii->second)) {
      win = true;
      break;
    }
  }
  return dp[i][j][k] = win ? 0 : 1;
}

int main() {
  scanf("%d%d\n", &n, &m);
  while(m--) {
    int v, u;
    char c;
    scanf("%d %d %c\n", &v, &u, &c);
    val[v][u] = c;
    edges[v].insert(make_pair(c, u));
  }
  
  memset(dp, -1, sizeof dp);
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      bool win = false;
      for(auto each : edges[i]) {
	int k = each.second;
	if(f(i, j, k)) {
	  win = true;
	  break;
	}
      }
      printf("%c", win ? 'A' : 'B');
    }
    printf("\n");
  }
  return 0;
}
