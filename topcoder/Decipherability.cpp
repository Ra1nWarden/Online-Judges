#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

class Decipherability {
public:
  string check(string s, int K) {
    if(K == s.length())
      return "Certain";
    int prev[26];
    int mindist = 100;
    memset(prev, -1, sizeof prev);
    for(int i=  0; i < s.length(); i++) {
      char curchar = s[i];
      if(prev[curchar - 'a'] == -1) {
	prev[curchar - 'a'] = i;
      } else {
	mindist = min(mindist, i - prev[curchar - 'a'] - 1);
	prev[curchar - 'a'] = i;
      }
    }
    if(mindist == 100) {
      return "Certain";
    }
    else if(K > mindist)
      return "Uncertain";
    else
      return "Certain";
  }
};

// @begin_tests
void _run_test(string s, int K, string res_expected, int test_no) {
string tc_res = (new Decipherability)->check(s, K);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
cout << '"' << res_expected << '"';
cout << endl << "got: ";
cout << '"' << tc_res << '"';
cout << endl;
}
}
int main() {
string s;
int K;
string res_expected;
s = "snuke";
K = 2;
res_expected = "Certain";
_run_test(s, K, res_expected, 0);
s = "aba";
K = 1;
res_expected = "Certain";
_run_test(s, K, res_expected, 1);
s = "aba";
K = 2;
res_expected = "Uncertain";
_run_test(s, K, res_expected, 2);
s = "abcdabcd";
K = 3;
res_expected = "Certain";
_run_test(s, K, res_expected, 3);
s = "koukyoukoukokukikou";
K = 2;
res_expected = "Uncertain";
_run_test(s, K, res_expected, 4);
s = "wolfsothe";
K = 8;
res_expected = "Uncertain";
_run_test(s, K, res_expected, 5);
s = "aa";
K = 2;
res_expected = "Certain";
_run_test(s, K, res_expected, 6);
 s = "abcdefg";
 K = 1;
 res_expected = "Certain";
 _run_test(s, K, res_expected, 7);
 s = "aa";
 K = 1;
 res_expected = "Uncertain";
 _run_test(s, K, res_expected, 8);
 s = "abaaba";
 K = 2;
 res_expected = "Uncertain";
 _run_test(s, K, res_expected, 9);
 s = "aaa";
 K = 2;
 res_expected = "Uncertain";
 _run_test(s, K, res_expected, 10);
}
// @end_tests

// Born in Emacs
