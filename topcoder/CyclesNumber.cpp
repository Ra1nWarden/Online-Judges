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

class CyclesNumber {
private:
  static const int mod = 1000000007;
public:
  int sterling(int a, int b) {
    if(b == 1 || b == a)
      return 1;
    else
      return sterling(a-1, b-1) + (b * 1LL * sterling(a-1, b)) % mod;
  }
  int power(int b, int p) {
    if(p == 0)
      return 1;
    int base = power(b, p / 2);
    int ans = (base * 1LL * base) % mod;
    if(p & 1)
      ans = (ans * 1LL * b) % mod;
    return ans;
  }
  int calc(int n, int m) {
    int ans = 0;
    for(int len = 1; len <= n; len++) {
      ans = ((long long) ans + (sterling(n, len) * 1LL * power(len, m)) % mod) % mod;
    }
    return ans;
  }
  vector <int> getExpectation(vector <int> n, vector <int> m) {
    vector<int> ans;
    for(int i = 0; i < n.size(); i++) {
      int nn = n[i];
      int mm = m[i];
      ans.push_back(calc(nn, mm));
    }
    return ans;
  }
};

// @begin_tests
void _print_res(ostream& str, vector< int > v) {
  bool first = 1;
  str << "{";
  for (vector< int >::iterator i = v.begin(); i != v.end(); i++) {
    if (first) {
      str << " ";
      first = 0;
    } else
      str << ", ";
    str << *i;
  }
  str << " }";
}
void _run_test(vector< int > n, vector< int > m, vector< int > res_expected, int test_no) {
vector< int > tc_res = (new CyclesNumber)->getExpectation(n, m);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
_print_res(cout, res_expected);
cout << endl << "got: ";
_print_res(cout, tc_res);
cout << endl;
}
}
int main() {
vector< int > n;
vector< int > m;
vector< int > res_expected;
{int tmpa[] = {2};
n.assign(tmpa, tmpa + 1);}
{int tmpa[] = {2};
m.assign(tmpa, tmpa + 1);}
{int tmpa[] = {5};
res_expected.assign(tmpa, tmpa + 1);}
_run_test(n, m, res_expected, 0);
{int tmpa[] = {3};
n.assign(tmpa, tmpa + 1);}
{int tmpa[] = {0};
m.assign(tmpa, tmpa + 1);}
{int tmpa[] = {6};
res_expected.assign(tmpa, tmpa + 1);}
_run_test(n, m, res_expected, 1);
{int tmpa[] = {1, 2, 3};
n.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1, 3, 3};
m.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1, 9, 53};
res_expected.assign(tmpa, tmpa + 3);}
_run_test(n, m, res_expected, 2);
{int tmpa[] = {10, 20, 30};
n.assign(tmpa, tmpa + 3);}
{int tmpa[] = {10, 20, 30};
m.assign(tmpa, tmpa + 3);}
{int tmpa[] = {586836447, 544389755, 327675273};
res_expected.assign(tmpa, tmpa + 3);}
_run_test(n, m, res_expected, 3);
}
// @end_tests

// Born in Emacs
