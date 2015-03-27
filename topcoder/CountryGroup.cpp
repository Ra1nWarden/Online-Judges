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

class CountryGroup {
public:
  int solve(vector <int> a) {
    int res = 0;
    bool ok = true;
    for(int i = 0; i < a.size(); i++) {
      int n = a[i];
      int ncpy = n - 1;
      res++;
      while(ncpy-- && i < a.size()) {
	i++;
	if(a[i] != n) {
	  ok = false;
	  break;
	}
      }
      if(!ok)
	break;
    }
    return ok ? res : -1;
  }
};

// @begin_tests
void _run_test(vector< int > a, int res_expected, int test_no) {
int tc_res = (new CountryGroup)->solve(a);
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
vector< int > a;
int res_expected;
{int tmpa[] = {2, 2, 3, 3, 3};
a.assign(tmpa, tmpa + 5);}
res_expected = 2;
_run_test(a, res_expected, 0);
{int tmpa[] = {1, 1, 1, 1, 1};
a.assign(tmpa, tmpa + 5);}
res_expected = 5;
_run_test(a, res_expected, 1);
{int tmpa[] = {3, 3};
a.assign(tmpa, tmpa + 2);}
res_expected = -1;
_run_test(a, res_expected, 2);
{int tmpa[] = {4, 4, 4, 4, 1, 1, 2, 2, 3, 3, 3};
a.assign(tmpa, tmpa + 11);}
res_expected = 5;
_run_test(a, res_expected, 3);
{int tmpa[] = {2, 1, 2, 2, 1, 2};
a.assign(tmpa, tmpa + 6);}
res_expected = -1;
_run_test(a, res_expected, 4);
}
// @end_tests

// Born in Emacs
