#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#define MAXN 55

using namespace std;

// @begin_lib
// @end_lib

class GreaterGame {
private:
  bool seen[MAXN*2];
public:
  double calc(vector <int> hand, vector <int> sothe) {
    memset(seen, false, sizeof seen);
    for(int i = 0; i < hand.size(); i++)
      seen[hand[i]] = true;
    for(int i = 0; i < sothe.size(); i++) {
      if(sothe[i] != -1)
	seen[sothe[i]] = true;
    }
    vector<int> left;
    for(int i= 1; i <= hand.size() * 2; i++) {
      if(!seen[i])
	left.push_back(i);
    }

    sort(hand.begin(), hand.end());

    double ans = 0.0;

    for(int i = 0; i < sothe.size(); i++) {
      if(sothe[i] != -1) {
	vector<int>::iterator rmv = upper_bound(hand.begin(), hand.end(), sothe[i]);
	if(rmv == hand.end()) {
	  hand.erase(hand.begin());
	} else {
	  ans += 1.0;
	  hand.erase(rmv);
	}
      }
    }

    for(int i = 0; i < hand.size(); i++) {
      int cnt = upper_bound(left.begin(), left.end(), hand[i]) - left.begin();
      ans += ((double) cnt / left.size());
    }

    return ans;
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
void _run_test(vector< int > hand, vector< int > sothe, double res_expected, int test_no) {
double tc_res = (new GreaterGame)->calc(hand, sothe);
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
vector< int > hand;
vector< int > sothe;
double res_expected;
{int tmpa[] = {4, 2};
hand.assign(tmpa, tmpa + 2);}
{int tmpa[] = {-1, -1};
sothe.assign(tmpa, tmpa + 2);}
res_expected = 1.5;
_run_test(hand, sothe, res_expected, 0);
{int tmpa[] = {4, 2};
hand.assign(tmpa, tmpa + 2);}
{int tmpa[] = {1, 3};
sothe.assign(tmpa, tmpa + 2);}
res_expected = 2.0;
_run_test(hand, sothe, res_expected, 1);
{int tmpa[] = {2};
hand.assign(tmpa, tmpa + 1);}
{int tmpa[] = {-1};
sothe.assign(tmpa, tmpa + 1);}
res_expected = 1.0;
_run_test(hand, sothe, res_expected, 2);
{int tmpa[] = {1, 3, 5, 7};
hand.assign(tmpa, tmpa + 4);}
{int tmpa[] = {8, -1, 4, -1};
sothe.assign(tmpa, tmpa + 4);}
res_expected = 2.5;
_run_test(hand, sothe, res_expected, 3);
{int tmpa[] = {6, 12, 17, 14, 20, 8, 16, 7, 2, 15};
hand.assign(tmpa, tmpa + 10);}
{int tmpa[] = {-1, -1, 4, -1, 11, 3, 13, -1, -1, 18};
sothe.assign(tmpa, tmpa + 10);}
res_expected = 8.0;
_run_test(hand, sothe, res_expected, 4);
}
// @end_tests

// Born in Emacs
