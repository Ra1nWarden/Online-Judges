#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int dp[101][25001];
int v[101];

int knapsack(int i, int j) {
  if(dp[i][j] > -1)
    return dp[i][j];
  int result = 0;
  if(i == 0 || j == 0)
    result = 0;
  else if(v[i-1] > j)
    result = knapsack(i-1, j);
  else
    result = max(knapsack(i-1, j - v[i-1]) + v[i-1], knapsack(i-1, j));
  dp[i][j] = result;
  return result;
}

int main() {
  int cases;
  cin >> cases;
  for(int i= 0; i < cases; i++) {
    int n;
    cin >> n;
    int sum = 0;
    for(int j= 0; j < n; j++) {
      int x;
      cin >> x;
      v[j] = x;
      sum += x;
    }
    memset(dp, -1, sizeof dp);
    int maxhalf = knapsack(n, sum/2);
    cout << (int) (abs(maxhalf + maxhalf -sum)) << endl;
  }
  return 0;
}
