#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>
#define MAXN 1050000
#define INF 2000000000

using namespace std;

// @begin_lib
// @end_lib

class OrderOfOperations {
private:
  int decode(string num) {
    int ans = 0;
    for(int i = 0; i < num.length(); i++) {
      if(num[i] == '1') {
	ans = ans | (1 << i);
      }
    }
    return ans;
  }
  int dp[MAXN];
  bool in_queue[MAXN];
  int calc_time(int u, int v) {
    int cnt = 0;
    for(int i = 1; i <= v; i <<= 1) {
      if(v&i) {
	if(!(u&i))
	  cnt++;
      }
    }
    return cnt * cnt;
  }
public:
  int minTime(vector <string> s) {
    vector<int> nums;
    int max_mask = 0;
    for(int i = 0; i < s.size(); i++) {
      int each = decode(s[i]);
      max_mask |= each;
      nums.push_back(each);
    }
    for(int i = max_mask; i; i=(i-1)&max_mask) {
      dp[i] = INF;
      in_queue[i] = false;
    }
    dp[0] = 0;
    queue<int> q;
    q.push(0);
    in_queue[0] = true;
    while(!q.empty()) {
      int next = q.front();
      q.pop();
      in_queue[next] = false;
      for(int i = 0; i < nums.size(); i++) {
	int new_mask = next | nums[i];
	int extra = calc_time(next, nums[i]);
	if(dp[next] + extra < dp[new_mask]) {
	  dp[new_mask] = dp[next] + extra;
	  if(!in_queue[new_mask]) {
	    q.push(new_mask);
	    in_queue[new_mask] = true;
	  }
	}
      }
    }
    return dp[max_mask];
  }
};

// @begin_tests
void _run_test(vector< string > s, int res_expected, int test_no) {
int tc_res = (new OrderOfOperations)->minTime(s);
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
vector< string > s;
int res_expected;
{string tmpa[] = {"111", "001", "010"};
s.assign(tmpa, tmpa + 3);}
res_expected = 3;
_run_test(s, res_expected, 0);
{string tmpa[] = {"11101", "00111", "10101", "00000", "11000"};
s.assign(tmpa, tmpa + 5);}
res_expected = 9;
_run_test(s, res_expected, 1);
{string tmpa[] = {"11111111111111111111"};
s.assign(tmpa, tmpa + 1);}
res_expected = 400;
_run_test(s, res_expected, 2);
{string tmpa[] = {"1000", "1100", "1110"};
s.assign(tmpa, tmpa + 3);}
res_expected = 3;
_run_test(s, res_expected, 3);
{string tmpa[] = {"111", "111", "110", "100"};
s.assign(tmpa, tmpa + 4);}
res_expected = 3;
_run_test(s, res_expected, 4);
}
// @end_tests

// Born in Emacs
