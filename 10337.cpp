#include <iostream>
#include <cstring>

using namespace std;

int v[10][1001];
int dp[10][1001];

bool DEBUG = false;

int main() {
  int cases;
  cin >> cases;
  for(int i= 0; i < cases; i++) {
    int x;
    cin >> x;
    memset(v, 0, sizeof v);
    for(int j = 0; j < 10; j++) {
      for(int k = 0; k < x / 100; k++) {
	int wind;
	cin >> wind;
	v[j][k] = wind;
      }
    }
    memset(dp, -1, sizeof v);
    dp[9][0] = 0;
    for(int k = 1; k <= x/100; k++) {
      for(int j = 0; j < 10; j++) {
	int minCost = -1;
	if(dp[j][k-1] > -1)
	  minCost = dp[j][k-1] - v[j][k-1] + 30;
	if(j > 0 && dp[j-1][k-1] > -1) {
	  if(minCost > -1)
	    minCost = min(minCost, dp[j-1][k-1] - v[j-1][k-1] + 20);
	  else
	    minCost = dp[j-1][k-1] - v[j-1][k-1] + 20;
	}
	if(j < 9 && dp[j+1][k-1] > -1) {
	  if(minCost > -1)
	    minCost = min(minCost, dp[j+1][k-1] - v[j+1][k-1] + 60);
	  else
	    minCost = dp[j+1][k-1] - v[j+1][k-1] + 60;
	}
	dp[j][k] = minCost;
      }
    }
    if(DEBUG) {
      cout << "start of dp table" << endl;
      for(int j = 0; j < 10; j++) {
	for(int k = 0; k <= x/100; k++) {
	  cout << dp[j][k] << " ";
	}
	cout << endl;
      }
    }
    
    cout << dp[9][x/100] << endl;
    cout << endl;
  }
  return 0;
}
