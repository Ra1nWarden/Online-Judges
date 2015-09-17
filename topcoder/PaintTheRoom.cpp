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

class PaintTheRoom {
public:
  string canPaintEvenly(int R, int C, int K) {
    if(R > C)
      return canPaintEvenly(C, R, K);
    if(K == 1)
      return "Paint";
    if(R * C % 2)
      return "Cannot paint";
    return "Paint";
  }
};

// @begin_tests
void _run_test(int R, int C, int K, string res_expected, int test_no) {
string tc_res = (new PaintTheRoom)->canPaintEvenly(R, C, K);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
cout << '"' << res_expected << '"';
cout << endl << "got: ";
cout << '"' << tc_res << '"';
cout << endl;
}
}
int main() {
int R;
int C;
int K;
string res_expected;
R = 1;
C = 1;
K = 1;
res_expected = "Paint";
_run_test(R, C, K, res_expected, 0);
R = 1;
C = 1;
K = 2;
res_expected = "Cannot paint";
_run_test(R, C, K, res_expected, 1);
R = 1;
C = 2;
K = 2;
res_expected = "Paint";
_run_test(R, C, K, res_expected, 2);
R = 2;
C = 2;
K = 3;
res_expected = "Paint";
_run_test(R, C, K, res_expected, 3);
}
// @end_tests

// Born in Emacs
