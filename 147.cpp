#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
  int coins[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
  long long dp[6001];
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for(int i= 0; i < 11; i++) {
    for(int j = 1; j <= 6000; j++) {
      if(j >= coins[i]) {
	dp[j] += dp[j - coins[i]];
      }
    }
  }
  
  double money;
  while(cin >> money && money != 0.00) {
    int n = (int) (money * 20);
    printf("%6.2lf%17.lld\n", money, dp[n]);
  }

  return 0;
}
