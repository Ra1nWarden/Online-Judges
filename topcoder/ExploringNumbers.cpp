#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

// @begin_lib
// @end_lib

const int maxn = 800;
bool check[maxn+1];

class ExploringNumbers {
private:
  vector<int> primes;
  void init() {
    memset(check, false, sizeof check);
    for(int i = 2; i <= maxn; i++) {
      if(!check[i])
	primes.push_back(i);
      for(int j = 0; j < primes.size(); j++) {
	if(i * primes[j] > maxn)
	  break;
	check[i * primes[j]] = true;
	if(i % primes[j] == 0)
	  break;
      }
    }
  }
  bool is_prime(int num) {
    for(int i = 2; i * i <= num; i++) {
      if(num % i == 0) {
	return false;
      }
    }
    return true;
  }
  int next_num(int num) {
    int ans = 0;
    while(num) {
      int digit = num % 10;
      num /= 10;
      ans += digit * digit;
    }
    return ans;
  }
  bool check_prime(int num) {
    int idx = lower_bound(primes.begin(), primes.end(), num) - primes.begin();
    if(idx >= primes.size() || primes[idx] != num)
      return false;
    return true;
  }
public:
  int numberOfSteps(int n) {
    if(n == 1)
      return -1;
    init();
    set<int> seen;
    seen.insert(n);
    int ans = 1;
    if(is_prime(n)) {
      return ans;
    }
    int num = n;
    bool loop = false;
    while(!check_prime(num) && ans < n) {
      num = next_num(num);
      ans++;
      if(seen.count(num)) {
	loop = true;
	break;
      }
      seen.insert(num);
    }
    if(loop)
      return -1;
    else
      return ans;
  }
};

// @begin_tests
void _run_test(int n, int res_expected, int test_no) {
int tc_res = (new ExploringNumbers)->numberOfSteps(n);
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
int n;
int res_expected;
n = 5;
res_expected = 1;
_run_test(n, res_expected, 0);
n = 57;
res_expected = 4;
_run_test(n, res_expected, 1);
n = 1;
res_expected = -1;
_run_test(n, res_expected, 2);
n = 6498501;
res_expected = 2;
_run_test(n, res_expected, 3);
n = 989113;
res_expected = 6;
_run_test(n, res_expected, 4);
n = 12366;
res_expected = -1;
_run_test(n, res_expected, 5);
}
// @end_tests

// Born in Emacs
