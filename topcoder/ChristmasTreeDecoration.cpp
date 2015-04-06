#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#define MAXN 55

using namespace std;

// @begin_lib
// @end_lib

struct Edge {
  int a, b;
  int weight;
  Edge() {}
  Edge(int aa, int bb, int ww) : a(aa), b(bb), weight(ww) {}
  bool operator<(const Edge& rhs) const {
    return weight > rhs.weight;
  }
};

class ChristmasTreeDecoration {
private:
  int parent[MAXN];
  int findSet(int a) {
    return parent[a] == a ? a : parent[a] = findSet(parent[a]);
  }
  void unionSet(int a, int b) {
    parent[findSet(a)] = findSet(b);
  }
  bool sameSet(int a, int b) {
    return findSet(a) == findSet(b);
  }
public:
  int solve(vector <int> col, vector <int> x, vector <int> y) {
    priority_queue<Edge> pq;
    for(int i= 0; i < x.size(); i++) {
      if(col[x[i] - 1] != col[y[i] - 1]) {
	Edge edge(x[i], y[i], 0);
	pq.push(edge);
      } else {
	Edge edge(x[i], y[i], 1);
	pq.push(edge);
      }
    }
    for(int i = 1; i <= col.size(); i++) {
      parent[i] = i;
    }
    int add = col.size() - 1;
    int ans = 0;
    while(add) {
      while(!pq.empty()) {
	Edge next = pq.top();
	pq.pop();
	if(!sameSet(next.a, next.b)) {
	  unionSet(next.a, next.b);
	  add--;
	  ans += next.weight;
	  break;
	}
      }
    }
    return ans;
  }
};

// @begin_tests
void _run_test(vector< int > col, vector< int > x, vector< int > y, int res_expected, int test_no) {
int tc_res = (new ChristmasTreeDecoration)->solve(col, x, y);
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
vector< int > col;
vector< int > x;
vector< int > y;
int res_expected;
{int tmpa[] = {1, 1, 2, 2};
col.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, 2, 3, 4};
x.assign(tmpa, tmpa + 4);}
{int tmpa[] = {2, 3, 4, 1};
y.assign(tmpa, tmpa + 4);}
res_expected = 1;
_run_test(col, x, y, res_expected, 0);
{int tmpa[] = {1, 1, 2, 2};
col.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, 2, 3, 4, 1, 2};
x.assign(tmpa, tmpa + 6);}
{int tmpa[] = {2, 3, 4, 1, 3, 4};
y.assign(tmpa, tmpa + 6);}
res_expected = 0;
_run_test(col, x, y, res_expected, 1);
{int tmpa[] = {50, 50, 50, 50};
col.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, 2, 3, 1, 1, 2};
x.assign(tmpa, tmpa + 6);}
{int tmpa[] = {2, 3, 4, 4, 3, 4};
y.assign(tmpa, tmpa + 6);}
res_expected = 3;
_run_test(col, x, y, res_expected, 2);
{int tmpa[] = {1, 4, 2, 3};
col.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, 2, 3};
x.assign(tmpa, tmpa + 3);}
{int tmpa[] = {2, 3, 4};
y.assign(tmpa, tmpa + 3);}
res_expected = 0;
_run_test(col, x, y, res_expected, 3);
{int tmpa[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
col.assign(tmpa, tmpa + 12);}
{int tmpa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 1, 1, 1, 1, 1};
x.assign(tmpa, tmpa + 18);}
{int tmpa[] = {2, 3, 1, 5, 6, 4, 8, 9, 7, 11, 12, 10, 5, 7, 12, 11, 6, 4};
y.assign(tmpa, tmpa + 18);}
res_expected = 5;
_run_test(col, x, y, res_expected, 4);
}
// @end_tests

// Born in Emacs
