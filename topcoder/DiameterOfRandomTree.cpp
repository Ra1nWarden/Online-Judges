#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

const int maxn = 50;

class DiameterOfRandomTree {
private:
  vector<int> adjList[maxn+1];
  double dp[maxn+1][2]; // 0 -> max diameter 1 -> max path from root
  bool visited[maxn+1][2];
  double f(int root, int parent, int mode) {
    if(visited[root][mode])
      return dp[root][mode];
    double max_diameter = -1;
    vector<double> paths;
    for(int i = 0; i < adjList[root].size(); i++) {
      if(adjList[root][i] == parent)
	continue;
      max_diameter = max(max_diameter, f(adjList[root][i], root, 0));
      paths.push_back(f(adjList[root][i], root, 1));
    }
    if(paths.empty()) {
      // leaf
      visited[root][mode] = visited[root][mode^1] = true;
      dp[root][mode] = dp[root][mode^1] = 0;
    } else {
      sort(paths.begin(), paths.end(), greater<double>());
   
      visited[root][1] = true;
      dp[root][1] = paths[0] + 1.5;
      visited[root][0] = true;
    }
    return dp[root][mode];
  }
public:
  double getExpectation(vector <int> a, vector <int> b) {
    for(int i = 0; i < a.size(); i++) {
      adjList[a[i]].push_back(b[i]);
      adjList[b[i]].push_back(a[i]);
    }
    // 0 is the root
    memset(visited, false, sizeof visited);
    return f(0, -1, 0);
  }
};

// @begin_tests
bool _cmp_res(double expected, double got) {
  if (fabs(expected - got) < 1e-9) return 1;
  else {
    double a = (1.0 - 1e-9) * expected;
    double b = (1.0 + 1e-9) * expected;
    return got < max(a, b) && got > min(a, b);
  }
}
void _run_test(vector< int > a, vector< int > b, double res_expected, int test_no) {
double tc_res = (new DiameterOfRandomTree)->getExpectation(a, b);
if (_cmp_res(res_expected, tc_res))
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
}
cout << "expected: ";
cout << res_expected;
cout << endl << "got: ";
cout << tc_res;
cout << endl;
}
int main() {
vector< int > a;
vector< int > b;
double res_expected;
{int tmpa[] = {0, 1, 2, 3};
a.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, 2, 3, 4};
b.assign(tmpa, tmpa + 4);}
res_expected = 6.0;
_run_test(a, b, res_expected, 0);
{int tmpa[] = {0, 0, 0};
a.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1, 2, 3};
b.assign(tmpa, tmpa + 3);}
res_expected = 3.375;
_run_test(a, b, res_expected, 1);
{int tmpa[] = {0, 0, 0, 1, 4};
a.assign(tmpa, tmpa + 5);}
{int tmpa[] = {1, 2, 3, 4, 5};
b.assign(tmpa, tmpa + 5);}
res_expected = 6.25;
_run_test(a, b, res_expected, 2);
{int tmpa[] = {0, 0, 0, 0, 0, 0, 0, 0};
a.assign(tmpa, tmpa + 8);}
{int tmpa[] = {1, 2, 3, 4, 5, 6, 7, 8};
b.assign(tmpa, tmpa + 8);}
res_expected = 3.9609375;
_run_test(a, b, res_expected, 3);
{int tmpa[] = {0, 0, 0, 1, 2, 3, 5, 6, 8};
a.assign(tmpa, tmpa + 9);}
{int tmpa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
b.assign(tmpa, tmpa + 9);}
res_expected = 10.53125;
_run_test(a, b, res_expected, 4);
}
// @end_tests

// Born in Emacs
