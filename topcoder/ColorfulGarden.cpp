#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

const int alpha = 26;
int number[alpha];
typedef pair<int, char> Node;
Node chars[alpha];

class ColorfulGarden {
public:
  vector <string> rearrange(vector <string> garden) {
    int len = garden[0].length();
    memset(number, 0, sizeof number);
    for(int i = 0; i < garden.size(); i++) {
      for(int j = 0; j < garden[i].length(); j++) {
	number[garden[i][j] - 'a']++;
      }
    }
    vector<string> ans;
    int ci = 0;
    for(int i = 0; i < alpha; i++) {
      if(number[i] > len)
	return ans;
      if(number[i] > 0)
	chars[ci++] = make_pair(number[i], 'a' + i);
    }
    sort(chars, chars+ci, greater<pair<int, char> >());
    string s(len, ' ');
    ans.push_back(s);
    ans.push_back(s);
    ci = 0;
    int row = 0;
    for(int i = 0; i < len; i++) {
      while(chars[ci].first == 0) {
	ci++;
      }
      ans[row][i] = chars[ci].second;
      chars[ci].first--;
      row = !row;
    }
    row = 1;
    for(int i = 0; i < len; i++) {
      while(chars[ci].first == 0) {
	ci++;
      }
      ans[row][i] = chars[ci].second;
      chars[ci].first--;
      row = !row;
    }
    return ans;
  }
};

// @begin_tests
void _print_res(ostream& str, vector< string > v) {
  bool first = 1;
  str << "{";
  for (vector< string >::iterator i = v.begin(); i != v.end(); i++) {
    if (first) {
      str << " ";
      first = 0;
    } else
      str << ", ";
    str << '"' << *i << '"';
  }
  str << " }";
}
void _run_test(vector< string > garden, vector< string > res_expected, int test_no) {
vector< string > tc_res = (new ColorfulGarden)->rearrange(garden);
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
vector< string > garden;
vector< string > res_expected;
{string tmpa[] = {"aa", "bb"};
garden.assign(tmpa, tmpa + 2);}
{string tmpa[] = {"ab", "ba"};
res_expected.assign(tmpa, tmpa + 2);}
_run_test(garden, res_expected, 0);
{string tmpa[] = {"xxxx", "xxxx"};
garden.assign(tmpa, tmpa + 2);}
res_expected.clear();
_run_test(garden, res_expected, 1);
{string tmpa[] = {"abcd", "abcd"};
garden.assign(tmpa, tmpa + 2);}
{string tmpa[] = {"abcd", "dcba"};
res_expected.assign(tmpa, tmpa + 2);}
_run_test(garden, res_expected, 2);
{string tmpa[] = {"abcdefghijklm", "nopqrstuvwxyz"};
garden.assign(tmpa, tmpa + 2);}
{string tmpa[] = {"abcdefghijklm", "nopqrstuvwxyz"};
res_expected.assign(tmpa, tmpa + 2);}
_run_test(garden, res_expected, 3);
{string tmpa[] = {"aaa", "aab"};
garden.assign(tmpa, tmpa + 2);}
res_expected.clear();
_run_test(garden, res_expected, 4);
}
// @end_tests

// Born in Emacs
