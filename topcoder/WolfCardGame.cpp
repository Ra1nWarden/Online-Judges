#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

class WolfCardGame {
public:
  vector <int> createAnswer(int N, int K) {
    int i;
    for(i = 2; i <= 100; i++) {
      if(N % i > 0) {
	break;
      }
    }
    vector<int> ans;
    for(int j = 1; j <= K; j++) {
      if(i * j <= 100)
	ans.push_back(i * j);
    }
    if(ans.size() < K)
      ans.push_back(1);
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
void _run_test(int N, int K, vector< int > res_expected, int test_no) {
vector< int > tc_res = (new WolfCardGame)->createAnswer(N, K);
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
int N;
int K;
vector< int > res_expected;
N = 20;
K = 4;
{int tmpa[] = {1, 2, 3, 4};
res_expected.assign(tmpa, tmpa + 4);}
_run_test(N, K, res_expected, 0);
N = 40;
K = 1;
{int tmpa[] = {39};
res_expected.assign(tmpa, tmpa + 1);}
_run_test(N, K, res_expected, 1);
N = 97;
K = 6;
{int tmpa[] = {7, 68, 9, 10, 62, 58};
res_expected.assign(tmpa, tmpa + 6);}
_run_test(N, K, res_expected, 2);
N = 2;
K = 12;
{int tmpa[] = {33, 69, 42, 45, 96, 15, 57, 12, 93, 9, 54, 99};
res_expected.assign(tmpa, tmpa + 12);}
_run_test(N, K, res_expected, 3);
}
// @end_tests

// Born in Emacs
