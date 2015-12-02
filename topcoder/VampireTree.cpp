#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

// @begin_lib
// @end_lib

class VampireTree {
private:
  int n;
public:
  int maxDistance(vector <int> num) {
    int sum = 0;
    n = num.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      sum += num[i];
      if(num[i] != 1)
	cnt++;
    }
    if(sum + 2 != 2 * n) {
      return -1;
    }
    return cnt+1;
  }
};

// @begin_tests
void _run_test(vector< int > num, int res_expected, int test_no) {
int tc_res = (new VampireTree)->maxDistance(num);
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
vector< int > num;
int res_expected;
{int tmpa[] = {1, 2, 1};
num.assign(tmpa, tmpa + 3);}
res_expected = 2;
_run_test(num, res_expected, 0);
{int tmpa[] = {2, 2, 2};
num.assign(tmpa, tmpa + 3);}
res_expected = -1;
_run_test(num, res_expected, 1);
{int tmpa[] = {1, 1, 1, 1, 4};
num.assign(tmpa, tmpa + 5);}
res_expected = 2;
_run_test(num, res_expected, 2);
{int tmpa[] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
num.assign(tmpa, tmpa + 20);}
res_expected = -1;
_run_test(num, res_expected, 3);
}
// @end_tests

// Born in Emacs
