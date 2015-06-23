#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#define MAXN 305

using namespace std;

// @begin_lib
// @end_lib

class Bitwisdom {
private:
  double pv[MAXN];
  int n;
public:
  double expectedActions(vector <int> p) {
    n = p.size();
    double ans = 0;
    double allone = 1.0;
    for(int i = 0; i < p.size(); i++)
      pv[i] = p[i] * 1.0 / 100;
    for(int i = 0; i < p.size(); i++) {
      allone *= p[i] * 1.0 / 100;
      if(i > 0)
	ans += ((1 - pv[i]) * pv[i-1] + (1 - pv[i-1]) * pv[i]);
    }
    ans += allone;
    return ans;
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
void _run_test(vector< int > p, double res_expected, int test_no) {
double tc_res = (new Bitwisdom)->expectedActions(p);
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
vector< int > p;
double res_expected;
{int tmpa[] = {100, 100, 100};
p.assign(tmpa, tmpa + 3);}
res_expected = 1.0;
_run_test(p, res_expected, 0);
{int tmpa[] = {50, 50};
p.assign(tmpa, tmpa + 2);}
res_expected = 0.75;
_run_test(p, res_expected, 1);
{int tmpa[] = {0, 40, 50, 60};
p.assign(tmpa, tmpa + 4);}
res_expected = 1.4;
_run_test(p, res_expected, 2);
{int tmpa[] = {37, 63, 23, 94, 12};
p.assign(tmpa, tmpa + 5);}
res_expected = 2.6820475464;
_run_test(p, res_expected, 3);
}
// @end_tests

// Born in Emacs
