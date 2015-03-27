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

class ShufflingCardsDiv2 {
public:
  string shuffle(vector <int> permutation) {
    int first = 0;
    for(int i = 0; i < permutation.size(); i++) {
      if(i % 2 == 0 && permutation[i] <= permutation.size() / 2) {
	first++;
      }
    }
    int target = (permutation.size() / 2) % 2 == 1 ? permutation.size() / 4 + 1 : permutation.size() / 4;
    return first == target ? "Possible" : "Impossible";
  }
};

// @begin_tests
void _run_test(vector< int > permutation, string res_expected, int test_no) {
string tc_res = (new ShufflingCardsDiv2)->shuffle(permutation);
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
vector< int > permutation;
string res_expected;
{int tmpa[] = {1, 2, 3, 4};
permutation.assign(tmpa, tmpa + 4);}
res_expected = "Possible";
_run_test(permutation, res_expected, 0);
{int tmpa[] = {4, 3, 2, 1};
permutation.assign(tmpa, tmpa + 4);}
res_expected = "Possible";
_run_test(permutation, res_expected, 1);
{int tmpa[] = {1, 3, 2, 4};
permutation.assign(tmpa, tmpa + 4);}
res_expected = "Impossible";
_run_test(permutation, res_expected, 2);
{int tmpa[] = {1, 4, 2, 5, 3, 6};
permutation.assign(tmpa, tmpa + 6);}
res_expected = "Impossible";
_run_test(permutation, res_expected, 3);
{int tmpa[] = {8, 5, 4, 9, 1, 7, 6, 10, 3, 2};
permutation.assign(tmpa, tmpa + 10);}
res_expected = "Possible";
_run_test(permutation, res_expected, 4);
}
// @end_tests

// Born in Emacs
