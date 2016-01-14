#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

class WaterTank {
public:
  double minOutputRate(vector <int> t, vector <int> x, int C) {
    double eps = 1e-8;
    double left = 0, right = 1000000;
    while(fabs(left - right) > eps) {
      double mid = (left + right) / 2;
      double water = 0;
      bool small = false;
      for(int i = 0; i < t.size(); i++) {
	if(x[i] > mid) {
	  water += ((double) x[i] - mid) * (double) t[i];
	  if(water > C) {
	    small = true;
	    break;
	  }
	} else {
	  water = max(0.0, (double) water - (mid - (double) x[i]) * (double) t[i]);
	}
      }
      if(small) {
	left = mid;
      } else {
	right = mid;
      }
    }
    return left;
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
void _run_test(vector< int > t, vector< int > x, int C, double res_expected, int test_no) {
double tc_res = (new WaterTank)->minOutputRate(t, x, C);
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
vector< int > t;
vector< int > x;
int C;
double res_expected;
{int tmpa[] = {3, 3};
t.assign(tmpa, tmpa + 2);}
{int tmpa[] = {1, 2};
x.assign(tmpa, tmpa + 2);}
C = 3;
res_expected = 0.9999999999999999;
_run_test(t, x, C, res_expected, 0);
{int tmpa[] = {1, 2, 3, 4, 5};
t.assign(tmpa, tmpa + 5);}
{int tmpa[] = {5, 4, 3, 2, 1};
x.assign(tmpa, tmpa + 5);}
C = 10;
res_expected = 1.9999999999999996;
_run_test(t, x, C, res_expected, 1);
{int tmpa[] = {5949, 3198, 376, 3592, 4019, 3481, 5609, 3840, 6092, 4059};
t.assign(tmpa, tmpa + 10);}
{int tmpa[] = {29, 38, 96, 84, 10, 2, 39, 27, 76, 94};
x.assign(tmpa, tmpa + 10);}
C = 1000000000;
res_expected = 0.0;
_run_test(t, x, C, res_expected, 2);
{int tmpa[] = {9, 3, 4, 8, 1, 2, 5, 7, 6};
t.assign(tmpa, tmpa + 9);}
{int tmpa[] = {123, 456, 789, 1011, 1213, 1415, 1617, 1819, 2021};
x.assign(tmpa, tmpa + 9);}
C = 11;
res_expected = 2019.1666666666665;
_run_test(t, x, C, res_expected, 3);
{int tmpa[] = {100};
t.assign(tmpa, tmpa + 1);}
{int tmpa[] = {1000};
x.assign(tmpa, tmpa + 1);}
C = 12345;
res_expected = 876.55;
_run_test(t, x, C, res_expected, 4);
}
// @end_tests

// Born in Emacs
