#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 182;

char mat[maxn+5][maxn+5];
typedef pair<int, int> Node;
int n, m;
int ans[maxn+5][maxn+5];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main() {
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%d%d\n", &n, &m);
    for(int i = 0; i < n; i++)
      scanf("%s\n", mat[i]);
    memset(ans, -1, sizeof ans);
    queue<Node> q;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
	if(mat[i][j] == '1') {
	  ans[i][j] = 0;
	  q.push(make_pair(i, j));
	}
      }
    }
    while(!q.empty()) {
      Node u = q.front();
      q.pop();
      int cur = ans[u.first][u.second];
      for(int i = 0; i < 4; i++) {
	int ii = u.first + dx[i];
	int jj = u.second + dy[i];
	if(ii < 0 || ii >= n || jj < 0 || jj >= m) {
	  continue;
	}
	if(ans[ii][jj] != -1)
	  continue;
	ans[ii][jj] = cur + 1;
	q.push(make_pair(ii, jj));
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
	if(j)
	  printf(" ");
	printf("%d", ans[i][j]);
      }
      printf("\n");
    }
    if(tc)
      printf("\n");
  }
  return 0;
}
