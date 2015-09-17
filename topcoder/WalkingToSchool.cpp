#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>
#include <set>

using namespace std;

// @begin_lib
// @end_lib

class WalkingToSchool {
private:
  vector<int> adjList[2000];
  int visited[2000];
  int n;
  int gcd(int u, int v) {
    return v == 0 ? u : gcd(v, u%v);
  }
  bool isRelativelyPrime(int u, int v) {
    return gcd(u, v) == 1;
  }
  void dfs(int u, int step, set<int>& cycles) {
    if(visited[u] == -1) {
      visited[u] = step;
      for(int i = 0; i < adjList[u].size(); i++) {
	int v = adjList[u][i];
	if(visited[v] != -1) {
	  cycles.insert(step - visited[v] + 1);
	} else {
	  dfs(v, step+1, cycles);
	}
      }
    }
    visited[u] = -1;
  }
  bool possible(int u, int v) {
    memset(visited, -1, sizeof visited);
    queue<int> q;
    visited[u] = 0;
    q.push(u);
    while(!q.empty()) {
      int qu = q.front();
      q.pop();
      for(int i = 0; i < adjList[qu].size(); i++) {
	int qv = adjList[qu][i];
	if(visited[qv] == -1) {
	  visited[qv] = visited[qu] + 1;
	  q.push(qv);
	}
      }
    }
    if(visited[v] == -1)
      return false;

    set<int> cycles;
    memset(visited, -1, sizeof visited);
    dfs(0, 0, cycles);
    
    for(set<int>::iterator itr = cycles.begin(); itr != cycles.end(); itr++) {
      set<int>::iterator iitr = itr;
      for(iitr++; iitr != cycles.end(); iitr++) {
	if(isRelativelyPrime(*itr, *iitr))
	  return true;
      }
    }
    return false;
  }
public:
  string canWalkExactly(int N, vector <int> from, vector <int> to) {
    n = N;
    for(int i = 0; i < from.size(); i++)
      adjList[from[i]].push_back(to[i]);
    bool free = possible(0, 1) && possible(1, 0);
    if(free)
      return "Freedom";
    else
      return "Chores";
  }
};

// @begin_tests
void _run_test(int N, vector< int > from, vector< int > to, string res_expected, int test_no) {
string tc_res = (new WalkingToSchool)->canWalkExactly(N, from, to);
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
int N;
vector< int > from;
vector< int > to;
string res_expected;
N = 2;
{int tmpa[] = {0, 1};
from.assign(tmpa, tmpa + 2);}
{int tmpa[] = {1, 0};
to.assign(tmpa, tmpa + 2);}
res_expected = "Chores";
_run_test(N, from, to, res_expected, 0);
N = 3;
{int tmpa[] = {0, 1, 1, 2};
from.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, 0, 2, 0};
to.assign(tmpa, tmpa + 4);}
res_expected = "Freedom";
_run_test(N, from, to, res_expected, 1);
N = 4;
{int tmpa[] = {0, 2, 2, 3, 0};
from.assign(tmpa, tmpa + 5);}
{int tmpa[] = {2, 0, 3, 0, 1};
to.assign(tmpa, tmpa + 5);}
res_expected = "Chores";
_run_test(N, from, to, res_expected, 2);
N = 10;
{int tmpa[] = {0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 5, 5, 5, 6, 6, 6, 7, 8, 9, 9, 9, 9};
from.assign(tmpa, tmpa + 25);}
{int tmpa[] = {4, 5, 6, 7, 9, 4, 6, 0, 1, 3, 8, 4, 6, 1, 4, 8, 1, 7, 8, 1, 4, 2, 5, 6, 8};
to.assign(tmpa, tmpa + 25);}
res_expected = "Chores";
_run_test(N, from, to, res_expected, 3);
N = 8;
{int tmpa[] = {0, 1, 4, 6, 7, 5, 2, 3, 0};
from.assign(tmpa, tmpa + 9);}
{int tmpa[] = {1, 4, 6, 7, 5, 2, 3, 0, 7};
to.assign(tmpa, tmpa + 9);}
res_expected = "Freedom";
_run_test(N, from, to, res_expected, 4);
N = 2000;
from.clear();
to.clear();
res_expected = "Chores";
_run_test(N, from, to, res_expected, 5);
}
// @end_tests

// Born in Emacs
