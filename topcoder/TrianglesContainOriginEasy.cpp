#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#define EPS 2e-8

using namespace std;

// @begin_lib
// @end_lib

class TrianglesContainOriginEasy {
private:
  double distanceSq(int x1, int y1, int x2, int y2) {
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
  }
  double angleCos(double a2, double b2, double c2) {
    return acos((a2 + b2 - c2) / (2 * sqrt(a2 * b2)));
  }
public:
  int count(vector <int> x, vector <int> y) {
    int result = 0;
    for(int i = 0; i < x.size() - 2; i++) {
      for(int j = i + 1; j < x.size() - 1; j++) {
	for(int k = j + 1; k < x.size(); k++) {
	  double ji = distanceSq(x[i], y[i], x[j], y[j]);
	  double iz = distanceSq(x[i], y[i], 0, 0);
	  double ik = distanceSq(x[i], y[i], x[k], y[k]);
	  double jz = distanceSq(x[j], y[j], 0, 0);
	  double kz = distanceSq(x[k], y[k], 0, 0);
	  double jk = distanceSq(x[j], y[j], x[k], y[k]);
	  double jiz = angleCos(ji, iz, jz);
	  double kiz = angleCos(iz, ik, kz);
	  double jik = angleCos(ji, ik, jk);
	  if(fabs(jiz + kiz - jik) < EPS) {
	    double ijz = angleCos(ji, jz, iz);
	    double zjk = angleCos(jz, jk, kz);
	    double ijk = angleCos(ji, jk, ik);
	    if(fabs(ijz + zjk - ijk) < EPS)
	      result++;
	  }
	}
      }
    }
    return result;
  }
};

// @begin_tests
void _run_test(vector< int > x, vector< int > y, int res_expected, int test_no) {
int tc_res = (new TrianglesContainOriginEasy)->count(x, y);
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
vector< int > x;
vector< int > y;
int res_expected;
{int tmpa[] = {-1, -1, 1};
x.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1, -1, 0};
y.assign(tmpa, tmpa + 3);}
res_expected = 1;
_run_test(x, y, res_expected, 0);
{int tmpa[] = {-1, -1, 1, 2};
x.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, -1, 2, -1};
y.assign(tmpa, tmpa + 4);}
res_expected = 2;
_run_test(x, y, res_expected, 1);
{int tmpa[] = {-1, -2, 3, 3, 2, 1};
x.assign(tmpa, tmpa + 6);}
{int tmpa[] = {-2, -1, 1, 2, 3, 3};
y.assign(tmpa, tmpa + 6);}
res_expected = 8;
_run_test(x, y, res_expected, 2);
{int tmpa[] = {1, 5, 10, 5, -5, 7, -9, -6, -3, 0, 8, 8, 1, -4, 7, -3, 10, 9, -6};
x.assign(tmpa, tmpa + 19);}
{int tmpa[] = {5, -6, -3, 4, -2, -8, -7, 2, 7, 4, 2, 0, -4, -8, 7, 5, -5, -2, -9};
y.assign(tmpa, tmpa + 19);}
res_expected = 256;
_run_test(x, y, res_expected, 3);
}
// @end_tests

// Born in Emacs
