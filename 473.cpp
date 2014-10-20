#include <iostream>
#include <cstring>
#include <map>
#include <sstream>

using namespace std;

// dp[i][j][k] -> first i songs, j disc remaining, k minutes remaining on another disc
int dp[800][100][100];
int v[800];

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    memset(v, -1, sizeof v);
    int n, t, m;
    cin >> n >> t >> m >> ws;
    string line;
    getline(cin, line);
    istringstream iss(line.c_str());
    int v[n];
    for(int i = 0; i < n; i++) {
      string numberString;
      int number;
      getline(iss, numberString, ',');
      istringstream numberss(numberString.c_str());
      numberss >> number;
      v[i] = number;
    }
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= m; j++) {
	for(int k = 0; k <= t; k++) {
	  int currentDisc = v[i-1];
	  // not take the ith
	  dp[i][j][k] = dp[i-1][j][k];
	  // take the ith
	  if(k >= currentDisc) {
	    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-currentDisc] + 1);
	  }
	  if(j > 0) {
	    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][t - currentDisc] + 1);
	  }
	}
      }
    }
    int result = dp[n][m][0];
    cout << result << endl;
    if(cases)
      cout << endl;
  }
  return 0;
}
