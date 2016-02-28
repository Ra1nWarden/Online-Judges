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

class SuccessfulMerger {
public:
  int minimumMergers(vector <int> road) {
    vector<int> visited(road.size(), false);
    vector<int> degree(road.size(), 0);
    for(int i = 0; i < road.size(); i++) {
      if(visited[i])
	continue;
      int j = road[i];
      visited[i] = true;
      if(road[j] == i) {
	visited[j] = true;
      }
      degree[i]++;
      degree[j]++;
    }
    bool special = true;
    int three = 1;
    int one = 1;
    for(int i = 0; i < road.size(); i++) {
      if(degree[i] == 2)
	continue;
      else if(degree[i] == 1)
	one--;
      else if(degree[i] == 3)
	three--;
      else {
	special = false;
	break;
      }
    }
    special = one == 0 && three == 0;
    if(special) {
      return road.size() - 3;
    }
    int leaves = 0;
    bool cycle = true;
    for(int i = 0; i < road.size(); i++) {
      if(degree[i] == 1)
	leaves++;
      if(degree[i] != 2)
	cycle = false;
    }
    if(cycle) {
      return road.size() - 2;
    } else {
      return road.size() - leaves - (road.size() == 2 ? 0 : 1);
    }
  }
};

// @begin_tests
void _run_test(vector< int > road, int res_expected, int test_no) {
int tc_res = (new SuccessfulMerger)->minimumMergers(road);
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
vector< int > road;
int res_expected;
{int tmpa[] = {2, 2, 1, 1, 1};
road.assign(tmpa, tmpa + 5);}
res_expected = 1;
_run_test(road, res_expected, 0);
{int tmpa[] = {3, 4, 5, 4, 5, 3};
road.assign(tmpa, tmpa + 6);}
res_expected = 2;
_run_test(road, res_expected, 1);
{int tmpa[] = {1, 0, 1, 0, 0, 0, 1, 0, 1, 1};
road.assign(tmpa, tmpa + 10);}
res_expected = 1;
_run_test(road, res_expected, 2);
{int tmpa[] = {1, 2, 3, 0};
road.assign(tmpa, tmpa + 4);}
res_expected = 2;
_run_test(road, res_expected, 3);
{int tmpa[] = {31, 19, 0, 15, 30, 32, 15, 24, 0, 20, 40, 1, 22, 21, 39, 28, 0, 23, 15, 5, 19, 22, 6, 32, 8, 38, 35, 30, 4, 28, 32, 18, 18, 9, 22, 41, 20, 18, 6, 25, 41, 34, 4};
road.assign(tmpa, tmpa + 43);}
res_expected = 25;
_run_test(road, res_expected, 4);
{int tmpa[] = {1, 0};
road.assign(tmpa, tmpa + 2);}
res_expected = 0;
_run_test(road, res_expected, 5);
}
// @end_tests

// Born in Emacs
