#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

map<int, vector<int> > facts;
int dp[1001][1001];

int main() {
  for(int i= 2; i <= 1000; i++) {
    if(facts.count(i) == 0) {
      vector<int> singleton;
      singleton.push_back(i);
      facts[i] = singleton;
      for(int j = i + i; j <= 1000; j += i) {
	if(facts.count(j) == 0) {
	  vector<int> singleton;
	  singleton.push_back(i);
	  facts[j] = singleton;
	} else {
	  facts[j].push_back(i);
	}
      }
    }
  }

  memset(dp, -1, sizeof dp);
  for(int i = 1000; i >= 1; i--) {
    vector<int> primefact = facts[i];
    dp[i][i] = 0;
    for(int j= 0; j < primefact.size(); j++) {
      if(primefact[j] == i)
	continue;
      if(i + primefact[j] > 1000)
	break;
      else
	dp[i][i+primefact[j]] = 1;
    }
    for(int j= i+1; j <= 1000; j++) {
      if(dp[i][j] == -1) {
	for(int k = i+1; k < j; k++) {
	  if(dp[i][k] != -1 && dp[k][j] != -1) {
	    if(dp[i][j] == -1)
	      dp[i][j] = dp[i][k] + dp[k][j];
	    else
	      dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	  }
	}
      }
    }
  }
  
  int x, y;
  int caseNo = 1;
  while(cin >> x >> y && (x || y)) {
    int result = dp[x][y];
    cout << "Case " << caseNo++ << ": " << result << endl;
  }
  return 0;
}
