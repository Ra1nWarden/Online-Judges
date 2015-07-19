#include <cstring>
#include <cstdio>
#define MAXN 105

using namespace std;

int grid[MAXN][MAXN];
int s, c;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    memset(grid, -1, sizeof grid);
    scanf("%d %d", &s, &c);
    for(int i = 0; i < s; i++) {
      scanf("%d", &grid[s][i]);
    }
    for(int i = s - 1; i > 0; i--) {
      for(int j = 0; j < i; j++) {
	grid[i][j] = grid[i+1][j+1] - grid[i+1][j];
      }
    }
    for(int j = 1; j < s+c; j++)
      grid[1][j] = grid[1][j-1];
    for(int i = 2; i <= s; i++) {
      for(int j = i; j <= s+c; j++) {
	grid[i][j] = grid[i][j-1] + grid[i-1][j-1];
      }
    }
    for(int j = s; j < s+c; j++) {
      if(j > s)
	printf(" ");
      printf("%d", grid[s][j]);
    }
    printf("\n");
  }
  return 0;
}
