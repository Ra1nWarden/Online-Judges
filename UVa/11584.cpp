#include <iostream>
#include <cstring>
#define MAXN 1005
#define INF 2e9

bool pali[MAXN][MAXN];
int dp[MAXN][MAXN];

using namespace std;

int f(int start, int end) {
  if(dp[start][end] != -1)
    return dp[start][end];
  if(pali[start][end])
    return dp[start][end] = 1;
  int res = INF;
  for(int i = end; i > start; i--) {
    if(pali[i][end]) {
      res = min(res, f(start, i - 1) + 1);
    }
  }
  return dp[start][end] = res;
}

int main() {
  int tc;
  cin >> tc;
  string line;
  getline(cin, line);
  while(tc--) {
    getline(cin, line);
    memset(pali, false, sizeof pali);
    for(int i = 0; i < line.length(); i++) {
      for(int j = i; j < line.length(); j++) {
	if(i == j) {
	  pali[i][j] = true;
	  continue;
	}
	bool ok = true;
	for(int k = 0; k <= (j - i) / 2; k++) {
	  if(line[i + k] != line[j - k]) {
	    ok = false;
	    break;
	  }
	}
	pali[i][j] = ok;
      }
    }
    memset(dp, -1, sizeof dp);
    cout << f(0, line.length() - 1) << endl;
  }
  return 0;
}
