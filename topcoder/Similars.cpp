#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

// @begin_lib
// @end_lib

class Similars {
private:
  set<int> seen;
public:
  set<int> digits(int num) {
    set<int> ans;
    while(num > 0) {
      ans.insert(num % 10);
      num /= 10;
    }
    return ans;
  }
  int countbits(int x) {
    int ans = 0;
    for(int i = 0; i < 10; i++) {
      if((x & (1 << i)) != 0)
	ans++;
    }
    return ans;
  }

  int maxsim(int L, int R) {
    int ans = 0;
    for(int num = L; num <= R; num++) {
      set<int> digs = digits(num);
      int mask = 0;
      for(set<int>::iterator itr = digs.begin(); itr != digs.end(); itr++) {
	mask = (mask | (1 << (*itr)));
      }
      for(set<int>::iterator itr = seen.begin(); itr != seen.end(); itr++) {
	int prev = *itr;
	ans = max(ans, countbits(prev & mask));
      }
      seen.insert(mask);
    }
    return ans;
  }
};

// @begin_tests
void _run_test(int L, int R, int res_expected, int test_no) {
int tc_res = (new Similars)->maxsim(L, R);
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
int L;
int R;
int res_expected;
L = 1;
R = 10;
res_expected = 1;
_run_test(L, R, res_expected, 0);
L = 1;
R = 99;
res_expected = 2;
_run_test(L, R, res_expected, 1);
L = 99;
R = 100;
res_expected = 0;
_run_test(L, R, res_expected, 2);
L = 1000;
R = 1010;
res_expected = 2;
_run_test(L, R, res_expected, 3);
L = 444;
R = 454;
res_expected = 2;
_run_test(L, R, res_expected, 4);
L = 1;
R = 100000;
res_expected = 5;
_run_test(L, R, res_expected, 5);
}
// @end_tests

// Born in Emacs
