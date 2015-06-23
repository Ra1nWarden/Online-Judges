#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#define MAXN 1000000
#define INF 200000000

using namespace std;

// @begin_lib
// @end_lib

class MissingLCM {
private:
  bool check[MAXN+5];
  int primes[MAXN];
  int pi;
public:
  int getMin(int N) {
    if(N == 1)
      return 2;
    pi = 0;
    memset(check, false, sizeof check);
    for(int i = 2; i <= MAXN; i++) {
      if(!check[i]) {
	primes[pi++] = i;
      }
      for(int j = 0; j < pi; j++) {
	if(i * primes[j] > MAXN)
	  break;
	check[i * primes[j]] = true;
	if(i % primes[j] == 0)
	  break;
      }
    }
    int ans = N;
    for(int i =0; i < pi; i++) {
      long long fact = primes[i];
      if(fact > N)
	break;
      while(fact <= N)
	fact *= primes[i];
      if(fact != primes[i])
	fact /= primes[i];
      ans = max(ans, ((N / (int) fact) + 1) * (int) fact);
    }
    return ans;
  }
};

// @begin_tests
void _run_test(int N, int res_expected, int test_no) {
int tc_res = (new MissingLCM)->getMin(N);
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
int res_expected;
N = 1;
res_expected = 2;
_run_test(N, res_expected, 0);
N = 2;
res_expected = 4;
_run_test(N, res_expected, 1);
N = 3;
res_expected = 6;
_run_test(N, res_expected, 2);
N = 4;
res_expected = 8;
_run_test(N, res_expected, 3);
N = 5;
res_expected = 10;
_run_test(N, res_expected, 4);
N = 42;
res_expected = 82;
_run_test(N, res_expected, 5);
N = 999999;
res_expected = 1999966;
_run_test(N, res_expected, 6);
N = 1000000;
res_expected = 1999966;
_run_test(N, res_expected, 7);
}
// @end_tests

// Born in Emacs
