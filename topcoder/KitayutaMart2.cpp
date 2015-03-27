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

class KitayutaMart2 {
public:
  int numBought(int K, int T) {
    int res = 0;
    int power = (T / K) + 1;
    while(power != 1) {
      power >>= 1;
      res++;
    }
    return res;
  }
};

// @begin_tests
void _run_test(int K, int T, int res_expected, int test_no) {
int tc_res = (new KitayutaMart2)->numBought(K, T);
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
int K;
int T;
int res_expected;
K = 100;
T = 100;
res_expected = 1;
_run_test(K, T, res_expected, 0);
K = 100;
T = 300;
res_expected = 2;
_run_test(K, T, res_expected, 1);
K = 150;
T = 1050;
res_expected = 3;
_run_test(K, T, res_expected, 2);
K = 160;
T = 163680;
res_expected = 10;
_run_test(K, T, res_expected, 3);
}
// @end_tests

// Born in Emacs
