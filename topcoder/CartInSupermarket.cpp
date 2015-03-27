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

class CartInSupermarket {
public:
  int calcmin(vector <int> a, int b) {
    
  }
};

// @begin_tests
void _run_test(vector< int > a, int b, int res_expected, int test_no) {
int tc_res = (new CartInSupermarket)->calcmin(a, b);
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
vector< int > a;
int b;
int res_expected;
{int tmpa[] = {8};
a.assign(tmpa, tmpa + 1);}
b = 3;
res_expected = 4;
_run_test(a, b, res_expected, 0);
{int tmpa[] = {6, 6, 5};
a.assign(tmpa, tmpa + 3);}
b = 3;
res_expected = 4;
_run_test(a, b, res_expected, 1);
{int tmpa[] = {12, 5, 6, 2, 6, 8};
a.assign(tmpa, tmpa + 6);}
b = 4;
res_expected = 6;
_run_test(a, b, res_expected, 2);
{int tmpa[] = {15, 20, 11, 13, 18, 24, 25, 21, 22, 10, 15, 14, 19};
a.assign(tmpa, tmpa + 13);}
b = 0;
res_expected = 25;
_run_test(a, b, res_expected, 3);
{int tmpa[] = {671122748, 846444748, 84701624, 608579554, 672060899, 967957440, 31438849, 734849843, 376589643, 904285209, 80693344, 211737743, 85405464, 444633541, 293184188, 935462519, 146753109, 972886045, 496631016, 601669536, 257574086, 958464570, 6294570, 546189534, 668105964, 601197313, 784337929, 921840143, 70408284, 722040626, 253400894, 56411549, 811940644, 152086353, 122638884, 776352066, 118932182, 177589709, 538122558, 127914469, 523761221, 290027568, 734517444, 819458123, 699130727, 784698122, 810265337, 283326309, 593596316, 368671876};
a.assign(tmpa, tmpa + 50);}
b = 6478;
res_expected = 3805054;
_run_test(a, b, res_expected, 4);
}
// @end_tests

// Born in Emacs
