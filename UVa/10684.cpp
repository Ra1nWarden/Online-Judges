#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int n;
  while(cin >> n && n) {
    int v[n];
    for(int i= 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = x;
    }
    int dp[n+1][2];
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(int i= 1; i <= n; i++) {
      dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
      dp[i][1] = max(dp[i-1][1] + v[i-1], v[i-1]);
    }
    int result =  max(dp[n][0], dp[n][1]);
    if(result > 0)
      printf("The maximum winning streak is %d.\n", result);
    else
      printf("Losing streak.\n");
  }
  return 0;
}
