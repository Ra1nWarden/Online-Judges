#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXL 1005
#define SIGMA 26

using namespace std;

// @begin_lib
// @end_lib

class SquareScores {
private:
  double dp[MAXL][SIGMA];
  bool unknown[MAXL];
public:
  double calcexpectation(vector <int> p, string s) {
    while(p.size() != 26)
      p.push_back(0);
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= s.length(); i++) {
      char ch = s[i-1];
      if(ch == '?') {
	for(int k = 0; k < p.size(); k++) {
	  if(p[k] == 0)
	    continue;
	  ch = 'a' + k;
	  if(i - 2 > -1 ? unknown[i-2] : false) {
	    for(int j = 0; j < SIGMA; j++) {
	      if(dp[i-1][j] != 0)
		dp[i][ch - 'a'] += ((double)p[j] / 100) * (dp[i-1][j] + 1);
	    }
	  } else {
	    dp[i][ch - 'a'] = i - 2 > -1 ? dp[i-1][s[i-2] - 'a'] + 1 : 1;
	  }
	  
	  double prob = 1;
	  for(int j = i - 1; j > 0; j--) {
	    if(dp[j][ch - 'a'] == 0)
	      break;
	    prob *= unknown[j-1] ? ((double)p[ch - 'a']) /100 : 1;
	    dp[i][ch - 'a'] += prob;
	  }
	}
	unknown[i-1] = true;
      } else {
	if(i - 2 > -1 ? unknown[i-2] : false) {
	  for(int j = 0; j < SIGMA; j++) {
	    if(dp[i-1][j] != 0)
	      dp[i][ch - 'a'] += ((double)p[j] / 100) * (dp[i-1][j] + 1);
	  }
	} else {
	  dp[i][ch - 'a'] = i - 2 > -1 ? dp[i-1][s[i-2] - 'a'] + 1 : 1;
	}

	double prob = 1;
	for(int j = i - 1; j > 0; j--) {
	  if(dp[j][ch - 'a'] == 0)
	    break;
	  prob *= unknown[j-1] ? ((double)p[ch - 'a']) /100 : 1;
	  dp[i][ch - 'a'] += prob;
	}

	unknown[i-1] = false;
      }
    }
    if(unknown[s.length() - 1]) {
      double ans = 0.0;
      for(int i = 0; i < 26; i++)
	ans += ((double)p[i] / 100) * dp[s.length()][i];
      return ans;
    } else {
      return dp[s.length()][s[s.length() - 1] - 'a'];
    }
  }
};

// @begin_tests
bool _cmp_res(double expected, double got) {
  if (fabs(expected - got) < 1e-9) return 1;
  else {
    double a = (1.0 - 1e-9) * expected;
    double b = (1.0 + 1e-9) * expected;
    return got < max(a, b) && got > min(a, b);
  }
}
void _run_test(vector< int > p, string s, double res_expected, int test_no) {
double tc_res = (new SquareScores)->calcexpectation(p, s);
if (_cmp_res(res_expected, tc_res))
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
}
cout << "expected: ";
cout << res_expected;
cout << endl << "got: ";
cout << tc_res;
cout << endl;
}
int main() {
vector< int > p;
string s;
double res_expected;
{int tmpa[] = {1, 99};
p.assign(tmpa, tmpa + 2);}
s = "aaaba";
res_expected = 8.0;
_run_test(p, s, res_expected, 0);
{int tmpa[] = {10, 20, 70};
p.assign(tmpa, tmpa + 3);}
s = "aa?bbbb";
res_expected = 15.0;
_run_test(p, s, res_expected, 1);
{int tmpa[] = {10, 20, 30, 40};
p.assign(tmpa, tmpa + 4);}
s = "a??c?dc?b";
res_expected = 11.117;
_run_test(p, s, res_expected, 2);
{int tmpa[] = {25, 25, 21, 2, 2, 25};
p.assign(tmpa, tmpa + 6);}
s = "a??b???????ff??e";
res_expected = 21.68512690712425;
_run_test(p, s, res_expected, 3);
{int tmpa[] = {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4};
p.assign(tmpa, tmpa + 26);}
s = "??????????????????????????????";
res_expected = 31.16931963781721;
_run_test(p, s, res_expected, 4);
{int tmpa[] = {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3};
p.assign(tmpa, tmpa + 26);}
s = "makigotapresentfromniko";
res_expected = 23.0;
_run_test(p, s, res_expected, 5);
}
// @end_tests

// Born in Emacs
