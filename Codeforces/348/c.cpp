#include <utility>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;
const int maxq = 10000;
int n, m, q;
typedef pair<int, int> II;
II mat[maxn+1][maxn+1];
int ans[maxn+1][maxn+1];

void init() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      mat[i][j] = make_pair(i, j);
    }
  }
}

void row_shift(int v) {
  for(int j = 1; j <= m - 1; j++) {
    swap(mat[v][j], mat[v][j+1]);
  }
}

void col_shift(int v) {
  for(int i = 1; i <= n - 1; i++) {
    swap(mat[i][v], mat[i+1][v]);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  init();
  memset(ans, 0, sizeof ans);
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int v;
      scanf("%d", &v);
      row_shift(v);
    } else if(t == 2) {
      int v;
      scanf("%d", &v);
      col_shift(v);
    } else if(t == 3) {
      int x,y, v;
      scanf("%d%d%d", &x, &y, &v);
      ans[mat[x][y].first][mat[x][y].second] = v;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(j > 1)
	printf(" ");
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
