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

class BuyingTshirts {
public:
  int meet(int T, vector <int> Q, vector <int> P) {
      int qmoney = 0;
      int pmoney = 0;
      int result = 0;
      for(int i = 0; i < min(P.size(), Q.size()); i++) {
	  qmoney += Q[i];
	  pmoney += P[i];
	  bool pbuy = false;
	  bool qbuy = false;
	  if(pmoney >= T) {
	      pbuy = true;
	      pmoney -= T;
	  }
	  if(qmoney >= T) {
	      qbuy = true;
	      qmoney -= T;
	  }
	  if(pbuy && qbuy)
	    result++;
      }
      return result;
  }
};

// @begin_tests
void _run_test(int T, vector< int > Q, vector< int > P, int res_expected, int test_no) {
int tc_res = (new BuyingTshirts)->meet(T, Q, P);
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
int T;
vector< int > Q;
vector< int > P;
int res_expected;
T = 5;
{int tmpa[] = {1, 2, 3, 4, 5};
Q.assign(tmpa, tmpa + 5);}
{int tmpa[] = {5, 4, 3, 2, 1};
P.assign(tmpa, tmpa + 5);}
res_expected = 2;
_run_test(T, Q, P, res_expected, 0);
T = 10;
{int tmpa[] = {10, 10, 10};
Q.assign(tmpa, tmpa + 3);}
{int tmpa[] = {10, 10, 10};
P.assign(tmpa, tmpa + 3);}
res_expected = 3;
_run_test(T, Q, P, res_expected, 1);
T = 2;
{int tmpa[] = {1, 2, 1, 2, 1, 2, 1, 2};
Q.assign(tmpa, tmpa + 8);}
{int tmpa[] = {1, 1, 1, 1, 2, 2, 2, 2};
P.assign(tmpa, tmpa + 8);}
res_expected = 5;
_run_test(T, Q, P, res_expected, 2);
T = 100;
{int tmpa[] = {1, 2, 3};
Q.assign(tmpa, tmpa + 3);}
{int tmpa[] = {4, 5, 6};
P.assign(tmpa, tmpa + 3);}
res_expected = 0;
_run_test(T, Q, P, res_expected, 3);
T = 10;
{int tmpa[] = {10, 1, 10, 1};
Q.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, 10, 1, 10};
P.assign(tmpa, tmpa + 4);}
res_expected = 0;
_run_test(T, Q, P, res_expected, 4);
}
// @end_tests

// Born in Emacs
