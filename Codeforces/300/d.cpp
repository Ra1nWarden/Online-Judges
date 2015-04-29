#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 55

using namespace std;

int board[MAXN][MAXN];
int vboard[MAXN][MAXN];
char buff[MAXN];
bool ans[MAXN * 2][MAXN * 2];
typedef pair<int, int> II;
vector<II> pieces;
int n;

bool ok(int dx, int dy) {
  bool reached = false;
  for(int i = 0; i < pieces.size(); i++) {
    int x = pieces[i].first;
    int y = pieces[i].second;
    if(x + dx > -1 && x + dx < n && y + dy > -1 && y + dy < n) {
      reached = true;
      if(board[x+dx][y+dy] == -1)
	return false;
    }
  }
  if(!reached)
    return false;
  return true;
}

bool validate(vector<II> moves) {
  memset(vboard, -1, sizeof vboard);
  for(int i = 0; i < pieces.size(); i++) {
    int x = pieces[i].first;
    int y = pieces[i].second;
    for(int j = 0; j < moves.size(); j++) {
      int dx = moves[j].first;
      int dy = moves[j].second;
      if(x + dx > -1 && x + dx < n && y + dy > -1 && y + dy < n) {
	vboard[x+dx][y+dy] = 1;
       }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(board[i][j] == 1 && vboard[i][j] == -1)
	 return false;
    }
  }
  return true;
}


int main() {
  scanf("%d\n", &n);
  pieces.clear();
  memset(board, -1, sizeof board);
  for(int i = 0; i < n; i++) {
    scanf("%s", buff);
    for(int j= 0; j < n; j++) {
      if(buff[j] == 'x') {
	board[i][j] = 1;
      } else if(buff[j] == 'o') {
	board[i][j] = 0;
	pieces.push_back(make_pair(i, j));
      }
    }
  }
  vector<II> moves;
  for(int dx = -(n-1); dx <= (n-1); dx++) {
    for(int dy = -(n-1); dy <= (n-1); dy++) {
      if(ok(dx, dy))
	moves.push_back(make_pair(dx, dy));
    }
  }
  
  if(validate(moves)) {
    printf("YES\n");
    memset(ans, false, sizeof ans);
    for(int i = 0; i < moves.size(); i++) {
      int dx = moves[i].first;
      int dy = moves[i].second;
      if(n-1 + dx > -1 && n-1 + dx < (2 * n - 1) && n-1 + dy > -1 && n-1+dy < (2 * n - 1)) {
	ans[n-1+dx][n-1+dy]= true;
      }
    }
    for(int i = 0; i < 2 * n - 1; i++) {
      for(int j = 0; j < 2 * n - 1; j++) {
	if(i == n - 1 && j == n - 1)
	  printf("o");
	else if(ans[i][j]) {
	  printf("x");
	} else {
	  printf(".");
	}
      }
      printf("\n");
    }
  } else {
    printf("NO\n");
  }
  
  return 0;
}
