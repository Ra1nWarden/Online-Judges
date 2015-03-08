#include <iostream>
#include <vector>
#include <cstring>
#define MAXN (1<<12)
#define INF 2e9

using namespace std;

int dp[MAXN][MAXN];
int m, n;
vector<string> v;

int f(int ques, int ans) {
  if(dp[ques][ans] != -1)
    return dp[ques][ans];
  int count = 0;
  for(int i = 0; i < n; i++) {
    bool match = true;
    for(int j = 0; j < m; j++) {
      if((ques & (1 << j)) != 0) {
	if((ans & (1 << j)) != 0) {
	  if(v[i][j] == '0')
	    match = false;
	} else {
	  if(v[i][j] == '1')
	    match = false;
	}
      }
      if(!match)
	break;
    }
    if(match)
      count++;
    if(count > 1)
      break;
  }
  if(count == 0)
    return dp[ques][ans] = INF;
  if(count == 1)
    return dp[ques][ans] = 0;
  int res = INF;
  for(int i = 0; i < m; i++) {
    if(((1 << i) & ques) == 0) {
      res = min(res, max(f(ques | (1 << i), ans | (1 << i)), f(ques | (1 << i), ans)) + 1);
    }
  }
  return dp[ques][ans] = res;
}

int main() {
  ios_base::sync_with_stdio(false);
  string line;
  while(cin >> m >> n && (n || m)) {
    v.clear();
    getline(cin, line);
    for(int i = 0; i < n; i++) {
      getline(cin, line);
      v.push_back(line);
    }
    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << endl;
  }
  return 0;
}
