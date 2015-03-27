#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

// @begin_lib
// @end_lib

class Fragile2 {
private:
  int countComponent(vector<string>& graph, int i, int j) {
    int n = graph.size();
    int color[n];
    memset(color, -1, sizeof color);
    int index = 0;
    for(int k = 0; k < n; k++) {
      if(k == i || k == j || color[k] != -1)
	continue;
      stack<int> s;
      s.push(k);
      color[k] = index;
      while(!s.empty()) {
	int next = s.top();
	s.pop();
	for(int l = 0; l < n; l++) {
	  if(l == i || l == j || color[l] != -1)
	    continue;
	  if(graph[next][l] == 'Y') {
	    color[l] = index;
		s.push(l);
	  }
	}
      }
      index++;
    }
    return index;
  }
public:
  int countPairs(vector <string> graph) {
    int res = 0;
    int n = graph.size();
    int orig = countComponent(graph, -1, -1);
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
	int x = countComponent(graph, i, j);
	if(x > orig) {
	  //cout << "found " << i <<  " and " << j << endl;
	  res++;
	}
      }
    }
    return res;
  }
};

// @begin_tests
void _run_test(vector< string > graph, int res_expected, int test_no) {
int tc_res = (new Fragile2)->countPairs(graph);
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
vector< string > graph;
int res_expected;
{string tmpa[] = {"NYNN", "YNYN", "NYNY", "NNYN"};
graph.assign(tmpa, tmpa + 4);}
res_expected = 3;
_run_test(graph, res_expected, 0);
{string tmpa[] = {"NYNNNN", "YNYNNN", "NYNNNN", "NNNNYN", "NNNYNY", "NNNNYN"};
graph.assign(tmpa, tmpa + 6);}
res_expected = 5;
_run_test(graph, res_expected, 1);
{string tmpa[] = {"NNN", "NNN", "NNN"};
graph.assign(tmpa, tmpa + 3);}
res_expected = 0;
_run_test(graph, res_expected, 2);
{string tmpa[] = {"NYNYNNYYNN", "YNNNYNYYNN", "NNNNYNNNYN", "YNNNYYNNNN", "NYYYNNNNYN", "NNNYNNNNYN", "YYNNNNNNNN", "YYNNNNNNYN", "NNYNYYNYNY", "NNNNNNNNYN"};
graph.assign(tmpa, tmpa + 10);}
res_expected = 9;
_run_test(graph, res_expected, 3);
{string tmpa[] = {"NNNYNNYNNNNNNNYYNNNY", "NNNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNYNNNNNNNNN", "NNNNNNNYNNNNNYNNNNYN", "NNNNNNNNNNNNNNNNYNNY", "YNNNNNNNNNNNNYYYNYNN", "NNNNYNNNNNNNNYYNNNNN", "NYNNNNNNNYNNNNNNNNNN", "NNNNNNNNYNNNYNNNNNYN", "NNNYNNNNNNNNNNYNNNNN", "NNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNNNNNYNN", "NNNNYNYYNNNNNNNNNNNN", "YNNNNNYYNNYNNNNNNNNN", "YNNNNNYNNNNNNNNNYNNN", "NNNNNYNNNNNNNNNYNYNN", "NNNNNNYNNNNNYNNNYNNN", "NNNNYNNNNYNNNNNNNNNN", "YNNNNYNNNNNNNNNNNNNN"};
graph.assign(tmpa, tmpa + 20);}
res_expected = 42;
_run_test(graph, res_expected, 4);
}
// @end_tests

// Born in Emacs
