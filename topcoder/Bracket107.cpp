#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

// @begin_lib
// @end_lib

class Bracket107 {
public:
  bool valid(string s) {
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == '(')
	cnt++;
      if(s[i] == ')')
	cnt--;
      if(cnt < 0)
	return false;
    }
    return cnt == 0;
  }
  int yetanother(string s) {
    set<string> visited;
    for(int i = 0; i < s.length(); i++) {
      string substring = s.substr(0, i);
      if(i+1 < s.length())
	substring += s.substr(i+1);
      for(int j = 0; j <= substring.length(); j++) {
	string u = substring.substr(0, j);
	u += s[i];
	if(j < substring.length())
	  u += substring.substr(j);
	if(u != s && valid(u)) {
	  visited.insert(u);
	}
      }
    }
    return visited.size();
  }
};

// @begin_tests
void _run_test(string s, int res_expected, int test_no) {
int tc_res = (new Bracket107)->yetanother(s);
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
string s;
int res_expected;
s = "(())";
res_expected = 1;
_run_test(s, res_expected, 0);
s = "(())()";
res_expected = 3;
_run_test(s, res_expected, 1);
s = "()()()";
res_expected = 3;
_run_test(s, res_expected, 2);
s = "(((())))";
res_expected = 5;
_run_test(s, res_expected, 3);
s = "((())())";
res_expected = 9;
_run_test(s, res_expected, 4);
}
// @end_tests

// Born in Emacs
