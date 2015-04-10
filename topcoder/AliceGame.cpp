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

class AliceGame {
public:
  long long findMinimumValue(long long x, long long y) {
    long long sum = x + y;
    long long n = 0;
    while(n * n < sum)
      n++;
    if(n * n != sum)
      return -1;
    long long bottom = 0, top = 0;
    for(int a = 0; a <= n; a++) {
      if((x+a) % 2 == 0) {
	if(bottom <= (x+a) / 2 && (x+a) / 2 <= top) {
	  return a;
	}
      }
      bottom += a + 1;
      top += (n - a);
    }
    return -1;
  }
};

// @begin_tests
void _run_test(long long x, long long y, long long res_expected, int test_no) {
long long tc_res = (new AliceGame)->findMinimumValue(x, y);
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
long long x;
long long y;
long long res_expected;
x = 8LL;
y = 17LL;
res_expected = 2LL;
_run_test(x, y, res_expected, 0);
x = 17LL;
y = 8LL;
res_expected = 3LL;
_run_test(x, y, res_expected, 1);
x = 0LL;
y = 0LL;
res_expected = 0LL;
_run_test(x, y, res_expected, 2);
x = 9LL;
y = 9LL;
res_expected = -1LL;
_run_test(x, y, res_expected, 3);
x = 500000LL;
y = 500000LL;
res_expected = 294LL;
_run_test(x, y, res_expected, 4);
}
// @end_tests

// Born in Emacs
