#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#define MAXN 105

using namespace std;

char str[MAXN];
int n;
int dp[MAXN][MAXN];
string ans[MAXN][MAXN];

int repeating(int i, int j) {
  for(int len = 1; len <= (j - i + 1) / 2; len++) {
    if((j - i + 1) % len == 0) {
      bool ok = true;
      for(int ii = i; ii <= j; ii++) {
	if(ii + len <= j && str[ii] != str[ii+len]) {
	  ok = false;
	  break;
	}
      }
      if(ok) {
	//printf("repeating %d to %d length is %d\n", i, j, len);
	return len;
      }
    }
  }
  return 0;
}

int f(int i, int j) {
  if(dp[i][j] != -1)
    return dp[i][j];
  int len_ans = j - i + 1;
  string str_ans = string(str+i, j-i+1);
  //printf("i=%d j=%d str_ans is %s\n", i, j, str_ans.c_str());
  for(int jj = i; jj < j; jj++) {
    if(f(i, jj) + f(jj+1, j) < len_ans) {
      len_ans = f(i, jj) + f(jj+1, j);
      str_ans = ans[i][jj] + ans[jj+1][j];
    }
  }
  int cycle = repeating(i, j);
  if(cycle) {
    stringstream ss;
    f(i, i+cycle-1);
    ss << (j - i + 1) / cycle << "(" << ans[i][i+cycle-1] << ")";
    string sub_res = ss.str();
    if(sub_res.length() < len_ans) {
      len_ans = sub_res.length();
      str_ans = sub_res;
    }
  }
  //printf("from %d to %d min_length is %d string is %s\n", i, j, len_ans, str_ans.c_str());
  ans[i][j] = str_ans;
  return dp[i][j] = len_ans;
}

int main() {
  while(scanf("%s\n", str) != EOF) {
    n = strlen(str);
    memset(dp, -1, sizeof dp);
    f(0, n-1);
    printf("%s\n", ans[0][n-1].c_str());
  }
  return 0;
}
