#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 3000;
int n, m;
vector<int> adjMat[maxn+5];
int dist[maxn+5][maxn+5];
int nodes[maxn+5][2][3];
pair<int, int> v[maxn+5];

int main() {
  scanf("%d%d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    adjMat[u].push_back(v);
  }
  memset(dist, -1, sizeof dist);
  for(int i = 1; i <= n; i++) {
    queue<int> q;
    dist[i][i] = 0;
    q.push(i);
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      int prev = dist[i][u];
      for(int j = 0; j < adjMat[u].size(); j++) {
	int v = adjMat[u][j];
	if(dist[i][v] == -1) {
	  dist[i][v] = prev + 1;
	  //printf("%d to %d=%d\n", i, v, dist[i][v]);
	  q.push(v);
	}
      }
    }
  }

  // for(int i = 1; i <= n; i++)
  //   for(int j = 1; j <= n; j++)
  //     printf("dist[%d][%d]=%d\n", i, j, dist[i][j]);

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      v[j] = make_pair(dist[i][j], j);
    }
    sort(v+1, v+n+1);
    // for(int j = 1; j <= n; j++)
    //   printf("v[%d]=%d,%d\n", j, v[j].first, v[j].second);
    for(int j = 0; j < 3; j++) {
      nodes[i][0][j] = v[n-j].second;
      //printf("nodes[%d][0][%d]=%d\n", i, j, nodes[i][0][j]);
    }
    for(int j = 1; j <= n; j++) {
      v[j] = make_pair(dist[j][i], j);
    }
    sort(v+1, v+n+1);
    // for(int j = 1; j <= n; j++)
    //     printf("v[%d]=%d,%d\n", j, v[j].first, v[j].second);
    for(int j = 0; j < 3; j++) {
      nodes[i][1][j] = v[n-j].second;
      //printf("nodes[%d][1][%d]=%d\n", i, j, nodes[i][1][j]);
    }
  }
  int max_val = -1;
  int a = -1, b = -1, c = -1, d = -1;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(j == i || dist[i][j] == -1)
	continue;
      for(int k = 0; k < 3; k++) {
	for(int l = 0; l < 3; l++) {
	  int aa = nodes[i][1][k];
	  int dd = nodes[j][0][l];
	  if(aa != -1 && dd != -1 && aa != i && aa != dd && aa != j && dd != i && dd != j) {
	  
	    int val = dist[aa][i] + dist[i][j] + dist[j][dd];
	    //printf("%d %d %d %d = %d\n", aa, i, j, dd, val);
	    if(val > max_val) {
	      max_val = val;
	      a = aa;
	      b = i;
	      c = j;
	      d = dd;
	    }
	  }
	}
      }
    }
  }
  printf("%d %d %d %d\n", a, b, c, d);
  return 0;
}
