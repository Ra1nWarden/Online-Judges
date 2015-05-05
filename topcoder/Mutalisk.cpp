#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

struct Node {
  int cnt, num;
  Node() {}
  Node(int a, int b) : num(a), cnt(b) {}
  bool operator<(const Node& rhs) const {
    return num < rhs.num;
  }
};

class Mutalisk {
public:
  bool ok(vector<int>& x, int n) {
    int nine = 0;
    int three = 0;
    int one = 0;
    vector<int> cnt;
    for(int i = 0; i < x.size(); i++)
      cnt.push_back(n);
    for(int i = 0; i < x.size(); i++) {
      if(cnt[i] * 3 < x[i]) {
	int need = (x[i] - (cnt[i] * 3) + 5) / 6;
	cnt[i] -= need;
	x[i] -= need * 9;
	nine += need;
      }
    }
    for(int i = 0; i < x.size(); i++) {
      if(cnt[i] < x[i]) {
	int need = (x[i] - cnt[i] + 1) / 2;
	cnt[i] -= need;
	x[i] -= need * 3;
	three += need;
      }
    }

    priority_queue<Node> pq;
    for(int i = 0; i < x.size(); i++) {
      if(x[i] != 0)
	pq.push(Node(x[i], i));
    }
    while(!pq.empty()) {
      Node node = pq.top();
      pq.pop();
      int next = node.num;
      int ni = node.cnt;
      while(next > 0) {
	if(n - nine > 0) {
	  next -= 9;
	  nine++;
	  cnt[ni]--;
	} else if(n - three > 0) {
	  next -= 3;
	  three++;
	  cnt[ni]--;
	} else {
	  next -= 1;
	  one++;
	  cnt[ni]--;
	}
      }
    }
    if(nine > n || three > n || one > n)
      return false;
    for(int i = 0; i < x.size(); i++) {
      if(cnt[i] < 0)
	return false;
    }
    return true;
  }
  int minimalAttacks(vector <int> x) {
    int l = 10;
    int r = -1;
    int sum = 0;
    for(int i = 0; i < x.size(); i++) {
      r = max(r, x[i]);
      l = min(l, (x[i] + 8) / 9);
      sum += x[i];
    }
    l = max(l, (sum + 12) / 13);
    l = max(l, ((int) x.size() + 2) / 3);
    while(l < r) {
      int mid = (l + r) >> 1;
      if(ok(x, mid)) {
	r = mid;
      } else {
	l = mid + 1;
      }
    }
    return l;
  }
};

// @begin_tests
void _run_test(vector< int > x, int res_expected, int test_no) {
int tc_res = (new Mutalisk)->minimalAttacks(x);
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
int res_expected;
{int tmpa[] = {12, 10, 4};
x.assign(tmpa, tmpa + 3);}
res_expected = 2;
_run_test(x, res_expected, 0);
{int tmpa[] = {54, 18, 6};
x.assign(tmpa, tmpa + 3);}
res_expected = 6;
_run_test(x, res_expected, 1);
{int tmpa[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
x.assign(tmpa, tmpa + 10);}
res_expected = 4;
_run_test(x, res_expected, 2);
{int tmpa[] = {55, 60, 53};
x.assign(tmpa, tmpa + 3);}
res_expected = 13;
_run_test(x, res_expected, 3);
{int tmpa[] = {60};
x.assign(tmpa, tmpa + 1);}
res_expected = 7;
_run_test(x, res_expected, 4);
{int tmpa[] = {60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60};
x.assign(tmpa, tmpa + 20);}
res_expected = 93;
_run_test(x, res_expected, 5);
}
// @end_tests

// Born in Emacs
