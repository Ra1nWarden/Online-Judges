#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 8;

char board[maxn][maxn+1];

int main() {
  for(int i = 0; i < maxn; i++)
    scanf("%s\n", board[i]);
  int w = 10, b = 10;
  for(int j = 0; j < maxn; j++) {
    for(int i = 0; i < maxn; i++) {
      if(board[i][j] != '.') {
	if(board[i][j] == 'W') {
	  w = min(w, i);
	}
	break;
      }
    }
    for(int i = maxn-1; i >= 0; i--) {
      if(board[i][j] != '.') {
	if(board[i][j] == 'B') {
	  b = min(b, maxn - 1 - i);
	}
	break;
      }
    }
  }
  if(w <= b) {
    printf("A\n");
  } else {
    printf("B\n");
  }
  return 0;
}
