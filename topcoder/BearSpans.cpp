#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

const int maxn = 1000;

class BearSpans {
private:
  //int p[maxn+1];
  bool mat[maxn+1][maxn+1];
  //void init(int n) {
   
    // for(int i = 0; i < n; i++) {
    //   p[i] = i;
    // }
  //}
  // int find_set(int a) {
  //   return p[a] == a ? a : p[a] = find_set(p[a]);
  // }
  // void union_set(int a, int b) {
  //   p[find_set(a)] = find_set(b);
  // }
public:
  vector<int> invalid() {
    vector<int> ans;
    ans.push_back(-1);
    return ans;
  }
  int count(int n) {
    int ans = 0;
    while(n > 1) {
      n >>= 1;
      ans++;
    }
    return ans;
  }
  vector <int> findAnyGraph(int n, int m, int k) {
    int max_iter = count(n);
    if(k > max_iter)
      return invalid();
    vector<int> ans(2 * m);
    int edge = 1;
    memset(mat, false, sizeof mat);
    //init(n);
    int sets = n;
    while(k > 1) {
      int target = sets >> 1;
      for(int i = target; i < sets; i++) {
	ans[2 * edge - 2] = i - target + 1;
	ans[2 * edge - 1] = i + 1;
	mat[i - target][i] = mat[i][i - target] = true;
	edge++;
      }
      sets = target;
      k--;
    }
    for(int i = 1; i < sets; i++) {
      ans[2 * edge - 2] = 1;
      ans[2 * edge - 1] = i + 1;
      mat[0][i] = mat[i][0] = true;
      edge++;
    }
    int i = 0, j = 1;
    while(edge <= m) {
      if(!mat[i][j]) {
	ans[2 * edge - 2] = i + 1;
	ans[2 * edge - 1] = j + 1;
	mat[i][j] = mat[j][i] = true;
	edge++;
      }
      j++;
      if(j == n) {
	i++;
	j = i + 1;
      }
    }
    return ans;
  }
};

// @begin_tests
void _print_res(ostream& str, vector< int > v) {
  bool first = 1;
  str << "{";
  for (vector< int >::iterator i = v.begin(); i != v.end(); i++) {
    if (first) {
      str << " ";
      first = 0;
    } else
      str << ", ";
    str << *i;
  }
  str << " }";
}
void _run_test(int n, int m, int k, vector< int > res_expected, int test_no) {
vector< int > tc_res = (new BearSpans)->findAnyGraph(n, m, k);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
_print_res(cout, res_expected);
cout << endl << "got: ";
_print_res(cout, tc_res);
cout << endl;
}
}
int main() {
int n;
int m;
int k;
vector< int > res_expected;
n = 17;
m = 22;
k = 1;
{int tmpa[] = {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13, 1, 14, 1, 15, 1, 16, 1, 17, 2, 3, 2, 8, 3, 9, 8, 9, 10, 12, 12, 14};
res_expected.assign(tmpa, tmpa + 44);}
_run_test(n, m, k, res_expected, 0);
n = 9;
m = 12;
k = 3;
{int tmpa[] = {6, 5, 7, 6, 1, 2, 3, 4, 8, 9, 3, 5, 7, 4, 1, 9, 6, 2, 6, 1, 1, 8, 4, 5};
res_expected.assign(tmpa, tmpa + 24);}
_run_test(n, m, k, res_expected, 1);
n = 9;
m = 12;
k = 7;
{int tmpa[] = {-1};
res_expected.assign(tmpa, tmpa + 1);}
_run_test(n, m, k, res_expected, 2);
n = 1000;
m = 999;
k = 970;
{int tmpa[] = {-1};
res_expected.assign(tmpa, tmpa + 1);}
_run_test(n, m, k, res_expected, 3);
n = 2;
m = 1;
k = 1;
{int tmpa[] = {1, 2};
res_expected.assign(tmpa, tmpa + 2);}
_run_test(n, m, k, res_expected, 4);
n = 3;
m = 2;
k = 1;
{int tmpa[] = {1, 2, 1, 3};
res_expected.assign(tmpa, tmpa + 4);}
_run_test(n, m, k, res_expected, 5);
n = 3;
m = 3;
k = 2;
{int tmpa[] = {-1};
res_expected.assign(tmpa, tmpa + 1);}
_run_test(n, m, k, res_expected, 6);
}
// @end_tests

// Born in Emacs
