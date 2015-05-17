#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#define MAXN 2005

using namespace std;

// @begin_lib
// @end_lib

class ApplesAndOrangesEasy {
private:
  bool apple[MAXN];
public:
  int maximumApples(int N, int K, vector <int> info) {
    memset(apple, false, sizeof apple);
    for(int i = 0; i < info.size(); i++)
      apple[info[i]] = true;
    int ans = info.size();
    for(int i = 1; i <= N; i++) {
      if(apple[i]) {
	continue;
      }
      int j = max(i - (K - 1), 1);
      int rcnt = 0;
      bool ok = true;
      for(int k = j; k < j + K; k++) {
	if(apple[k])
	  rcnt++;
      }
      if(rcnt > (K / 2) - 1) {
	continue;
      }
      for(j = j+1; j <= min(i, N - (K - 1)); j++) {
	if(apple[j-1])
	  rcnt--;
	if(apple[j+K-1])
	  rcnt++;
	if(rcnt > (K / 2) - 1) {
	  ok = false;
	  break;
	}
      }
      if(ok) {
	ans++;
	apple[i] = true;
      }
    }
    return ans;
  }
};

// @begin_tests
void _run_test(int N, int K, vector< int > info, int res_expected, int test_no) {
int tc_res = (new ApplesAndOrangesEasy)->maximumApples(N, K, info);
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
int N;
int K;
vector< int > info;
int res_expected;
N = 3;
K = 2;
info.clear();
res_expected = 2;
_run_test(N, K, info, res_expected, 0);
N = 10;
K = 3;
{int tmpa[] = {3, 8};
info.assign(tmpa, tmpa + 2);}
res_expected = 2;
_run_test(N, K, info, res_expected, 1);
N = 9;
K = 4;
{int tmpa[] = {1, 4};
info.assign(tmpa, tmpa + 2);}
res_expected = 5;
_run_test(N, K, info, res_expected, 2);
N = 9;
K = 4;
{int tmpa[] = {2, 4};
info.assign(tmpa, tmpa + 2);}
res_expected = 4;
_run_test(N, K, info, res_expected, 3);
N = 23;
K = 7;
{int tmpa[] = {3, 2, 9, 1, 15, 23, 20, 19};
info.assign(tmpa, tmpa + 8);}
res_expected = 10;
_run_test(N, K, info, res_expected, 4);
N = 2;
K = 2;
{int tmpa[] = {};
info.assign(tmpa, tmpa + 0);}
res_expected = 1;
_run_test(N, K, info, res_expected, 5);
N = 2;
K = 2;
{int tmpa[] = {1};
info.assign(tmpa, tmpa + 1);}
res_expected = 1;
_run_test(N, K, info, res_expected, 6);
N = 3;
K = 2;
{int tmpa[] = {1};
info.assign(tmpa, tmpa + 1);}
res_expected = 2;
_run_test(N, K, info, res_expected, 7);
N = 4;
K = 2;
{int tmpa[] = {};
info.assign(tmpa, tmpa + 0);}
res_expected = 2;
_run_test(N, K, info, res_expected, 8);
N = 10;
K = 10;
 {int tmpa[] = {1,3,4,5,8};
info.assign(tmpa, tmpa + 5);}
res_expected = 5;
_run_test(N, K, info, res_expected, 9);
N = 11;
K = 10;
 {int tmpa[] = {1,3,4,5,8};
info.assign(tmpa, tmpa + 5);}
res_expected = 6;
_run_test(N, K, info, res_expected, 10);
N = 10;
K = 9;
 {int tmpa[] = {};
info.assign(tmpa, tmpa + 0);}
res_expected = 5;
_run_test(N, K, info, res_expected, 11);
N = 2000;
K = 2;
 {int tmpa[] = {};
info.assign(tmpa, tmpa + 0);}
res_expected = 1000;
_run_test(N, K, info, res_expected, 12);
N = 2000;
K = 1000;
 {int tmpa[] = {};
info.assign(tmpa, tmpa + 0);}
res_expected = 1000;
_run_test(N, K, info, res_expected, 13);
N = 11;
K = 2;
 {int tmpa[] = {1, 5, 9};
info.assign(tmpa, tmpa + 3);}
res_expected = 6;
_run_test(N, K, info, res_expected, 14);
N = 11;
K = 2;
 {int tmpa[] = {2};
info.assign(tmpa, tmpa + 1);}
res_expected = 5;
_run_test(N, K, info, res_expected, 15);
}
// @end_tests

// Born in Emacs
