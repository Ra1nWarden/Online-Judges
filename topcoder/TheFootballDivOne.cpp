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

class TheFootballDivOne {
public:
  int find(int yourScore, vector <int> scores, vector <int> numberOfTeams) {
    
  }
};

// @begin_tests
void _run_test(int yourScore, vector< int > scores, vector< int > numberOfTeams, int res_expected, int test_no) {
int tc_res = (new TheFootballDivOne)->find(yourScore, scores, numberOfTeams);
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
int yourScore;
vector< int > scores;
vector< int > numberOfTeams;
int res_expected;
yourScore = 4;
{int tmpa[] = {7};
scores.assign(tmpa, tmpa + 1);}
{int tmpa[] = {1};
numberOfTeams.assign(tmpa, tmpa + 1);}
res_expected = 1;
_run_test(yourScore, scores, numberOfTeams, res_expected, 0);
yourScore = 1;
{int tmpa[] = {7};
scores.assign(tmpa, tmpa + 1);}
{int tmpa[] = {2};
numberOfTeams.assign(tmpa, tmpa + 1);}
res_expected = 2;
_run_test(yourScore, scores, numberOfTeams, res_expected, 1);
yourScore = 1;
{int tmpa[] = {7, 1};
scores.assign(tmpa, tmpa + 2);}
{int tmpa[] = {2, 1};
numberOfTeams.assign(tmpa, tmpa + 2);}
res_expected = 1;
_run_test(yourScore, scores, numberOfTeams, res_expected, 2);
yourScore = 11;
{int tmpa[] = {5, 12, 17, 19, 99, 13, 15, 14};
scores.assign(tmpa, tmpa + 8);}
{int tmpa[] = {2, 4, 8, 2, 1, 3, 25, 3};
numberOfTeams.assign(tmpa, tmpa + 8);}
res_expected = 4;
_run_test(yourScore, scores, numberOfTeams, res_expected, 3);
yourScore = 1;
{int tmpa[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
scores.assign(tmpa, tmpa + 10);}
{int tmpa[] = {245, 365, 135, 367, 4345, 6729, 5806, 431, 256, 178};
numberOfTeams.assign(tmpa, tmpa + 10);}
res_expected = 1650;
_run_test(yourScore, scores, numberOfTeams, res_expected, 4);
}
// @end_tests

// Born in Emacs
