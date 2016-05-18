#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>

using namespace std;

const int maxl = 10000;
char str[maxl+5];
bool dp[maxl+5][2];
int n;

string rev(string s) {
  reverse(s.begin(), s.end());
  return s;
}

int main() {
  scanf("%s", str);
  n = strlen(str);
  reverse(str, str+n);
  set<string> ans;
  memset(dp, false, sizeof dp);
  n -= 5;
  for(int i = 0; i < n; i++) {
    if(i + 1 < n) {
      if(i == 0) {
	ans.insert(rev(string(str+i, 2)));
	dp[i][0] = true;
      } else if(i - 3 >= 0 && dp[i-3][1]) {
	ans.insert(rev(string(str+i, 2)));
	dp[i][0] = true;
      } else if(i - 2 >= 0 && dp[i-2][0] && string(str+i-2, 2) != string(str+i, 2)) {
	ans.insert(rev(string(str+i, 2)));
	dp[i][0] = true;
      }
    }
    if(i + 2 < n) {
      if(i == 0) {
	ans.insert(rev(string(str+i, 3)));
	dp[i][1] = true;
      } else if(i - 2 >= 0 && dp[i-2][0]) {
	ans.insert(rev(string(str+i, 3)));
	dp[i][1] = true;
      } else if(i - 3 >= 0 && dp[i-3][1] && string(str+i-3, 3) != string(str+i, 3)) {
	ans.insert(rev(string(str+i, 3)));
	dp[i][1] = true;
      }
    }
  }
  printf("%d\n", ans.size());
  for(set<string>::iterator itr = ans.begin(); itr != ans.end(); itr++) {
    printf("%s\n", itr->c_str());
  }
  return 0;
}
