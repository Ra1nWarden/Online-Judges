#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

ll dp[51][2];

int main() {
  memset(dp, 0, sizeof dp);
  dp[1][0] = 1;
  dp[1][1] = 1;
  for(int i= 2; i < 51; i++) {
    dp[i][0] = dp[i-1][0] + dp[i-1][1];
    dp[i][1] = dp[i-1][0];
  }
  
  int n;
  cin >> n;
  for(int i= 1; i <= n; i++) {
    int x;
    cin >> x;
    printf("Scenario #%d:\n", i);
    printf("%lld\n\n", dp[x][0] + dp[x][1]);
  }

  return 0;
}
