#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 200;
int dp[maxn+5];
int sum[maxn+5];

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    string w;
    cin >> n >> w;
    sum[0] = 0;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++) {
      sum[i] = w[i-1] == '1' ? sum[i-1] + 1 : sum[i-1];
      for(int j = 0; j < i; j++) {
	dp[i] = max(dp[i], dp[j]);
	if(sum[i] - sum[j] > (i - j) / 2) {
	  dp[i] = max(dp[i], dp[j] + (i - j));
	}
      }
    }
    cout << dp[n] << endl;
  }
  return 0;
}
