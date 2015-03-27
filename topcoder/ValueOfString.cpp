#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

// @begin_lib
// @end_lib

class ValueOfString {
private:
  int letters[26];
  int count[26];
public:
  int findValue(string s) {
    memset(letters, 0, sizeof letters);
    int res = 0;
    for(int i = 0; i < s.length(); i++) {
      letters[s[i] - 'a']++;
    }
    count[0] = letters[0];
    for(int i = 1; i < 26; i++) {
      count[i] = letters[i] + count[i-1];
    }
    for(int i = 0; i < s.length(); i++) {
      res += count[s[i] - 'a'] * (s[i] - 'a' +1);
    }
    return res;
  }
};

// @begin_tests
void _run_test(string s, int res_expected, int test_no) {
int tc_res = (new ValueOfString)->findValue(s);
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
s = "babca";
res_expected = 35;
_run_test(s, res_expected, 0);
s = "zz";
res_expected = 104;
_run_test(s, res_expected, 1);
s = "y";
res_expected = 25;
_run_test(s, res_expected, 2);
s = "aaabbc";
res_expected = 47;
_run_test(s, res_expected, 3);
s = "topcoder";
res_expected = 558;
_run_test(s, res_expected, 4);
s = "thequickbrownfoxjumpsoverthelazydog";
res_expected = 11187;
_run_test(s, res_expected, 5);
s = "zyxwvutsrqponmlkjihgfedcba";
res_expected = 6201;
_run_test(s, res_expected, 6);
}
// @end_tests

// Born in Emacs
