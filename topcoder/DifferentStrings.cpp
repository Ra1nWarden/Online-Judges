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

class DifferentStrings {
public:
  int minimize(string A, string B) {
    return 0;
  }
};

// @begin_tests
void _run_test(string A, string B, int res_expected, int test_no) {
  int tc_res = (new DifferentStrings)->minimize(A, B);
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
  string A;
  string B;
  int res_expected;
  A = "koder";
  B = "topcoder";
  res_expected = 1;
  _run_test(A, B, res_expected, 0);
  A = "hello";
  B = "xello";
  res_expected = 1;
  _run_test(A, B, res_expected, 1);
  A = "abc";
  B = "topabcoder";
  res_expected = 0;
  _run_test(A, B, res_expected, 2);
  A = "adaabc";
  B = "aababbc";
  res_expected = 2;
  _run_test(A, B, res_expected, 3);
  A = "giorgi";
  B = "igroig";
  res_expected = 6;
  _run_test(A, B, res_expected, 4);
}
// @end_tests

// Born in Emacs
