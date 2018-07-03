#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

const int maxn = 1000;
int r, c;
char mat[maxn+5][maxn+5];
int vis[maxn+5][maxn+5];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
typedef pair<int, int> Node;
Node start;
int maxl = 0;

void dfs(int i , int j, int v) {
  if(v > maxl) {
    start = make_pair(i, j);
    maxl = v;
  }
  vis[i][j] = v;
  for(int dir = 0; dir < 4; dir++) {
    int ii = i + dx[dir];
    int jj = j + dy[dir];
    if(ii < 0 || ii >= r || jj < 0 || jj >= c || mat[ii][jj] == '#' || vis[ii][jj] != -1) {
      continue;
    }
    dfs(ii, jj, v + 1);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d\n", &c, &r);
    for(int i = 0; i < r; i++) {
      scanf("%s\n", mat[i]);
    }
    memset(vis, -1, sizeof vis);
    for(int i = 0; i < r; i++) {
      bool br = false;
      for(int j = 0; j < c; j++) {
	if(mat[i][j] == '.') {
	  maxl = 0;
	  start = make_pair(i, j);
	  dfs(i, j, 0);
	  br = true;
	  break;
	}
      }
      if(br)
	break;
    }
    memset(vis, -1, sizeof vis);
    maxl = 0;
    dfs(start.first, start.second, 0);
    printf("Maximum rope length is %d.\n", maxl);
  }
  return 0;
}
