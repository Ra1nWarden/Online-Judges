#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 500;
char board[maxn+5][maxn+5];
int v[maxn+5][maxn+5];
int h, w;

void init() {
  for(int i = 0; i <= h; i++) {
    for(int j = 0; j <= w; j++) {
      v[i][j] = 0;
      if(board[i][j] == '.') {
	if(i + 1 <= h && board[i+1][j] == '.')
	  v[i][j]++;
	if(j + 1 <= w && board[i][j+1] == '.')
	  v[i][j]++;
      }
    }
  }
  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
      v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
    }
  }
}

int main() {
  scanf("%d %d\n", &h, &w);
  for(int i = 1; i <= h; i++) {
    scanf("%s\n", board[i]+1);
  }
  init();
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int ans = v[r2][c2] - v[r2][c1-1] - v[r1-1][c2] + v[r1-1][c1-1];
    if(c2 + 1 <= w) {
      for(int i = r1; i <= r2; i++) {
	if(board[i][c2+1] == '.' && board[i][c2] == '.')
	  ans--;
      }
    }
    if(r2 + 1 <= h) {
      for(int j = c1; j <= c2; j++) {
	if(board[r2+1][j] == '.' && board[r2][j] == '.')
	  ans--;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
