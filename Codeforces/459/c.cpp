#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxl = 5000;
char str[maxl+5];
bool dp[maxl+5][maxl+5];
vector<int> ends[maxl+5];
int n;

int main() {
  scanf("%s", str);
  n = strlen(str);
  memset(dp, false, sizeof dp);
  int ans = 0;
  for(int l = 1; l < n; l += 2) {
    for(int i = 0; i + l < n; i++) {
      if(str[i] == ')') {
	continue;
      }
      if(str[i+l] == '(') {
	continue;
      }
      if(l == 1 || dp[i+1][i+l-1]) {
	dp[i][i+l] = true;
	ends[i].push_back(i+l);
	ans++;
      } else {
	bool ok = false;
	for(int j = 0; j < ends[i].size(); j++) {
	  int end = ends[i][j];
	  if(dp[end+1][i+l]) {
	    ok = true;
	    break;
	  }
	}
	dp[i][i+l] = ok;
	if(ok) {
	  ends[i].push_back(i+l);
	  ans++;
	}
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
