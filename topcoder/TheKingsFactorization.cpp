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

class TheKingsFactorization {
public:
  vector<long long> getVector(long long N, vector<long long> primes) {
    long long n = N;
    for(int i = 0; i < primes.size(); i++)
      n /= primes[i];
    for(long long p = 2; p * p * p <= N; p++) {
      if(n % p == 0) {
	while(n % p == 0) {
	  primes.push_back(p);
	  n /= p;
	}
      }
    }
    if(n != 1)
      primes.push_back(n);
    sort(primes.begin(), primes.end());
    return primes;
  }
};

// @begin_tests
void _print_res(ostream& str, vector< long long > v) {
  bool first = 1;
  str << "{";
  for (vector< long long >::iterator i = v.begin(); i != v.end(); i++) {
    if (first) {
      str << " ";
      first = 0;
    } else
      str << ", ";
    str << *i;
  }
  str << " }";
}
void _run_test(long long N, vector< long long > primes, vector< long long > res_expected, int test_no) {
vector< long long > tc_res = (new TheKingsFactorization)->getVector(N, primes);
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
long long N;
vector< long long > primes;
vector< long long > res_expected;
N = 12LL;
{long long tmpa[] = {2LL, 3LL};
primes.assign(tmpa, tmpa + 2);}
{long long tmpa[] = {2LL, 2LL, 3LL};
res_expected.assign(tmpa, tmpa + 3);}
_run_test(N, primes, res_expected, 0);
N = 7LL;
{long long tmpa[] = {7LL};
primes.assign(tmpa, tmpa + 1);}
{long long tmpa[] = {7LL};
res_expected.assign(tmpa, tmpa + 1);}
_run_test(N, primes, res_expected, 1);
N = 1764LL;
{long long tmpa[] = {2LL, 3LL, 7LL};
primes.assign(tmpa, tmpa + 3);}
{long long tmpa[] = {2LL, 2LL, 3LL, 3LL, 7LL, 7LL};
res_expected.assign(tmpa, tmpa + 6);}
_run_test(N, primes, res_expected, 2);
N = 49LL;
{long long tmpa[] = {7LL};
primes.assign(tmpa, tmpa + 1);}
{long long tmpa[] = {7LL, 7LL};
res_expected.assign(tmpa, tmpa + 2);}
_run_test(N, primes, res_expected, 3);
N = 210LL;
{long long tmpa[] = {2LL, 5LL};
primes.assign(tmpa, tmpa + 2);}
{long long tmpa[] = {2LL, 3LL, 5LL, 7LL};
res_expected.assign(tmpa, tmpa + 4);}
_run_test(N, primes, res_expected, 4);
N = 100000LL;
{long long tmpa[] = {2LL, 2LL, 2LL, 5LL, 5LL};
primes.assign(tmpa, tmpa + 5);}
{long long tmpa[] = {2LL, 2LL, 2LL, 2LL, 2LL, 5LL, 5LL, 5LL, 5LL, 5LL};
res_expected.assign(tmpa, tmpa + 10);}
_run_test(N, primes, res_expected, 5);
}
// @end_tests

// Born in Emacs
