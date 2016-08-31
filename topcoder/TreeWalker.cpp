#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

const int mod = 1000000007;
const int maxn = 100000;

class TreeWalker {
private:
  int dp[maxn+5][2];
  int A[maxn+5];
  vector<int> adjMat[maxn+5];
  int dist[]
  void dfs(int u) {
    visited[u] = true;
    for(int i = 0; i < adjMat[u].size(); i++) {
      int v = adjMat[v];
      if(!visited[v]) {
	pa[v] = u;
	dfs(v);
      }
    }
  }
public:
  int calc(int N, int A0, int B, int C, int MOD) {
    A[0] = A0;
    for(int i = 1; i <= N-2; i++) {
      A[i] = (B * 1LL * A[i-1] + C) % MOD;
    }
    for(int i = 1; i <= N-1; i++) {
      int j = A[i-1] % i;
      adjMat[i].push_back(j);
      adjMat[j].push_back(i);
    }
  }
};

// @begin_tests
void _run_test(int N, int A0, int B, int C, int MOD, int res_expected, int test_no) {
int tc_res = (new TreeWalker)->calc(N, A0, B, C, MOD);
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
int A0;
int B;
int C;
int MOD;
int res_expected;
N = 4;
A0 = 0;
B = 1;
C = 1;
MOD = 1000;
res_expected = 34;
_run_test(N, A0, B, C, MOD, res_expected, 0);
N = 10;
A0 = 0;
B = 0;
C = 0;
MOD = 1;
res_expected = 13824;
_run_test(N, A0, B, C, MOD, res_expected, 1);
N = 16;
A0 = 15;
B = 1;
C = 1;
MOD = 16;
res_expected = 917506;
_run_test(N, A0, B, C, MOD, res_expected, 2);
N = 1000;
A0 = 385498676;
B = 349131547;
C = 115776323;
MOD = 614879544;
res_expected = 245566366;
_run_test(N, A0, B, C, MOD, res_expected, 3);
N = 100000;
A0 = 111222333;
B = 444555666;
C = 777888999;
MOD = 123456789;
res_expected = 119729770;
_run_test(N, A0, B, C, MOD, res_expected, 4);
}
// @end_tests

// Born in Emacs
