#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

// @begin_lib
// @end_lib

const int maxn = 200;
const int mod = 1e9+7;
int dp[maxn+1][maxn/3+1][maxn/3+1];
string str;
int n;

class BearCries {
public:
  int f(int i, int a, int b) {
    if(i == n) {
      if(a == 0 && b == 0) {
	return dp[i][a][b] = 1;
      } else {
	return dp[i][a][b] = 0;
      }
    }
    int ans = 0;
    if(str[i] == '_') {
      ans += (f(i+1, a, b) * 1LL * a) % mod;
      if(b > 0)
	ans += (f(i+1, a+1, b-1) * 1LL * b) % mod;
    } else {
      if(b < n / 3)
	ans += f(i+1, a, b+1);
      if(a > 0)
	ans += (f(i+1, a-1, b) * 1LL * a) % mod;
    }
    return dp[i][a][b] = ans % mod;
  }
  int count(string message) {
    str = message;
    n = str.length();
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0);
  }
};

// @begin_tests
void _run_test(string message, int res_expected, int test_no) {
int tc_res = (new BearCries)->count(message);
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
string message;
int res_expected;
message = ";_;;_____;";
res_expected = 2;
_run_test(message, res_expected, 0);
message = ";;;___;;;";
res_expected = 36;
_run_test(message, res_expected, 1);
message = "_;__;";
res_expected = 0;
_run_test(message, res_expected, 2);
message = ";_____________________________________;";
res_expected = 1;
_run_test(message, res_expected, 3);
message = ";__;____;";
res_expected = 0;
_run_test(message, res_expected, 4);
message = ";_;;__;_;;";
res_expected = 52;
_run_test(message, res_expected, 5);
}
// @end_tests

// Born in Emacs
