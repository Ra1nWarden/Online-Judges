#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 505
#define INF 2000000000

using namespace std;

typedef pair<int, int> II; // index, depth

int dp[MAXN][MAXN][2];
int adjMat[MAXN][MAXN];
int n;
II v[MAXN];
bool childv[MAXN];
int nodecount[MAXN];
int maxdepth;

void getDepth(int parent, int level) {
  v[parent].first = parent;
  v[parent].second = level;
  maxdepth = max(maxdepth, level);
  nodecount[parent] = 1;
  for(int i = 0; i < n; i++) {
    if(adjMat[parent][i] > -1) {
      getDepth(i, level + 1);
      nodecount[parent] += nodecount[i];
    }
  }
}

bool _cmp(const II& a, const II& b) {
  return a.second > b.second;
}

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    memset(childv, false, sizeof childv);
    memset(adjMat, -1, sizeof adjMat);
    for(int i = 0; i < n - 1; i++) {
      int child, parent, weight;
      scanf("%d %d %d", &child, &parent, &weight);
      adjMat[parent][child] = weight;
      childv[child] = true;
    }
    int root;
    for(int i = 0; i < n; i++) {
      if(!childv[i]) {
	root = i;
	break;
      }
    }
    maxdepth = 0;
    getDepth(root, 0);
    sort(v, v+n, _cmp);
    
    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= n; j++)
	dp[i][j][0] = dp[i][j][1] = INF;

    for(int i = 0; i < n; i++) {
      int node = v[i].first;
      int dep = v[i].second;
      printf("looking at node %d depth is %d nodecount is %d\n", node, dep, nodecount[node]);
      for(int j = 0; j <= nodecount[node]; j++) {
	if(j <= 1) {
	  dp[node][j][0] = dp[node][j][1] = 0;
	  printf("set to 1 and continue\n");
	  continue;
	}
	for(int ch = 0; ch < n; ch++) {
	  printf("from %d to %d\n", node, ch);
	  if(adjMat[node][ch] > -1) {
	    for(int k = 1; k <= nodecount[ch]; k++) {
	      dp[node][j][1] = min(dp[node][j][1], dp[node][j-k][1] + 2 * adjMat[node][ch] + dp[ch][k][1]);
	      dp[node][j][0] = min(dp[node][j][0], dp[node][j-k][1] + dp[ch][k][0] + adjMat[node][ch]);
	      dp[node][j][0] = min(dp[node][j][0], dp[node][j-k][0] + dp[ch][k][1] + 2 * adjMat[node][ch]);
	      printf("k=%d dp[%d][%d][0] = %d dp[%d][%d][1] = %d\n", k, node, j, dp[node][j][0], node, j, dp[node][j][1]);
	    }
	  }
	}
	printf("dp[%d][%d][0] = %d dp[%d][%d][1] = %d\n", node, j, dp[node][j][0], node, j, dp[node][j][1]);
      }
      
    }

    int qn;
    scanf("%d", &qn);
    printf("Case %d:\n", kase++);
    while(qn--) {
      int query;
      scanf("%d", &query);
      for(int i = n; i >= 1; i--) {
	printf("i = %d dp[%d][%d][0] = %d\n",i, root, i, dp[root][i][0]);
	if(dp[root][i][0] <= query) {
	  printf("%d\n", i);
	  break;
	}
      }
    }

  }
  return 0;
}
