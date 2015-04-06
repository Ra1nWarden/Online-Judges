#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

class TrianglesContainOrigin {
public:
  long long count(vector <int> x, vector <int> y) {
    long long n = x.size();
    long long ans = n * (n - 1) * (n - 2) / 6;
    long long sub = 0;
    for(int i = 0; i < x.size(); i++) {
      int k = 0;
      for(int j = 0; j < x.size(); j++) {
	if(i == j)
	  continue;
	if((0 - x[i]) * (y[j] - y[i]) - (x[j] - x[i]) * (0 - y[i]) < 0)
	  k++;
      }
      sub += (k * (k - 1) / 2);
    }
    return ans - sub;
  }
};

// @begin_tests
void _run_test(vector< int > x, vector< int > y, long long res_expected, int test_no) {
long long tc_res = (new TrianglesContainOrigin)->count(x, y);
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
long long res_expected;
{int tmpa[] = {-1, -1, 1};
x.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1, -1, 0};
y.assign(tmpa, tmpa + 3);}
res_expected = 1LL;
_run_test(x, y, res_expected, 0);
{int tmpa[] = {-1, -1, 1, 2};
x.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, -1, 2, -1};
y.assign(tmpa, tmpa + 4);}
res_expected = 2LL;
_run_test(x, y, res_expected, 1);
{int tmpa[] = {-1, -2, 3, 3, 2, 1};
x.assign(tmpa, tmpa + 6);}
{int tmpa[] = {-2, -1, 1, 2, 3, 3};
y.assign(tmpa, tmpa + 6);}
res_expected = 8LL;
_run_test(x, y, res_expected, 2);
{int tmpa[] = {1, 5, 10, 5, -5, 7, -9, -6, -3, 0, 8, 8, 1, -4, 7, -3, 10, 9, -6};
x.assign(tmpa, tmpa + 19);}
{int tmpa[] = {5, -6, -3, 4, -2, -8, -7, 2, 7, 4, 2, 0, -4, -8, 7, 5, -5, -2, -9};
y.assign(tmpa, tmpa + 19);}
res_expected = 256LL;
_run_test(x, y, res_expected, 3);
}
// @end_tests

// Born in Emacs
