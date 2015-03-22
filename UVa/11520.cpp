#include <cstdio>
#define MAXN 15

using namespace std;

char board[MAXN][MAXN];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
      scanf("%s\n", board[i]);
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	if(board[i][j] == '.') {
	  for(char fill = 'A'; fill <= 'E'; fill++) {
	    if(i - 1 > -1 && board[i-1][j] == fill)
	      continue;
	    if(i+1 < n && board[i+1][j] == fill)
	      continue;
	    if(j - 1 > -1 && board[i][j-1] == fill)
	      continue;
	    if(j+1 < n && board[i][j+1] == fill)
	      continue;
	    board[i][j] = fill;
	    break;
	  }
	}
      }
    }
    printf("Case %d:\n", kase);
    for(int i = 0; i < n; i++)
      printf("%s\n", board[i]);
  }
  return 0;
}
