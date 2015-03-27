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

class ThePermutationGameDiv2 {
private:
  long long res[36];
  long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
  }
  long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
  }
public:
  long long findMin(int N) {
    res[1] = 1;
    for(long long i = 2; i <= N; i++) {
      res[i] = lcm(res[i-1], i);
    }
    return res[N];
  }
};

// @begin_tests
void _run_test(int N, long long res_expected, int test_no) {
long long tc_res = (new ThePermutationGameDiv2)->findMin(N);
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
int N;
long long res_expected;
N = 2;
res_expected = 2LL;
_run_test(N, res_expected, 0);
N = 3;
res_expected = 6LL;
_run_test(N, res_expected, 1);
N = 6;
res_expected = 60LL;
_run_test(N, res_expected, 2);
N = 11;
res_expected = 27720LL;
_run_test(N, res_expected, 3);
N = 25;
res_expected = 26771144400LL;
_run_test(N, res_expected, 4);
}
// @end_tests

// Born in Emacs
