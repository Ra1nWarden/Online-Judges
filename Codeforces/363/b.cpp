#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000;
int row[maxn+5], col[maxn+5];
char board[maxn+5][maxn+5];
int n, m;

int main() {
  scanf("%d%d\n", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%s\n", board[i]);
  int total = 0;
  memset(row, 0, sizeof row);
  memset(col, 0, sizeof col);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(board[i][j] == '*') {
	row[i]++;
	col[j]++;
	total++;
      }
    }
  }
  bool ans = false;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int cur = row[i] + col[j];
      if(board[i][j] == '*')
	cur--;
      if(cur == total) {
	printf("YES\n%d %d\n", i+1, j+1);
	return 0;
      }
    }
  }
  printf("NO\n");
  return 0;
}
