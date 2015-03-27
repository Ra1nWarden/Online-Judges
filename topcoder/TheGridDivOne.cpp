#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <stack>
#include <cstring>
#include <map>

using namespace std;

// @begin_lib
// @end_lib

typedef pair<int, int> Point;
typedef pair<Point, int> State;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

class TheGridDivOne {
public:
  bool checkFree(const Point& p, map<int, vector<int> >& ym) {
    vector<int> v = ym[p.second];
    for(int i = 0; i < v.size(); i++) {
      if(v[i] > p.first)
	return false;
    }
    return true;
  }
  int find(vector <int> x, vector <int> y, int k) {
    map<Point, int> board;
    map<int, vector<int> > ym;
    for(int i = 0; i < x.size(); i++) {
      board[make_pair(x[i], y[i])] = -2;
      ym[y[i]].push_back(x[i]);
    }
    stack<State> s;
    s.push(make_pair(make_pair(0, 0), 0));
    int result = 0;
    while(!s.empty()) {
      State next = s.top();
      s.pop();
      if(next.second == k) {
	result = max(result, next.first.first);
	if(result == k)
	  break;
      } else if (checkFree(next.first, ym)) {
	result = max(result, next.first.first + k - next.second);
      } else {
	for(int i = 0; i < 4; i++) {
	  int nextx = next.first.first + dx[i];
	  int nexty = next.first.second + dy[i];
	  if(board.count(make_pair(nextx, nexty)) == 0 || board[make_pair(nextx, nexty)] > next.second + 1) {
	    if(nextx + (k - next.second + 1) > result) {
	      s.push(make_pair(make_pair(nextx, nexty), next.second + 1));
	      board[make_pair(nextx, nexty)] = next.second + 1;
	    }
	  }
	}
      }
    }
    return result;
  }
};

// @begin_tests
void _run_test(vector< int > x, vector< int > y, int k, int res_expected, int test_no) {
int tc_res = (new TheGridDivOne)->find(x, y, k);
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
vector< int > x;
vector< int > y;
int k;
int res_expected;
{int tmpa[] = {1, 1, 1, 1};
x.assign(tmpa, tmpa + 4);}
{int tmpa[] = {-2, -1, 0, 1};
y.assign(tmpa, tmpa + 4);}
k = 4;
res_expected = 2;
_run_test(x, y, k, res_expected, 0);
{int tmpa[] = {-1, 0, 0, 1};
x.assign(tmpa, tmpa + 4);}
{int tmpa[] = {0, -1, 1, 0};
y.assign(tmpa, tmpa + 4);}
k = 9;
res_expected = 0;
_run_test(x, y, k, res_expected, 1);
x.clear();
y.clear();
k = 1000;
res_expected = 1000;
_run_test(x, y, k, res_expected, 2);
{int tmpa[] = {1, 0, 0, -1, -1, -2, -2, -3, -3, -4, -4};
x.assign(tmpa, tmpa + 11);}
{int tmpa[] = {0, -1, 1, -2, 2, -3, 3, -4, 4, -5, 5};
y.assign(tmpa, tmpa + 11);}
k = 47;
res_expected = 31;
_run_test(x, y, k, res_expected, 3);
}
// @end_tests

// Born in Emacs
