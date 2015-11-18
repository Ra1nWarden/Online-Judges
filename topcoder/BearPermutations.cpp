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

const int maxn = 100;

class BearPermutations {
private:
  int dp[maxn+1][maxn+1][maxn+1];
  int mod;
public:
  int f(int len, int cap) {
    if(dp[len][cap] != -1)
      return dp[len][cap];
    int ans = (f(len-1, cap) * 1LL * 2) % mod;
    for(int i = 1; i <= len - 2; i++) {
      ans += f()
    }
  }
  int countPermutations(int N, int S, int MOD) {
    memset(dp, -1, sizeof dp);
    mod = MOD;
    return f(N, S);
  }
};

// @begin_tests
void _run_test(int N, int S, int MOD, int res_expected, int test_no) {
int tc_res = (new BearPermutations)->countPermutations(N, S, MOD);
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
int S;
int MOD;
int res_expected;
N = 3;
S = 1;
MOD = 71876209;
res_expected = 4;
_run_test(N, S, MOD, res_expected, 0);
N = 4;
S = 0;
MOD = 1000003;
res_expected = 8;
_run_test(N, S, MOD, res_expected, 1);
N = 4;
S = 1;
MOD = 483128897;
res_expected = 8;
_run_test(N, S, MOD, res_expected, 2);
N = 5;
S = 3;
MOD = 907283243;
res_expected = 82;
_run_test(N, S, MOD, res_expected, 3);
N = 5;
S = 100;
MOD = 101;
res_expected = 19;
_run_test(N, S, MOD, res_expected, 4);
N = 20;
S = 30;
MOD = 3;
res_expected = 2;
_run_test(N, S, MOD, res_expected, 5);
}
// @end_tests

// Born in Emacs
