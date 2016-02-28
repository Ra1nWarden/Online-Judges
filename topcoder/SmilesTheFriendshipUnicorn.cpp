#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

const int maxn = 2000;

class SmilesTheFriendshipUnicorn {
private:
  vector<int> adjMat[maxn+5];
  bool visited[maxn+5];
public:
  int dfs(int cur) {
    int ret = 0;
    visited[cur] = true;
    for(int i = 0; i < adjMat[cur].size(); i++) {
      int v = adjMat[cur][i];
      if(!visited[v]) {
	ret = max(ret, dfs(v) + 1);
	if(ret >= 4)
	  return ret;
      }
    }
    visited[cur] = false;
    return ret;
  }
  string hasFriendshipChain(int N, vector <int> A, vector <int> B) {
    for(int i = 0; i < A.size(); i++) {
      adjMat[A[i]].push_back(B[i]);
      adjMat[B[i]].push_back(A[i]);
    }
    memset(visited, false, sizeof visited);
    int maxval = 0;
    for(int i = 0; i < N; i++) {
      maxval = max(maxval, dfs(i));
      if(maxval >= 4)
	break;
    }
    return maxval >= 4 ? "Yay!" : ":(";
  }
};

// @begin_tests
void _run_test(int N, vector< int > A, vector< int > B, string res_expected, int test_no) {
string tc_res = (new SmilesTheFriendshipUnicorn)->hasFriendshipChain(N, A, B);
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
vector< int > A;
vector< int > B;
string res_expected;
N = 5;
{int tmpa[] = {0, 1, 2, 3};
A.assign(tmpa, tmpa + 4);}
{int tmpa[] = {1, 2, 3, 4};
B.assign(tmpa, tmpa + 4);}
res_expected = "Yay!";
_run_test(N, A, B, res_expected, 0);
N = 5;
{int tmpa[] = {0, 1, 2, 3, 1};
A.assign(tmpa, tmpa + 5);}
{int tmpa[] = {1, 2, 3, 0, 4};
B.assign(tmpa, tmpa + 5);}
res_expected = "Yay!";
_run_test(N, A, B, res_expected, 1);
N = 6;
{int tmpa[] = {0, 0, 0, 0, 0};
A.assign(tmpa, tmpa + 5);}
{int tmpa[] = {1, 2, 3, 4, 5};
B.assign(tmpa, tmpa + 5);}
res_expected = ":(";
_run_test(N, A, B, res_expected, 2);
N = 8;
{int tmpa[] = {1, 3, 4, 3, 4, 3, 0, 2};
A.assign(tmpa, tmpa + 8);}
{int tmpa[] = {7, 7, 7, 4, 6, 5, 4, 7};
B.assign(tmpa, tmpa + 8);}
res_expected = "Yay!";
_run_test(N, A, B, res_expected, 3);
N = 7;
{int tmpa[] = {0, 1, 1, 5, 4, 5};
A.assign(tmpa, tmpa + 6);}
{int tmpa[] = {5, 2, 3, 6, 1, 1};
B.assign(tmpa, tmpa + 6);}
res_expected = ":(";
_run_test(N, A, B, res_expected, 4);
N = 42;
{int tmpa[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
A.assign(tmpa, tmpa + 42);}
{int tmpa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0};
B.assign(tmpa, tmpa + 42);}
res_expected = "Yay!";
_run_test(N, A, B, res_expected, 5);
}
// @end_tests

// Born in Emacs
