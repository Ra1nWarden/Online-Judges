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

class OddEvenTree {
public:
  bool check_sym(vector<string>& x, int n) {
    for(int i = 0; i < n; i++) {
      if(x[i][i] != 'E') {
        return false;
      }
      for(int j = i+1; j < n; j++) {
	if(x[i][j] != x[j][i]) {
	  return false;
	}
      }
    }
    return true;
  }
  bool check_poss(vector<string>& x, int n) {
    for(int i = 1; i < n; i++) {
      for(int j = i+1; j < n; j++) {
	bool iodd = x[0][i] == 'O';
	bool jodd = x[0][j] == 'O';
	bool ijodd = x[i][j] == 'O';
	if(iodd && jodd) {
	  if(ijodd)
	    return false;
	} else if(iodd || jodd) {
	  if(!ijodd)
	    return false;
	} else {
	  if(ijodd)
	    return false;
	}
      }
    }
    return true;
  }
  bool check_odd(vector<string>& x, int n) {
    for(int i = 1; i < n; i++) {
      if(x[0][i] == 'O')
	return true;
    }
    return false;
  }
  vector <int> getTree(vector <string> x) {
    int n = x.size();
    vector<int> ans;
    if(check_sym(x, n) && check_poss(x, n) && check_odd(x, n)) {
      vector<int> odds, evens;
      for(int i = 1; i < n; i++) {
	if(x[0][i] == 'E') {
	  evens.push_back(i);
	} else {
	  odds.push_back(i);
	}
      }
      for(int i = 0; i < odds.size(); i++) {
	ans.push_back(0);
	ans.push_back(odds[i]);
      }
      for(int i = 0; i < evens.size(); i++) {
	ans.push_back(odds[0]);
	ans.push_back(evens[i]);
      }
      return ans;
    } else {
      ans.push_back(-1);
      return ans;
    }
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
void _run_test(vector< string > x, vector< int > res_expected, int test_no) {
vector< int > tc_res = (new OddEvenTree)->getTree(x);
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
vector< string > x;
vector< int > res_expected;
{string tmpa[] = {"EOE", "OEO", "EOE"};
x.assign(tmpa, tmpa + 3);}
{int tmpa[] = {0, 1, 2, 1};
res_expected.assign(tmpa, tmpa + 4);}
_run_test(x, res_expected, 0);
{string tmpa[] = {"EO", "OE"};
x.assign(tmpa, tmpa + 2);}
{int tmpa[] = {0, 1};
res_expected.assign(tmpa, tmpa + 2);}
_run_test(x, res_expected, 1);
{string tmpa[] = {"OO", "OE"};
x.assign(tmpa, tmpa + 2);}
{int tmpa[] = {-1};
res_expected.assign(tmpa, tmpa + 1);}
_run_test(x, res_expected, 2);
{string tmpa[] = {"EO", "EE"};
x.assign(tmpa, tmpa + 2);}
{int tmpa[] = {-1};
res_expected.assign(tmpa, tmpa + 1);}
_run_test(x, res_expected, 3);
{string tmpa[] = {"EOEO", "OEOE", "EOEO", "OEOE"};
x.assign(tmpa, tmpa + 4);}
{int tmpa[] = {0, 1, 0, 3, 2, 1};
res_expected.assign(tmpa, tmpa + 6);}
_run_test(x, res_expected, 4);
}
// @end_tests

// Born in Emacs
