#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#define MAXN 255

using namespace std;

// @begin_lib
// @end_lib

class RandomPancakeStack {
private:
  int n;
  double dp[MAXN][MAXN];
public:
  double expectedDeliciousness(vector <int> d) {
    n = d.size();
    for(int maxi = 0; maxi <= n; maxi++) {
      for(int left = maxi; left <= n; left++) {
	if(maxi == 0) {
	  dp[maxi][left] = 0.0;
	} else {
	  dp[maxi][left] = 0.0;
	  for(int i = 1; i <= maxi; i++) {
	    dp[maxi][left] += 1.0 / left * (dp[i-1][left-1] + d[i - 1]);
	  }
	}
      }
    }
    return dp[n][n];
  }
};

// @begin_tests
bool _cmp_res(double expected, double got) {
  if (fabs(expected - got) < 1e-9) return 1;
  else {
    double a = (1.0 - 1e-9) * expected;
    double b = (1.0 + 1e-9) * expected;
    return got < max(a, b) && got > min(a, b);
  }
}
void _run_test(vector< int > d, double res_expected, int test_no) {
double tc_res = (new RandomPancakeStack)->expectedDeliciousness(d);
if (_cmp_res(res_expected, tc_res))
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
}
cout << "expected: ";
cout << res_expected;
cout << endl << "got: ";
cout << tc_res;
cout << endl;
}
int main() {
vector< int > d;
double res_expected;
{int tmpa[] = {1, 1, 1};
d.assign(tmpa, tmpa + 3);}
res_expected = 1.6666666666666667;
_run_test(d, res_expected, 0);
{int tmpa[] = {3, 6, 10, 9, 2};
d.assign(tmpa, tmpa + 5);}
res_expected = 9.891666666666667;
_run_test(d, res_expected, 1);
{int tmpa[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
d.assign(tmpa, tmpa + 10);}
res_expected = 10.999999724426809;
_run_test(d, res_expected, 2);
{int tmpa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
d.assign(tmpa, tmpa + 10);}
res_expected = 7.901100088183421;
_run_test(d, res_expected, 3);
{int tmpa[] = {2, 7, 1, 8, 2, 8, 1, 8, 2, 8, 4, 5, 90, 4, 5, 2, 3, 5, 60, 2, 8, 74, 7, 1};
d.assign(tmpa, tmpa + 24);}
res_expected = 19.368705050402465;
_run_test(d, res_expected, 4);
{int tmpa[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
d.assign(tmpa, tmpa + 100);}
res_expected = 1.718281828459045;
_run_test(d, res_expected, 5);
}
// @end_tests

// Born in Emacs
