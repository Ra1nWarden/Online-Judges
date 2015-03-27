#include <string>
#include <cstdio>
#define MAXN 1005

using namespace std;

int n, m;
bool board[MAXN][MAXN];
int left[MAXN][MAXN];
int right[MAXN][MAXN];
int up[MAXN][MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
	int ch = getchar();
	while(ch != 'F' && ch != 'R')
	  ch = getchar();
	if(ch == 'F') {
	  board[i][j] = true;
	} else {
	  board[i][j] = false;
	}
      }
    }
    for(int i = 0; i < n; i++) {
      int prev = -1;
      for(int j = 0; j < m;  j++) {
	if(board[i][j]) {
	  up[i][j] = i > 0 ? up[i-1][j] + 1 : 1;
	  left[i][j] = i > 0 ? max(left[i-1][j], prev + 1) : prev + 1;
	} else {
	  up[i][j] = 0;
	  left[i][j] = 0;
	  prev = j;
	}
      }
      prev = m;
      for(int j = m - 1; j > -1; j--) {
	if(board[i][j]) {
	  right[i][j] = i > 0 ? min(right[i-1][j], prev - 1) : prev - 1;
	  ans = max(ans, (right[i][j] - left[i][j] + 1) * up[i][j]);
	  //printf("i = %d j = %d ans is %d up is %d\n", i, j, ans, up[i][j]);
	} else {
	  right[i][j] = m;
	  prev = j;
	}
      }
     
    }
    printf("%d\n", ans * 3);
  }
  return 0;
}
