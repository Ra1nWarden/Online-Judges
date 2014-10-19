#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

long long dp[30001][6];
const int coins[] = {1, 5, 10, 25, 50};

// build n with first x
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
  else
    result = f(n, x-1);
  dp[n][x] = result;
  return result;
}

int main() {
  memset(dp, -1, sizeof dp);
  int n;
  while(cin >> n) {
    long long result =f(n, 5);
    if(result == 1)
      printf("There is only 1 way to produce %d cents change.\n", n);
    else
      printf("There are %lld ways to produce %d cents change.\n", result, n);
  }
  return 0;
}
