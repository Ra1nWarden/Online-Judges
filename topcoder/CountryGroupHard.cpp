#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#define MAXN 105

using namespace std;

// @begin_lib
// @end_lib

class CountryGroupHard {
private:
  int n;
  vector<int> aa;
  int dp[MAXN][MAXN];
public:
  bool ok(int start, int end) {
    int len = end - start + 1;
    for(int i = start; i <= end; i++) {
      if(aa[i] != 0 && aa[i] != len)
	return false;
    }
    return true;
  }

  int f(int start, int end) {
    if(dp[start][end] != -1)
      return dp[start][end];
    int ans = ok(start, end) ? 1 : 0;
    for(int i = start; i < end; i++) {
      if(ok(start, i))
	ans += f(i + 1, end);
    }
    return dp[start][end] = ans;
  }

  string solve(vector <int> a) {
    n = a.size();
    aa = a;
    memset(dp, -1, sizeof dp);
    return f(0, n - 1) == 1 ? "Sufficient" : "Insufficient";
  }
};

// @begin_tests
void _run_test(vector< int > a, string res_expected, int test_no) {
string tc_res = (new CountryGroupHard)->solve(a);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
cout << '"' << res_expected << '"';
cout << endl << "got: ";
cout << '"' << tc_res << '"';
cout << endl;
}
}
int main() {
vector< int > a;
string res_expected;
{int tmpa[] = {0, 2, 3, 0, 0};
a.assign(tmpa, tmpa + 5);}
res_expected = "Sufficient";
_run_test(a, res_expected, 0);
{int tmpa[] = {0, 2, 0};
a.assign(tmpa, tmpa + 3);}
res_expected = "Insufficient";
_run_test(a, res_expected, 1);
{int tmpa[] = {0, 3, 0, 0, 3, 0};
a.assign(tmpa, tmpa + 6);}
res_expected = "Sufficient";
_run_test(a, res_expected, 2);
{int tmpa[] = {0, 0, 3, 3, 0, 0};
a.assign(tmpa, tmpa + 6);}
res_expected = "Insufficient";
_run_test(a, res_expected, 3);
{int tmpa[] = {2, 2, 0, 2, 2};
a.assign(tmpa, tmpa + 5);}
res_expected = "Sufficient";
_run_test(a, res_expected, 4);
}
// @end_tests

// Born in Emacs
