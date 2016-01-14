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

class ANewHope {
public:
  int calc(int cur, int old, int diff, int n) {
    int ans = 1;
    while(old > cur) {
      old += diff;
      if(old < n)
	old = 0;
      else
	old -= n;
      ans++;
    }
    return ans;
  }
  int count(vector <int> firstWeek, vector <int> lastWeek, int D) {
    int n = firstWeek.size();
    bool same = true;
    for(int i = 0; i < n; i++) {
      if(firstWeek[i] != lastWeek[i]) {
	same = false;
	break;
      }
    }
    if(same)
      return 1;
    int ans = 2;
    vector<int> idx(n + 1, -1);
    for(int i = 0; i < n; i++) {
      idx[firstWeek[i]] = i;
    }
    for(int i = 0; i < n; i++) {
      int new_idx = n + i;
      int diff = new_idx - idx[lastWeek[i]];
      if(diff < D) {
	ans = max(ans, calc(i, idx[lastWeek[i]], D, n));
      }
    }
    return ans;
  }
};

// @begin_tests
void _run_test(vector< int > firstWeek, vector< int > lastWeek, int D, int res_expected, int test_no) {
int tc_res = (new ANewHope)->count(firstWeek, lastWeek, D);
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
vector< int > firstWeek;
vector< int > lastWeek;
int D;
int res_expected;
{int tmpa[] = {1, 2, 3, 4};
firstWeek.assign(tmpa, tmpa + 4);}
{int tmpa[] = {4, 3, 2, 1};
lastWeek.assign(tmpa, tmpa + 4);}
D = 3;
res_expected = 4;
_run_test(firstWeek, lastWeek, D, res_expected, 0);
{int tmpa[] = {8, 5, 4, 1, 7, 6, 3, 2};
firstWeek.assign(tmpa, tmpa + 8);}
{int tmpa[] = {2, 4, 6, 8, 1, 3, 5, 7};
lastWeek.assign(tmpa, tmpa + 8);}
D = 3;
res_expected = 3;
_run_test(firstWeek, lastWeek, D, res_expected, 1);
{int tmpa[] = {1, 2, 3, 4};
firstWeek.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, 2, 3, 4};
lastWeek.assign(tmpa, tmpa + 4);}
D = 2;
res_expected = 1;
_run_test(firstWeek, lastWeek, D, res_expected, 2);
}
// @end_tests

// Born in Emacs
