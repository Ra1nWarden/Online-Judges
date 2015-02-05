#include <iostream>
#include <cstring>

using namespace std;

int dp[10001];

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    int target;
    int n;
    cin >> target >> n;
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for(int i= 0; i < n; i++) {
      int x;
      cin >> x;
      for(int i = 10000 - x; i>= 0; i--) {
	if(dp[i] > -1) {
	  if(dp[i+x] < 0) {
	    dp[i+x] = dp[i] + 1;
	  } else {
	    dp[i+x] = min(dp[i] + 1, dp[i+x]);
	  }
	}
      }
    }
    int result1 = 0;
    int result2 = 0;
    for(int i = target; i <= 10000; i++) {
      if(dp[i] > -1) {
	result1 = i;
	result2 = dp[i];
	break;
      }
    }
    cout << result1 << " " << result2 << endl;
  }
}
