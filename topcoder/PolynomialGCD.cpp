#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
#define INF 2000000000

using namespace std;

// @begin_lib
// @end_lib

class PolynomialGCD {
public:
  int gcd(string s) {
    bool pv[10001];
    memset(pv, true, sizeof pv);
    vector<int> primes;
    for(int i = 2; i <= 10000; i++) {
      if(pv[i]) {
	primes.push_back(i);
	for(int j = i + i; j <= 10000; j += i) {
	  pv[j] = false;
	}
      }    
    }
    
    int ans = 1;
    for(int i = 0; i < primes.size(); i++) {
      int p = primes[i];
      if(p > s.length())
	break;
      int maxpow = INF;
      for(int pr = 1; pr < p; pr++) {
	int power = 0;
	for(int j = pr; j < s.length(); j += p) {
	  int dig = s[j] - '0';
	  power += dig;
	}
	maxpow = min(maxpow, power);
      }
      if(maxpow != INF) {
	long long mult = 1LL;
	for(int j = 0; j < maxpow; j++) {
	  mult = mult * p;
	  mult %= MOD;
	}
	ans =  (((long long) ans) * mult) % MOD;
      }
    }
    return ans;
  }
};

// @begin_tests
void _run_test(string s, int res_expected, int test_no) {
int tc_res = (new PolynomialGCD)->gcd(s);
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
string s;
int res_expected;
s = "111";
res_expected = 6;
_run_test(s, res_expected, 0);
s = "00000";
res_expected = 1;
_run_test(s, res_expected, 1);
s = "2014";
res_expected = 16;
_run_test(s, res_expected, 2);
s = "31415926535";
res_expected = 659897170;
_run_test(s, res_expected, 3);
}
// @end_tests

// Born in Emacs
