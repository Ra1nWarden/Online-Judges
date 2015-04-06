#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;

// @begin_lib
// @end_lib

class OkonomiyakiParty {
public:
  int count(vector <int> osize, int M, int K) {
    sort(osize.begin(), osize.end());
    vector<vector<int> > choose(osize.size() + 1, vector<int>(osize.size() + 1, 0));
    for(int i = 0; i <= osize.size(); i++) {
      choose[i][0] = 1;
      for(int j= 1; j <= i; j++) {
	choose[i][j] = (int) (((long long) choose[i-1][j] + (long long) choose[i-1][j-1]) % MOD);
      }
    }

    int ans = 0;
    for(int i = 0; i < osize.size(); i++) {
      int next = osize[i];
      int bound = next + K;
      int possible = upper_bound(osize.begin(), osize.end(), bound) - osize.begin();
      if(possible == osize.size())
	possible--;
      if(osize[possible] > bound)
	possible--;
      if(possible == osize.size() - 1) {
	//cout << "choose " << possible - i+1 << " " << M << endl;
	ans = ((long long) ans + (long long) choose[possible - i + 1][M]) % MOD;
	break;
      } else {
	//cout << "choose " << possible - i << " " << M -1 << endl;
	ans = ((long long) choose[possible - i][M - 1] + (long long) ans) % MOD;
      }
    }
    return ans;
  }
};

// @begin_tests
void _run_test(vector< int > osize, int M, int K, int res_expected, int test_no) {
int tc_res = (new OkonomiyakiParty)->count(osize, M, K);
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
vector< int > osize;
int M;
int K;
int res_expected;
{int tmpa[] = {1, 4, 6, 7, 9};
osize.assign(tmpa, tmpa + 5);}
M = 2;
K = 3;
res_expected = 6;
_run_test(osize, M, K, res_expected, 0);
{int tmpa[] = {1, 6, 2, 7, 4, 2, 6, 1, 5, 2, 4};
osize.assign(tmpa, tmpa + 11);}
M = 4;
K = 3;
res_expected = 60;
_run_test(osize, M, K, res_expected, 1);
{int tmpa[] = {1, 4, 5, 7, 10, 11, 13, 16, 18};
osize.assign(tmpa, tmpa + 9);}
M = 4;
K = 5;
res_expected = 0;
_run_test(osize, M, K, res_expected, 2);
{int tmpa[] = {55, 2, 7, 232, 52, 5, 5332, 623, 52, 6, 532, 5147};
osize.assign(tmpa, tmpa + 12);}
M = 6;
K = 10000;
res_expected = 924;
_run_test(osize, M, K, res_expected, 3);
{int tmpa[] = {5781, 8708, 1754, 4750, 9888, 3675, 4810, 1020, 922, 9834, 5695, 1101, 1236, 2496, 8431, 6727, 1376, 3373, 4423, 1839, 7438, 9407, 1851, 6966, 8715, 2905, 542, 535, 8980, 2602, 2603, 3117, 3452, 5682, 7775, 4356, 5140, 8923, 9801, 3729};
osize.assign(tmpa, tmpa + 40);}
M = 15;
K = 4003;
res_expected = 114514;
_run_test(osize, M, K, res_expected, 4);
 {int tmpa[] = {1, 1, 1 ,1 ,1, 1, 1, 1 ,1 ,1, 1, 1, 1 ,1 ,1, 1, 1, 1 ,1 ,1, 1, 1, 1 ,1 ,1, 1, 1, 1 ,1 ,1, 1, 1, 1 ,1 ,1, 1, 1, 1 ,1 ,1, 1, 1, 1 ,1 ,1, 1, 1, 1, 1, 1};
osize.assign(tmpa, tmpa + 50);}
M = 25;
K = 1;
res_expected = 605552882;
_run_test(osize, M, K, res_expected, 5);
}
// @end_tests

// Born in Emacs
