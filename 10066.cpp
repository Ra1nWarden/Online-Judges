#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
  int x, y;
  int tc = 1;
  while(cin >> x >> y && (x || y)) {
    int v1[x];
    int v2[y];
    for(int i = 0; i < x; i++) {
      int num;
      cin >> num;
      v1[i] = num;
    }
    for(int i = 0; i < y; i++) {
      int num;
      cin >> num;
      v2[i] = num;
    }
    int dp[x+1][y+1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= x; i++) {
      for(int j = 1; j <= y; j++) {
	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	if(v1[i-1] == v2[j-1])
	  dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
      }
    }
    printf("Twin Towers #%d\n", tc++);
    printf("Number of Tiles : %d\n\n", dp[x][y]);
  }
  return 0;
}
