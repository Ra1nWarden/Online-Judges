#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstring>
#define MAXS 200005

using namespace std;

// @begin_lib
// @end_lib

class WaitingForBus {
private:
  double dp[MAXS];
  vector<int> t;
  vector<int> p;
  int ss;
public:
  double f(int tt) {
    if(dp[tt] > -1)
      return dp[tt];
    if(tt >= ss)
      return dp[tt] = tt - ss;
    else {
      double res = 0.0;
      for(int i = 0; i < t.size(); i++) {
	res += f(tt + t[i]) * (double) p[i] / 100.0;
      }
      return dp[tt] = res;
    }
  }

  double whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
    t = time;
    p = prob;
    ss = s;
    memset(dp, -1, sizeof dp);
    return f(0);
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
void _run_test(vector< int > time, vector< int > prob, int s, double res_expected, int test_no) {
double tc_res = (new WaitingForBus)->whenWillBusArrive(time, prob, s);
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
vector< int > time;
vector< int > prob;
int s;
double res_expected;
{int tmpa[] = {5, 100};
time.assign(tmpa, tmpa + 2);}
{int tmpa[] = {90, 10};
prob.assign(tmpa, tmpa + 2);}
s = 5;
res_expected = 9.5;
_run_test(time, prob, s, res_expected, 0);
{int tmpa[] = {5};
time.assign(tmpa, tmpa + 1);}
{int tmpa[] = {100};
prob.assign(tmpa, tmpa + 1);}
s = 101;
res_expected = 4.0;
_run_test(time, prob, s, res_expected, 1);
{int tmpa[] = {5, 10};
time.assign(tmpa, tmpa + 2);}
{int tmpa[] = {50, 50};
prob.assign(tmpa, tmpa + 2);}
s = 88888;
res_expected = 3.666666666666667;
_run_test(time, prob, s, res_expected, 2);
{int tmpa[] = {1, 2, 3, 4};
time.assign(tmpa, tmpa + 4);}
{int tmpa[] = {10, 20, 30, 40};
prob.assign(tmpa, tmpa + 4);}
s = 1000;
res_expected = 1.166666666666667;
_run_test(time, prob, s, res_expected, 3);
{int tmpa[] = {10, 100, 1000, 10000, 100000};
time.assign(tmpa, tmpa + 5);}
{int tmpa[] = {90, 4, 3, 2, 1};
prob.assign(tmpa, tmpa + 5);}
s = 100000;
res_expected = 21148.147303578935;
_run_test(time, prob, s, res_expected, 4);
}
// @end_tests

// Born in Emacs
