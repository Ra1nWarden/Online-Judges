#include <iostream>
#include <cstring>

using namespace std;

int dp[1000][1000];
string line;

int f(int a, int b) {
  if(dp[a][b] != -1)
    return dp[a][b];
  if(a == b)
    return dp[a][b] = 1;
  if(a + 1 == b)
    return dp[a][b] = line[a] == line[b] ? 2 : 1;
  if(line[a] == line[b])
    return dp[a][b] = f(a+1, b-1) + 2;
  else
    return dp[a][b] = max(f(a+1, b), f(a, b-1));
}

int main() {
  int n;
  cin >> n;
  getline(cin, line);
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    memset(dp, -1, sizeof dp);
    cout << f(0, line.length() - 1) << endl;
  }
  return 0;
}
