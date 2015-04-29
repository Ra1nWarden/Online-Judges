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

class ProblemSets {
public:
  bool valid(long long mid, long long E, long long EM, long long M, long long MH, long long H) {
    EM -= max((mid - E), 0LL);
    MH -= max((mid - H), 0LL);
    if(EM < 0 || MH < 0)
      return false;
    return M + EM + MH >= mid; 
  }
  long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
    long long left = min(min(E, M), H);
    long long right = max(max(E + EM, EM + M), max(EM + M, MH + H));
    while(left != right) {
      long long mid = (((left + right) >> 1) + 1);
      if(valid(mid, E, EM, M, MH, H)) {
	left = mid;
      } else {
	right = mid - 1;
      }
    }
    return left;
  }
};

// @begin_tests
void _run_test(long long E, long long EM, long long M, long long MH, long long H, long long res_expected, int test_no) {
long long tc_res = (new ProblemSets)->maxSets(E, EM, M, MH, H);
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
long long E;
long long EM;
long long M;
long long MH;
long long H;
long long res_expected;
E = 2LL;
EM = 2LL;
M = 1LL;
MH = 2LL;
H = 2LL;
res_expected = 3LL;
_run_test(E, EM, M, MH, H, res_expected, 0);
E = 100LL;
EM = 100LL;
M = 100LL;
MH = 0LL;
H = 0LL;
res_expected = 0LL;
_run_test(E, EM, M, MH, H, res_expected, 1);
E = 657LL;
EM = 657LL;
M = 657LL;
MH = 657LL;
H = 657LL;
res_expected = 1095LL;
_run_test(E, EM, M, MH, H, res_expected, 2);
E = 1LL;
EM = 2LL;
M = 3LL;
MH = 4LL;
H = 5LL;
res_expected = 3LL;
_run_test(E, EM, M, MH, H, res_expected, 3);
E = 1000000000000000000LL;
EM = 1000000000000000000LL;
M = 1000000000000000000LL;
MH = 1000000000000000000LL;
H = 1000000000000000000LL;
res_expected = 1666666666666666666LL;
_run_test(E, EM, M, MH, H, res_expected, 4);
}
// @end_tests

// Born in Emacs
