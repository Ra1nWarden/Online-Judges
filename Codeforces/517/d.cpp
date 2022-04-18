#include <cstdio>
#include <cstring>
#include <utility>
#include <set>

using namespace std;

const int maxn = 2000;
int dp[maxn+5][maxn+5];
char mat[maxn+5][maxn+5];
typedef pair<int, int> II;
char ans[maxn*2];
int n, k;

int main() {
  scanf("%d %d\n", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%s\n", mat[i]);
  memset(dp, -1, sizeof dp);
  dp[0][0] = k;
  if(mat[0][0] != 'a')
    dp[0][0]--;
  set<II> maxp;
  if(dp[0][0] > -1)
    maxp.insert(make_pair(0, 0));
  for(int len = 1; len < 2*n-1; len++) {
    for(int i = 0; i < n; i++) {
      int j = len - i;
      if(j < 0 || j >= n)
	continue;
      if(mat[i][j] == 'a') {
	if(i)
	  dp[i][j] = max(dp[i][j], dp[i-1][j]);
	if(j)
	  dp[i][j] = max(dp[i][j], dp[i][j-1]);
      } else {
	if(i && dp[i-1][j] > 0)
	  dp[i][j] = max(dp[i-1][j] - 1, dp[i][j]);
	if(j && dp[i][j-1] > 0)
	  dp[i][j] = max(dp[i][j-1] - 1, dp[i][j]);
      }
      if(dp[i][j] > -1) {
	if(!maxp.empty() && maxp.begin()->first + maxp.begin()->second < i + j) {
	  maxp.clear();
	}
	maxp.insert(make_pair(i, j));
      }
    }
  }
  int idx = 0;
  
  if(maxp.empty()) {
    ans[idx++] = mat[0][0];
    maxp.insert(make_pair(0, 0));
  } else {
    while(idx <= maxp.begin()->first + maxp.begin()->second) {
      ans[idx++] = 'a';
    }
  }

  while(idx < 2 * n - 1) {
    set<II> next_max;
    char minc = 'z' + 1;
    for(II each : maxp) {
      int ii = each.first;
      int jj = each.second;
      if(ii + 1 < n) {
	if(mat[ii + 1][jj] < minc) {
	  next_max.clear();
	  next_max.insert(make_pair(ii + 1, jj));
	  minc = mat[ii + 1][jj];
	} else if(mat[ii + 1][jj] == minc) {
	  next_max.insert(make_pair(ii + 1, jj));
	}
      }
      if(jj + 1 < n) {
	if(mat[ii][jj + 1] < minc) {
	  next_max.clear();
	  next_max.insert(make_pair(ii, jj + 1));
	  minc = mat[ii][jj + 1];
	} else if(mat[ii][jj + 1] == minc) {
	  next_max.insert(make_pair(ii, jj + 1));
	}
      }
    }
    ans[idx++] = minc;
    maxp = next_max;
  }
  ans[idx++] = '\0';
 
  printf("%s\n", ans);
  return 0;
}
