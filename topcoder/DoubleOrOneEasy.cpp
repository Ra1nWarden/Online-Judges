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

class DoubleOrOneEasy {
public:
  int minimalSteps(int a, int b, int newA, int newB) {
    int diff = b - a;
    int newDiff = newB - newA;
    if(diff == 0) {
      if(a > newA || newDiff != 0) 
	return -1;
      int ans = 0;
      while(newA != a) {
	if(newA % 2 == 0 && newA >= a * 2){
	  newA >>= 1;
	  newB >>= 1;
	  ans++;
	} else {
	  newA--;
	  newB--;
	  ans++;
	}
      }
      return ans;
    }
    int mult = newDiff / diff;
    if(mult * diff != newDiff)
      return -1;
    if(mult <= 0)
      return -1;
    int multcpy = mult;
    int ans = 0;
    while(multcpy > 1) {
      if(multcpy & 1)
	return -1;
      multcpy >>= 1;
      ans++;
    }
    int add = newA - a * mult;
    if(add < 0)
      return -1;
    int base = 1 << ans;
    while(add && base) {
      ans += add / base;
      add %= base;
      base >>= 1;
    }
    return ans;
  }
};

// @begin_tests
void _run_test(int a, int b, int newA, int newB, int res_expected, int test_no) {
int tc_res = (new DoubleOrOneEasy)->minimalSteps(a, b, newA, newB);
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
int a;
int b;
int newA;
int newB;
int res_expected;
a = 100;
b = 1000;
newA = 101;
newB = 1001;
res_expected = 1;
_run_test(a, b, newA, newB, res_expected, 0);
a = 100;
b = 1000;
newA = 202;
newB = 2002;
res_expected = 2;
_run_test(a, b, newA, newB, res_expected, 1);
a = 2;
b = 2;
newA = 1;
newB = 1;
res_expected = -1;
_run_test(a, b, newA, newB, res_expected, 2);
a = 1;
b = 111111111;
newA = 8;
newB = 888888888;
res_expected = 3;
_run_test(a, b, newA, newB, res_expected, 3);
a = 1;
b = 111111111;
newA = 9;
newB = 999999999;
res_expected = -1;
_run_test(a, b, newA, newB, res_expected, 4);
}
// @end_tests

// Born in Emacs
