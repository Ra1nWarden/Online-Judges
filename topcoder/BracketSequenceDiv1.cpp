#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

class BracketSequenceDiv1 {
private:
  static const int maxn = 40;
  long long dp[maxn+1][maxn+1];
  long long f(int i, int j, const string& s) {
    if(i >= j)
      return 1;
    if(dp[i][j] != -1)
      return dp[i][j];
    long long ans;
    if(s[j] == '(' || s[j] == '[') {
      return dp[i][j] = f(i, j-1, s);
    } else if(s[j] == ')') {
      ans = f(i, j-1, s);
      for(int jj = j - 1; jj >= i; jj--) {
	if(s[jj] == '(')
	  ans += f(i, jj - 1, s) * f(jj + 1, j - 1, s);
      }
    } else {
      ans = f(i, j-1, s);
      for(int jj = j - 1; jj >= i; jj--) {
	if(s[jj] == '[')
	  ans += f(i, jj - 1, s) * f(jj + 1, j - 1, s);
      }
    }
    return dp[i][j] = ans;
  }
public:
  long long count(string s) {
    memset(dp, -1, sizeof dp);
    return f(0, s.length() - 1, s) - 1;
  }
};

// @begin_tests
void _run_test(string s, long long res_expected, int test_no) {
long long tc_res = (new BracketSequenceDiv1)->count(s);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
cout << res_expected;
cout << endl << "got: ";
cout << tc_res;
cout << endl;
}
}
int main() {
string s;
long long res_expected;
s = "()[]";
res_expected = 3LL;
_run_test(s, res_expected, 0);
s = "())";
res_expected = 2LL;
_run_test(s, res_expected, 1);
s = "()()";
res_expected = 4LL;
_run_test(s, res_expected, 2);
s = "([)]";
res_expected = 2LL;
_run_test(s, res_expected, 3);
s = "())[]][]([]()]]()]]]";
res_expected = 3854LL;
_run_test(s, res_expected, 4);
}
// @end_tests

// Born in Emacs
