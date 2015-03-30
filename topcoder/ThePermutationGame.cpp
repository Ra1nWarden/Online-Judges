#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
#define MAXN 100005

using namespace std;

// @begin_lib
// @end_lib

class ThePermutationGame {
private:
  vector<int> primes;
  bool used[MAXN];
  int counter[MAXN];
public:
  int findMin(int N) {
    memset(used, true, sizeof used);
    for(int i = 2; i <= N; i++) {
      if(used[i]) {
	primes.push_back(i);
	for(int j = i + i; j <= N; j+=i)
	  used[j] = false;
      }
    }
    memset(counter, 0, sizeof counter);
    
    for(int i = 1; i <= N; i++) {
      for(int j = 0; j < primes.size(); j++) {
	if(primes[j] > i)
	  break;
	if(i % primes[j] == 0) {
	  int count = 0;
	  int copy = i;
	  while(copy % primes[j] == 0) {
	    count++;
	    copy /= primes[j];
	  }
	  counter[j] = max(counter[j], count);
	  //printf("counter[%d] = %d\n", j, counter[j]);
	}
      }
    }
    int ans = 1;
    for(int i = 0; i < primes.size(); i++) {
      for(int j = 0; j < counter[i]; j++) {
	ans = (ans * 1LL * primes[i]) % MOD;
      }
    }
    return ans;
  }
};

// @begin_tests
void _run_test(int N, int res_expected, int test_no) {
int tc_res = (new ThePermutationGame)->findMin(N);
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
N = 2;
res_expected = 2;
_run_test(N, res_expected, 0);
N = 3;
res_expected = 6;
_run_test(N, res_expected, 1);
N = 11;
res_expected = 27720;
_run_test(N, res_expected, 2);
N = 102;
res_expected = 53580071;
_run_test(N, res_expected, 3);
N = 9999;
res_expected = 927702802;
_run_test(N, res_expected, 4);
}
// @end_tests

// Born in Emacs
