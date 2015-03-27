#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#define MOD 1000000007
#define MAXN 2005

using namespace std;

// @begin_lib
// @end_lib

class RockPaperScissorsMagicEasy {
private:
  int dp[MAXN][MAXN];
public:
  int f(int n, int s) {
    if(dp[n][s] != -1)
      return dp[n][s];
    if(s == n) {
      return dp[n][s] = 1;
    }
    if(s > n) {
      return dp[n][s] = 0;
    }
    if(n == 1) {
      return dp[n][s] = s == 1 ? 1 : 2;
    }
    return dp[n][s] = s == 0 ? ((long long) f(n-1, s) * 2) % MOD : ((long long) f(n-1, s)*2 + (long long) f(n-1, s - 1)) % MOD;
  }
  int count(vector <int> card, int score) {
    memset(dp, -1, sizeof dp);
    return f(card.size(), score);
  }
};

// @begin_tests
void _run_test(vector< int > card, int score, int res_expected, int test_no) {
int tc_res = (new RockPaperScissorsMagicEasy)->count(card, score);
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
vector< int > card;
int score;
int res_expected;
{int tmpa[] = {0, 1, 2};
card.assign(tmpa, tmpa + 3);}
score = 2;
res_expected = 6;
_run_test(card, score, res_expected, 0);
{int tmpa[] = {1, 2};
card.assign(tmpa, tmpa + 2);}
score = 0;
res_expected = 4;
_run_test(card, score, res_expected, 1);
{int tmpa[] = {2, 2, 1, 0, 0};
card.assign(tmpa, tmpa + 5);}
score = 10;
res_expected = 0;
_run_test(card, score, res_expected, 2);
{int tmpa[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
card.assign(tmpa, tmpa + 33);}
score = 7;
res_expected = 286226628;
_run_test(card, score, res_expected, 3);
{int tmpa[] = {0, 1, 2, 0, 1, 2, 2, 1, 0};
card.assign(tmpa, tmpa + 9);}
score = 8;
res_expected = 18;
_run_test(card, score, res_expected, 4);
}
// @end_tests

// Born in Emacs
