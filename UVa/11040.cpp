#include <cstdio>
#include <cstring>

using namespace std;

int bricks[10][10];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    memset(bricks, -1, sizeof bricks);
    for(int i = 0; i < 9; i += 2) {
      for(int j = 0; j <= i; j += 2) {
	scanf("%d", &bricks[i][j]);
      }
    }
    for(int i = 2; i < 9; i += 2) {
      for(int j = 1; j <= i; j += 2) {
	bricks[i][j] = (bricks[i-2][j-1] - bricks[i][j-1] - bricks[i][j+1]) / 2;
      }
    }
    for(int i = 1; i < 9; i += 2) {
      for(int j = 0; j <= i; j++) {
	bricks[i][j] = bricks[i+1][j] + bricks[i+1][j+1];
      }
    }
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j <= i; j++) {
	if(j > 0)
	  printf(" ");
	printf("%d", bricks[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
