#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    int v[n];
    int iv[n+1];
    for(int i= 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = x;
      iv[x] = i;
    }
    int dp[n];
    long long sum[n];
    long long result = 0;
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++) {
      for(int j = 1; j < v[i]; j++) {
	if(iv[j] < i) {
	  dp[i]++;
	  if(iv[j] > 0) {
	    //cout << "i is " << i << " index for " << j << " is " << iv[j] << " sum is " << sum[iv[j] - 1] << endl;
	    result += sum[iv[j] - 1];
	  }
	}
      }
      if(i == 0)
	sum[0] = dp[0];
      else
	sum[i] = sum[i - 1] + dp[i];
      //cout << "dp i is " << dp[i] << endl;
      //cout << "sum i is "  << sum[i] << endl;
    } 
    cout << result << endl;
  }
  return 0;
}
