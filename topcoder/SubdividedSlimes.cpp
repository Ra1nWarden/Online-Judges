#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

typedef pair<int, int> II;

class SubdividedSlimes {
private:
  map<II, int> memo;
public:
  pair<int, int> sort_three(int a, int b, int c) {
    int v[3] = {a, b, c};
    sort(v, v+3);
    return make_pair(c, b);
  }
  int f(int largest, int target, int next) {
    II k = make_pair(largest, target);
    if(memo.count(k))
      return memo[k];
    if(target <= 0) {
      return memo[k] = 0;
    }
    if(largest == 1)
      return memo[k] = -1;
    int ans = -1;
    for(int i = 1; i < largest; i++) {
      int prod = i * (largest - i);
      int j = largest - i;
      pair<int, int> sub_ans = sort_three(i, j, next);
      int sub = f(sub_ans.first, target - prod, sub_ans.second);
      if(sub != -1) {
	if(ans == -1 || ans > sub + 1) {
	  ans = sub + 1;
	}
      }
    }
    return memo[k] = ans;
  }
  int needCut(int S, int M) {
    return f(S, M, 0);
  }
};

// @begin_tests
void _run_test(int S, int M, int res_expected, int test_no) {
int tc_res = (new SubdividedSlimes)->needCut(S, M);
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
int S;
int M;
int res_expected;
S = 3;
M = 2;
res_expected = 1;
_run_test(S, M, res_expected, 0);
S = 3;
M = 3;
res_expected = 2;
_run_test(S, M, res_expected, 1);
S = 3;
M = 4;
res_expected = -1;
_run_test(S, M, res_expected, 2);
S = 765;
M = 271828;
res_expected = 14;
_run_test(S, M, res_expected, 3);
}
// @end_tests

// Born in Emacs
