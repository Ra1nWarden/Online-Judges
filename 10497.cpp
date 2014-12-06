#include <iostream>

using namespace std;

typedef long long ll;

ll dp[801];

int main() {
  dp[0] = 1;
  for(int i = 1; i < 801; i++) {
    dp[i] = dp[i-1] * i + (i % 2 == 0 ? 1 : -1);
  }
  int n;
  while(cin >> n && n != -1)
    cout << dp[n] << endl;
  return 0;
}
