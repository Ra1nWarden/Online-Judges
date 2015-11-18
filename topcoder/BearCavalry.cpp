#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

const int mod = 1e9+7;

class BearCavalry {
public:
  int countAssignments(vector <int> warriors, vector <int> horses) {
    int head = warriors[0];
    int ans = 0;
    sort(warriors.begin() + 1, warriors.end(), greater<int>());
    sort(horses.begin(), horses.end());
    for(int i = 0; i < horses.size(); i++) {
      int cap = head * horses[i];
      int cnt = 1;
      for(int j = 1; j < warriors.size(); j++) {
	int max_horse = cap / warriors[j];
	int idx;
	if(max_horse * warriors[j] == cap) {
	  idx = lower_bound(horses.begin(), horses.end(), max_horse) - horses.begin();
	  if(idx == horses.size())
	    idx--;
	  else if(horses[idx] * warriors[j] >= cap)
	    idx--;
	} else {
	  idx = upper_bound(horses.begin(), horses.end(), max_horse) - horses.begin();
	  idx--;
	}
	//printf("before sub index is %d\n", idx);
	if(idx >= i)
	  idx--;
	//printf("last index is %d\n", idx);
	idx++;
	idx -= (j - 1);
	//printf("i=%d j=%d idx=%d\n", i, j, idx);
	if(idx <= 0) {
	  cnt = 0;
	  break;
	}
	cnt = (cnt * 1LL * idx) % mod;
      }
      //printf("i=%d cnt is %d\n", i, cnt);
      ans = (ans + cnt) % mod;
    }
    return ans;
  }
};

// @begin_tests
void _run_test(vector< int > warriors, vector< int > horses, int res_expected, int test_no) {
int tc_res = (new BearCavalry)->countAssignments(warriors, horses);
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
vector< int > warriors;
vector< int > horses;
int res_expected;
{int tmpa[] = {5, 8, 4, 8};
warriors.assign(tmpa, tmpa + 4);}
{int tmpa[] = {19, 40, 25, 20};
horses.assign(tmpa, tmpa + 4);}
res_expected = 2;
_run_test(warriors, horses, res_expected, 0);
{int tmpa[] = {1, 1};
warriors.assign(tmpa, tmpa + 2);}
{int tmpa[] = {1, 1};
horses.assign(tmpa, tmpa + 2);}
res_expected = 0;
_run_test(warriors, horses, res_expected, 1);
{int tmpa[] = {10, 2, 10};
warriors.assign(tmpa, tmpa + 3);}
{int tmpa[] = {100, 150, 200};
horses.assign(tmpa, tmpa + 3);}
res_expected = 3;
_run_test(warriors, horses, res_expected, 2);
{int tmpa[] = {10, 20};
warriors.assign(tmpa, tmpa + 2);}
{int tmpa[] = {1, 3};
horses.assign(tmpa, tmpa + 2);}
res_expected = 1;
_run_test(warriors, horses, res_expected, 3);
{int tmpa[] = {20, 20, 25, 23, 24, 24, 21};
warriors.assign(tmpa, tmpa + 7);}
{int tmpa[] = {20, 25, 25, 20, 25, 23, 20};
horses.assign(tmpa, tmpa + 7);}
res_expected = 0;
_run_test(warriors, horses, res_expected, 4);
{int tmpa[] = {970, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800};
warriors.assign(tmpa, tmpa + 50);}
{int tmpa[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
horses.assign(tmpa, tmpa + 50);}
res_expected = 318608048;
_run_test(warriors, horses, res_expected, 5);
{int tmpa[] = {7, 1, 2, 2};
warriors.assign(tmpa, tmpa + 4);}
{int tmpa[] = {13, 19, 2, 1};
horses.assign(tmpa, tmpa + 4);}
res_expected = 12;
_run_test(warriors, horses, res_expected, 6);
}
// @end_tests

// Born in Emacs
