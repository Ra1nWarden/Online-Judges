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

class Procrastination {
public:
  long long findFinalAssignee(long long n) {
    long long i = 2;
    for(; i * i <= n; i++) {
      if(n % i == 0)
	n++;
      else if(n % i == 1)
	n--;
    }
    for(i = n / i; i > 1; i--) {
      if(n % i == 0)
	n++;
      else if(n % i == 1)
	n--;
    }
    return n;
  }
};

// @begin_tests
void _run_test(long long n, long long res_expected, int test_no) {
long long tc_res = (new Procrastination)->findFinalAssignee(n);
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
long long n;
long long res_expected;
n = 3LL;
res_expected = 3LL;
_run_test(n, res_expected, 0);
n = 8LL;
res_expected = 11LL;
_run_test(n, res_expected, 1);
n = 20LL;
res_expected = 20LL;
_run_test(n, res_expected, 2);
n = 196248LL;
res_expected = 196259LL;
_run_test(n, res_expected, 3);
n = 5587021440LL;
res_expected = 5587021440LL;
_run_test(n, res_expected, 4);
}
// @end_tests

// Born in Emacs
