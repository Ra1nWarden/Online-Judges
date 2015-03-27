#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#define MAXN 2005

using namespace std;

// @begin_lib
// @end_lib

class SingingEasy {
private:
  int dp[MAXN][MAXN];
  int f(int a, int b, vector<int>& v) {
    if(dp[a][b] != -1)
      return dp[a][b];
    if(a == v.size() || b == v.size())
      return dp[a][b] = 0;
    int next = max(a, b) + 1;
    return dp[a][b] = min(f(next, b, v) + (a ? abs(v[a-1] - v[next-1]) : 0), f(a, next, v) + (b ? abs(v[b-1] - v[next-1]) : 0));
  }
public:
  int solve(vector <int> pitch) {
    memset(dp, -1, sizeof dp);
    return f(0, 0, pitch);
  }
};

// @begin_tests
void _run_test(vector< int > pitch, int res_expected, int test_no) {
int tc_res = (new SingingEasy)->solve(pitch);
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
vector< int > pitch;
int res_expected;
{int tmpa[] = {1, 3, 8, 12, 13};
pitch.assign(tmpa, tmpa + 5);}
res_expected = 7;
_run_test(pitch, res_expected, 0);
{int tmpa[] = {1, 5, 6, 2, 1};
pitch.assign(tmpa, tmpa + 5);}
res_expected = 3;
_run_test(pitch, res_expected, 1);
{int tmpa[] = {5, 5, 5, 5, 4, 4, 4, 4};
pitch.assign(tmpa, tmpa + 8);}
res_expected = 0;
_run_test(pitch, res_expected, 2);
{int tmpa[] = {1000000};
pitch.assign(tmpa, tmpa + 1);}
res_expected = 0;
_run_test(pitch, res_expected, 3);
{int tmpa[] = {24, 13, 2, 4, 54, 23, 12, 53, 12, 23, 42, 13, 53, 12, 24, 12, 11, 24, 42, 52, 12, 32, 42};
pitch.assign(tmpa, tmpa + 23);}
res_expected = 188;
_run_test(pitch, res_expected, 4);
}
// @end_tests

// Born in Emacs
