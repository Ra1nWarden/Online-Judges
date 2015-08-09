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

class ModModMod {
public:
  long long findSum(vector <int> m, int R) {
    vector<int> mm;
    for(int i = 0; i < m.size(); i++) {
      if(mm.empty() || m[i] < mm.back()) {
	mm.push_back(m[i]);
      }
    }
    vector<int> rv;
    for(int i = mm.size() - 1; i > -1; i--) {
      
    }
  }
};

// @begin_tests
void _run_test(vector< int > m, int R, long long res_expected, int test_no) {
long long tc_res = (new ModModMod)->findSum(m, R);
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
vector< int > m;
int R;
long long res_expected;
{int tmpa[] = {5, 3, 2};
m.assign(tmpa, tmpa + 3);}
R = 10;
res_expected = 4LL;
_run_test(m, R, res_expected, 0);
{int tmpa[] = {33, 15, 7, 10, 100, 9, 5};
m.assign(tmpa, tmpa + 7);}
R = 64;
res_expected = 92LL;
_run_test(m, R, res_expected, 1);
{int tmpa[] = {995, 149, 28, 265, 275, 107, 555, 241, 702, 462, 519, 212, 362, 478, 783, 381, 602, 546, 183, 886, 59, 317, 977, 612, 328, 91, 771, 131};
m.assign(tmpa, tmpa + 28);}
R = 992363;
res_expected = 12792005LL;
_run_test(m, R, res_expected, 2);
{int tmpa[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
m.assign(tmpa, tmpa + 96);}
R = 100;
res_expected = 4950LL;
_run_test(m, R, res_expected, 3);
{int tmpa[] = {2934};
m.assign(tmpa, tmpa + 1);}
R = 10000000;
res_expected = 14664070144LL;
_run_test(m, R, res_expected, 4);
}
// @end_tests

// Born in Emacs
