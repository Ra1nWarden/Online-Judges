#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

// @begin_lib
// @end_lib

class BearPlays {
private:
  int power_mod(int base, int k, int mod) {
    if(k == 0)
      return 1;
    int sub_ans = power_mod(base, k / 2, mod);
    int ans = sub_ans * 1LL * sub_ans % mod;
    if(k % 2) {
      ans = ans * 1LL * base % mod;
    }
    return ans;
  }
public:
  int pileSize(int A, int B, int K) {
    int sum = A + B;
    int res = power_mod(2, K, sum);
    int a = A * 1LL * res % sum;
    int b = sum - a;
    return min(a, b);
  }
};

// @begin_tests
void _run_test(int A, int B, int K, int res_expected, int test_no) {
int tc_res = (new BearPlays)->pileSize(A, B, K);
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
int A;
int B;
int K;
int res_expected;
A = 4;
B = 7;
K = 2;
res_expected = 5;
_run_test(A, B, K, res_expected, 0);
A = 5;
B = 5;
K = 3;
res_expected = 0;
_run_test(A, B, K, res_expected, 1);
A = 2;
B = 6;
K = 1;
res_expected = 4;
_run_test(A, B, K, res_expected, 2);
A = 2;
B = 8;
K = 2000000000;
res_expected = 2;
_run_test(A, B, K, res_expected, 3);
A = 900000000;
B = 350000000;
K = 3;
res_expected = 300000000;
_run_test(A, B, K, res_expected, 4);
A = 1;
B = 1000000000;
K = 2000000000;
res_expected = 224136384;
_run_test(A, B, K, res_expected, 5);
}
// @end_tests

// Born in Emacs
