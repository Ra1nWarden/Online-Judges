#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#define MAXN 55

using namespace std;

// @begin_lib
// @end_lib

class JanuszTheBusinessman {
private:
  bool adjMat[MAXN][MAXN];
  bool visited[MAXN];
  int n;
public:
  void dfs(int u) {
    stack<int> s;
    s.push(u);
    while(!s.empty()) {
      int next = s.top();
      s.pop();
      for(int i = 0; i < n; i++) {
	if(adjMat[next][i] && !visited[i]) {
	  visited[i] = true;
	  s.push(i);
	}
      }
    }
  }
  int makeGuestsReturn(vector <int> arrivals, vector <int> departures) {
    n = arrivals.size();
    memset(adjMat, false, sizeof adjMat);
    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
	//cout << i << " and " << j << endl;
	bool connected = (arrivals[i] > arrivals[j] && arrivals[i] <= departures[j]);
	//cout << "after one " << connected << endl;
	connected = connected || (arrivals[j] > arrivals[i] && arrivals[j] <= departures[i]);
	//cout << "after two " << connected << endl;
	if(connected) {
	  //cout << "connecting " << i << " and " << j << endl;
	  adjMat[i][j] = adjMat[j][i] = true;
	}
      }
    }
    int component = 0;
    memset(visited, false, sizeof visited);
    for(int i = 0; i < n; i++) {
      if(!visited[i]) {
	visited[i] = true;
	dfs(i);
	component++;
      }
    }
    return component;
  }
};

// @begin_tests
void _run_test(vector< int > arrivals, vector< int > departures, int res_expected, int test_no) {
int tc_res = (new JanuszTheBusinessman)->makeGuestsReturn(arrivals, departures);
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
vector< int > arrivals;
vector< int > departures;
int res_expected;
{int tmpa[] = {2, 10, 6};
arrivals.assign(tmpa, tmpa + 3);}
{int tmpa[] = {6, 11, 9};
departures.assign(tmpa, tmpa + 3);}
res_expected = 2;
_run_test(arrivals, departures, res_expected, 0);
{int tmpa[] = {2, 10, 23, 34, 45, 123, 1};
arrivals.assign(tmpa, tmpa + 7);}
{int tmpa[] = {25, 12, 40, 50, 48, 187, 365};
departures.assign(tmpa, tmpa + 7);}
res_expected = 1;
_run_test(arrivals, departures, res_expected, 1);
{int tmpa[] = {8, 12, 20, 30, 54, 54, 68, 75};
arrivals.assign(tmpa, tmpa + 8);}
{int tmpa[] = {13, 31, 30, 53, 55, 70, 80, 76};
departures.assign(tmpa, tmpa + 8);}
res_expected = 3;
_run_test(arrivals, departures, res_expected, 2);
{int tmpa[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148};
arrivals.assign(tmpa, tmpa + 10);}
{int tmpa[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223};
departures.assign(tmpa, tmpa + 10);}
res_expected = 2;
_run_test(arrivals, departures, res_expected, 3);
{int tmpa[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6};
arrivals.assign(tmpa, tmpa + 20);}
{int tmpa[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13};
departures.assign(tmpa, tmpa + 20);}
res_expected = 14;
_run_test(arrivals, departures, res_expected, 4);
}
// @end_tests

// Born in Emacs
