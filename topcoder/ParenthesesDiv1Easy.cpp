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

class ParenthesesDiv1Easy {
public:
  vector <int> correct(string s) {
    
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
void _run_test(string s, vector< int > res_expected, int test_no) {
vector< int > tc_res = (new ParenthesesDiv1Easy)->correct(s);
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
string s;
vector< int > res_expected;
s = ")(";
{int tmpa[] = {0, 0, 1, 1};
res_expected.assign(tmpa, tmpa + 4);}
_run_test(s, res_expected, 0);
s = "))))))((((((";
{int tmpa[] = {0, 5, 6, 11};
res_expected.assign(tmpa, tmpa + 4);}
_run_test(s, res_expected, 1);
s = "))()())()";
{int tmpa[] = {-1};
res_expected.assign(tmpa, tmpa + 1);}
_run_test(s, res_expected, 2);
s = ")()(((";
{int tmpa[] = {0, 0, 3, 3, 5, 5};
res_expected.assign(tmpa, tmpa + 6);}
_run_test(s, res_expected, 3);
s = "()";
res_expected.clear();
_run_test(s, res_expected, 4);
}
// @end_tests

// Born in Emacs
