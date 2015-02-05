#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int v[1001];
int dp[1001];
int dpVal[1001];
int l, c, n;

int f(int x) {
  if(dp[x] > -1)
    return dp[x];
  if(x == 0)
    return 0;
  if(x == 1) {
    dp[x] = 1;
    int diff = l - v[n-1];
    if(diff == 0)
      dpVal[x] = 0;
    else if(diff <= 10)
      dpVal[x] = -c;
    else
      dpVal[x] = (diff - 10) * (diff - 10);
    return 1;
  }
  int result = 1001;
  int resultCost = 0;
  int used = 0;

  for(int i = n - x; i < n; i++) {
    used += v[i];
    if(used > l)
      break;
    int nextCount = f(n- i-1) + 1;
    if(nextCount < result) {
      result = nextCount;
      resultCost = dpVal[n-i-1];
      if(l - used <= 10 && l - used > 0)
	resultCost += (-c);
      else if(l - used > 10)
	resultCost += ((l-used-10) * (l-used-10));
    } else if (nextCount == result) {
      result = nextCount;
      int newResultCost = dpVal[n-i-1];
      if(l - used <= 10 && l - used > 0)
	newResultCost += (-c);
      else if(l - used > 10)
	newResultCost += ((l-used-10) * (l-used-10));
      resultCost = min(newResultCost, resultCost);
    }
  }
  dp[x] = result;
  dpVal[x] = resultCost;
  // cout << "finished dp for " << x << ": " << dp[x] << ", " << dpVal[x] << endl;
  return result;
}

int main() {
  int caseNo = 1;
  while(cin >> n && n) {
    if(caseNo > 1)
      cout << endl;
    cin >> l >> c;
    for(int i= 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = x;
    }
    memset(dp, -1, sizeof dp);
    memset(dpVal, 0, sizeof dpVal); 
    int minLecture = f(n);
    int minCost = dpVal[n];
    printf("Case %d:\n", caseNo++);
    printf("Minimum number of lectures: %d\n", minLecture);
    printf("Total dissatisfaction index: %d\n", minCost);
  } 
  return 0;
}
