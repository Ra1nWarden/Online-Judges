#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 2e8

using namespace std;

string line;
int dp[1000][1000];

int f(int a, int b) {
  //cout << "f " << a << " , " << b << endl;
  if(dp[a][b] != -1)
    return dp[a][b];
  if(a == b)
    return dp[a][b] = 0;
  if(line[a] == line[b]) {
    if(a == b - 1)
      return dp[a][b] = 0;
    else
      dp[a][b] = f(a+1, b-1);
  }
  if(dp[a][b] == -1)
    dp[a][b] = INF;
  dp[a][b] = min(dp[a][b], f(a+1, b) + 1);
  dp[a][b] = min(dp[a][b], f(a, b-1) + 1);
  if(b - a >= 2)
    dp[a][b] = min(dp[a][b], f(a+1, b-1) + 1);
  return dp[a][b];
}

int main() {
  int n;
  cin >> n;
  getline(cin, line);
  int tc = 1;
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", tc++, f(0, line.length() - 1));
  }
  return 0;
}
