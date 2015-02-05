#include <iostream>
#include <cstring>

using namespace std;

struct Item {
  Item() {};
  int weight, value;
};

Item items[1001];
int dp[1001][31];

int knapsack(int i, int j) {
  if(dp[i][j] > -1)
    return dp[i][j];
  int result = 0;
  if(i == 0 || j == 0)
    result = 0;
  else {
    if(items[i-1].weight > j) {
      result = knapsack(i-1, j);
    } else {
      result = max(knapsack(i-1, j - items[i-1].weight) + items[i-1].value, knapsack(i-1, j));
    }
  }
  dp[i][j] = result;
  return result;
}

int main() {
  int cases;
  cin >> cases;
  for(int i= 0; i < cases; i++) {
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    for(int j= 0; j < n; j++) {
      int x, y;
      cin >> x >> y;
      items[j].value = x;
      items[j].weight = y;
    }
    int ppl;
    cin >> ppl;
    int result = 0;
    for(int i= 0; i < ppl; i++) {
      int capacity;
      cin >> capacity;
      result += knapsack(n, capacity);
    }
    cout << result << endl;
  }
  return 0;
}
