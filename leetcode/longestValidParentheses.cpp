#include <cstring>
#include <algorithm>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;

int longestValidParentheses(string s) {
  int dp[s.length()];
  memset(dp, 0, sizeof dp);
  stack<int> st;
  int ans = 0;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == '(')
      st.push(i);
    else {
      if(!st.empty()) {
	int next = st.top();
	st.pop();
	dp[i] = (i - next + 1) + (next > 0 ? dp[next-1] : 0);
	ans = max(ans, dp[i]);
      }
    }
  }
  return ans;
}

int main() {
  string str = "()";
  printf("%d\n", longestValidParentheses(str));
  return 0;
}
