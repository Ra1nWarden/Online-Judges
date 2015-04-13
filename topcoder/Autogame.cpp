#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
#define MAXN 55

using namespace std;

// @begin_lib
// @end_lib

class Autogame {
private:
  int remainder[MAXN];
  int choose[30][30];
public:
  int pow2(int n) {
    if(remainder[n] != -1)
      return remainder[n];
    if(n == 0)
      return remainder[n] = 1;
    else
      return remainder[n] = (int) ((long long) pow2(n-1) * 2 % MOD);
  }

  void init(int p) {
    for(int i = 0; i <= p; i++) {
      for(int j = 0; j <= i; j++) {
	if(i == 0)
	  choose[i][j] = 0;
	else if(j == 0)
	  choose[i][j] = 1;
	else
	  choose[i][j] = ((long long) choose[i-1][j] + choose[i-1][j-1]) % MOD;
      }
    }
  }

  int wayscnt(vector <int> a, int K) {
    memset(remainder, -1, sizeof remainder);
    int ans = 0;
    int N = a.size();
    int pairs = 0;
    for(int i = 1; i <= N; i++) {
      for(int j = i+1; j <= N; j++) {
	bool collide = false;
	int x = i;
	int y = j;
	for(int k = 0; k < K; k++) {
	  x = a[x - 1];
	  y = a[y - 1];
	  if(x == y) {
	    collide = true;
	    break;
	  }
	}
	if(collide) {
	  ans = ((long long) ans + pow2(N - 2)) % MOD;
	  pairs++;
	}
      }
    }

    init(pairs);

    //printf("beofrelooop ans=%d\n", ans);

    for(int i = 2; i <= pairs; i++) {
      if(N >= 2*i) {
	if(i % 2 == 0) {
	  ans = ((long long) ans - ((long long)pow2(N - 2 * i) * choose[pairs][i]) % MOD + MOD) % MOD;
	} else {
	  ans = ((long long) ans + ((long long)pow2(N - 2 * i) * choose[pairs][i]) % MOD) % MOD;
	}
      }
    }

    int res = pow2(N);
    //printf("res=%d ans=%d\n", res, ans);
    res = (res - ans + MOD) % MOD;
    return res;
  }
};

// @begin_tests
void _run_test(vector< int > a, int K, int res_expected, int test_no) {
int tc_res = (new Autogame)->wayscnt(a, K);
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
vector< int > a;
int K;
int res_expected;
{int tmpa[] = {1, 2, 3};
a.assign(tmpa, tmpa + 3);}
K = 5;
res_expected = 8;
_run_test(a, K, res_expected, 0);
{int tmpa[] = {1, 1, 1};
a.assign(tmpa, tmpa + 3);}
K = 1;
res_expected = 4;
_run_test(a, K, res_expected, 1);
{int tmpa[] = {2, 1};
a.assign(tmpa, tmpa + 2);}
K = 42;
res_expected = 4;
_run_test(a, K, res_expected, 2);
{int tmpa[] = {2, 3, 4, 3};
a.assign(tmpa, tmpa + 4);}
K = 3;
res_expected = 9;
_run_test(a, K, res_expected, 3);
{int tmpa[] = {4, 4, 3, 2, 1};
a.assign(tmpa, tmpa + 5);}
K = 3;
res_expected = 18;
_run_test(a, K, res_expected, 4);
}
// @end_tests

// Born in Emacs
