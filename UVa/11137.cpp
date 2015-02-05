#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int coins[] = {
  1,
  8,
  27,
  64,
  125,
  216,
  343,
  512,
  729,
  1000,
  1331,
  1728,
  2197,
  2744,
  3375,
  4096,
  4913,
  5832,
  6859,
  8000,
  9261
};

long long dp[10000][22];

long long f(int n, int x) {
  if(dp[n][x] > -1)
    return dp[n][x];
  long long result = 0;
  if(n == 0)
    result = 1;
  else if(x == 0)
    result = 0;
  else if(n >= coins[x-1]) {
    result = f(n - coins[x-1], x) + f(n, x-1);
  }
  else {
    result = f(n , x-1);
  }
  dp[n][x] = result;
  return result;
}

int main() {
  memset(dp, -1, sizeof dp);
  int n;
  while(cin >> n) {
    cout << f(n, 21) << endl;
  }
  return 0;
}
