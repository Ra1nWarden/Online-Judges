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

class ReplacingDigit {
private:
  int base(int i) {
    if(i == 0)
      return 1;
    else
      return base(i-1) * 10;
  }
public:
  int getMaximumStockWorth(vector <int> A, vector <int> D) {
    vector<int> digits[7];
    int sum = 0;
    for(int i = 0; i < A.size(); i++) {
      int num = A[i];
      sum += num;
      int j = 0;
      while(num) {
	digits[j].push_back(num % 10);
	num /= 10;
	j++;
      }
    }
    for(int i = 0; i < 7; i++)
      sort(digits[i].begin(), digits[i].end());
    for(int i = 9; i >= 1; i--) {
      int cnt = D[i-1];
      for(int j = 6; j >= 0 && cnt; j--) {
	for(int k = 0; k < digits[j].size() && cnt; k++) {
	  if(digits[j][k] >= i)
	    break;
	  sum += (i - digits[j][k]) * base(j);
	  digits[j][k] = i;
	  cnt--;
	}
	sort(digits[j].begin(), digits[j].end());
      }
      if(cnt != 0)
	break;
    }
    return sum;
  }
};

// @begin_tests
void _run_test(vector< int > A, vector< int > D, int res_expected, int test_no) {
int tc_res = (new ReplacingDigit)->getMaximumStockWorth(A, D);
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
vector< int > A;
vector< int > D;
int res_expected;
{int tmpa[] = {100, 90};
A.assign(tmpa, tmpa + 2);}
{int tmpa[] = {0, 0, 0, 0, 2, 1, 0, 0, 0};
D.assign(tmpa, tmpa + 9);}
res_expected = 745;
_run_test(A, D, res_expected, 0);
{int tmpa[] = {9};
A.assign(tmpa, tmpa + 1);}
{int tmpa[] = {1, 1, 1, 1, 1, 1, 1, 1, 0};
D.assign(tmpa, tmpa + 9);}
res_expected = 9;
_run_test(A, D, res_expected, 1);
{int tmpa[] = {123456};
A.assign(tmpa, tmpa + 1);}
{int tmpa[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
D.assign(tmpa, tmpa + 9);}
res_expected = 988777;
_run_test(A, D, res_expected, 2);
{int tmpa[] = {10, 970019, 1976, 10936, 68750, 756309, 37600, 559601, 6750, 76091, 640, 312, 312, 90, 8870};
A.assign(tmpa, tmpa + 15);}
{int tmpa[] = {11, 2, 8, 10, 7, 6, 3, 1, 3};
D.assign(tmpa, tmpa + 9);}
res_expected = 3297500;
_run_test(A, D, res_expected, 3);
{int tmpa[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
A.assign(tmpa, tmpa + 22);}
{int tmpa[] = {111, 111, 111, 111, 111, 111, 111, 111, 111};
D.assign(tmpa, tmpa + 9);}
res_expected = 198;
_run_test(A, D, res_expected, 4);
}
// @end_tests

// Born in Emacs
