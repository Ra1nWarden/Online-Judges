#include <cstdio>
#include <cstring>
#define MAXN 1001

using namespace std;

bool colored[MAXN][MAXN];

int n, m, k;

bool check(int x, int y) {
  //left up
  if(x + 1 <= n && y + 1 <= m) {
    if(colored[x+1][y] && colored[x][y+1] && colored[x+1][y+1])
      return true;
  }
  // left down
  if(x - 1 >0 && y + 1 <= m) {
    if(colored[x-1][y] && colored[x][y+1] && colored[x-1][y+1])
      return true;
  }
  // right up
  if(x + 1 <= n && y - 1 > 0) {
    if(colored[x+1][y] && colored[x][y-1] && colored[x+1][y-1])
      return true;
  }
  // right down
  if(x -1 >0 && y - 1 >0) {
    if(colored[x-1][y] && colored[x][y-1] && colored[x-1][y-1])
      return true;
  }
  return false;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    colored[x][y] = true;
    if(check(x, y)) {
      printf("%d\n",i);
      return 0;
    }
  }
  printf("0\n");
  return 0;
}
