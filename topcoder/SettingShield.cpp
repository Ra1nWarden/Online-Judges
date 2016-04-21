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

class SettingShield {
public:
  long long getOptimalCost(int n, int h, int t, vector <int> val0, vector <int> a, vector <int> b, vector <int> m) {
    vector<int> left(h), right(h), protection(n);
    protection[0] = val0[0];
    for(int i = 1; i < n; i++) {
      protection[i] = (a[0] * 1LL * protection[i-1] + b[0]) % m[0];
    }
    left[0] = val0[0];
    right[0] = val0[0];
    for(int i = 1; i < h; i++) {
      left[i] = min(n-1, (int)((a[1] * 1LL * left[i-1] + b[1]) % m[1]));
      long long dist = (long long) right[i-1] - left[i-1];
      right[i] = min(n-1, left[i] + (int)((a[2] * 1LL * dist + b[2]) % m[2]));
    }
    
  }
};

// @begin_tests
void _run_test(int n, int h, int t, vector< int > val0, vector< int > a, vector< int > b, vector< int > m, long long res_expected, int test_no) {
long long tc_res = (new SettingShield)->getOptimalCost(n, h, t, val0, a, b, m);
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
int n;
int h;
int t;
vector< int > val0;
vector< int > a;
vector< int > b;
vector< int > m;
long long res_expected;
n = 3;
h = 3;
t = 10;
{int tmpa[] = {4, 0, 1};
val0.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1, 1, 1};
a.assign(tmpa, tmpa + 3);}
{int tmpa[] = {3, 1, 1};
b.assign(tmpa, tmpa + 3);}
{int tmpa[] = {6, 10, 10};
m.assign(tmpa, tmpa + 3);}
res_expected = 8LL;
_run_test(n, h, t, val0, a, b, m, res_expected, 0);
n = 3;
h = 1;
t = 10;
{int tmpa[] = {4, 0, 1};
val0.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1, 1, 1};
a.assign(tmpa, tmpa + 3);}
{int tmpa[] = {3, 1, 1};
b.assign(tmpa, tmpa + 3);}
{int tmpa[] = {6, 10, 10};
m.assign(tmpa, tmpa + 3);}
res_expected = 40LL;
_run_test(n, h, t, val0, a, b, m, res_expected, 1);
n = 6;
h = 3;
t = 2;
{int tmpa[] = {4, 1, 3};
val0.assign(tmpa, tmpa + 3);}
{int tmpa[] = {2, 4, 3};
a.assign(tmpa, tmpa + 3);}
{int tmpa[] = {3, 2, 2};
b.assign(tmpa, tmpa + 3);}
{int tmpa[] = {20, 9, 4};
m.assign(tmpa, tmpa + 3);}
res_expected = 22LL;
_run_test(n, h, t, val0, a, b, m, res_expected, 2);
n = 12;
h = 6;
t = 4;
{int tmpa[] = {4, 3, 7};
val0.assign(tmpa, tmpa + 3);}
{int tmpa[] = {2, 4, 5};
a.assign(tmpa, tmpa + 3);}
{int tmpa[] = {3, 8, 7};
b.assign(tmpa, tmpa + 3);}
{int tmpa[] = {40, 23, 13};
m.assign(tmpa, tmpa + 3);}
res_expected = 108LL;
_run_test(n, h, t, val0, a, b, m, res_expected, 3);
n = 50;
h = 77;
t = 4;
{int tmpa[] = {4, 11, 30};
val0.assign(tmpa, tmpa + 3);}
{int tmpa[] = {9, 40, 7};
a.assign(tmpa, tmpa + 3);}
{int tmpa[] = {33, 8, 12};
b.assign(tmpa, tmpa + 3);}
{int tmpa[] = {20000, 200, 13};
m.assign(tmpa, tmpa + 3);}
res_expected = 79111LL;
_run_test(n, h, t, val0, a, b, m, res_expected, 4);
n = 555;
h = 120;
t = 4;
{int tmpa[] = {10000000, 301, 520};
val0.assign(tmpa, tmpa + 3);}
{int tmpa[] = {9999999, 9999998, 9999997};
a.assign(tmpa, tmpa + 3);}
{int tmpa[] = {9995999, 0, 9919999};
b.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1999999, 9993999, 9299999};
m.assign(tmpa, tmpa + 3);}
res_expected = 40000000LL;
_run_test(n, h, t, val0, a, b, m, res_expected, 5);
n = 501;
h = 2;
t = 2;
{int tmpa[] = {10000000, 500, 500};
val0.assign(tmpa, tmpa + 3);}
{int tmpa[] = {10000000, 10000000, 10000000};
a.assign(tmpa, tmpa + 3);}
{int tmpa[] = {0, 0, 500};
b.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1000003, 10000000, 10000000};
m.assign(tmpa, tmpa + 3);}
res_expected = 10000000LL;
_run_test(n, h, t, val0, a, b, m, res_expected, 6);
}
// @end_tests

// Born in Emacs
