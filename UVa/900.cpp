#include <iostream>

using namespace std;

int dp[51];

int main() {
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i < 51; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }
  int n;
  while(cin >> n && n) {
    cout << dp[n] << endl;
  }
  return 0;
}
