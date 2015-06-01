#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXL 35

using namespace std;

string str1, str2;
int dp[MAXL][MAXL];
long long dpn[MAXL][MAXL][MAXL*2];
bool visited[MAXL][MAXL][MAXL*2];
int len1, len2, len;

long long g(int i, int j, int k) {
  if(visited[i][j][k])
    return dpn[i][j][k];
  if(i == 0 || j == 0) {
    visited[i][j][k] = true;
    return dpn[i][j][k] = (i+j == k) ? 1 : 0;
  } else {
    long long ans = 0;
    if(str1[i-1] == str2[j-1])
      ans += g(i-1, j-1, k-1);
    else
      ans += g(i-1, j, k-1) + g(i, j-1, k-1);
    visited[i][j][k] = true;
    return dpn[i][j][k] = ans;
  }
}

int main() {
  int tc;
  ios::sync_with_stdio(false);
  cin >> tc;
  getline(cin, str1);
  for(int kase = 1; kase <= tc; kase++) {
    getline(cin, str1);
    getline(cin, str2);
    len1 = str1.length();
    len2 = str2.length();
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= len1; i++) {
      for(int j = 1; j <= len2; j++) {
	if(str1[i-1] == str2[j-1])
	  dp[i][j] = dp[i-1][j-1] + 1;
	else
	  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
    len = len1 + len2 - dp[len1][len2];
    memset(visited, false, sizeof visited);
    long long ans = g(len1, len2, len);
    cout << "Case #" << kase << ": " << len << " " << ans << endl;
  }
  return 0;
}

