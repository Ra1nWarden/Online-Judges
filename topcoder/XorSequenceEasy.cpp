#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

// @begin_lib
// @end_lib

class XorSequenceEasy {
public:
  int getmax(vector <int> A, int N) {
    int bitcount = 0;
    while(N != 1) {
      N >>= 1;
      bitcount++;
    }
    int profits[bitcount][2];
    memset(profits, 0, sizeof profits);
    for(int i = 0 ;i < A.size(); i++) {
      for(int j = i+1; j < A.size(); j++) {
	for(int k = bitcount - 1; k >= 0; k--) {
	  if((A[i] >> k) != (A[j] >> k)) {
	    if((A[i] >> k) < (A[j] >> k))
	      profits[k][0]++;
	    else
	      profits[k][1]++;
	    break;
	  }
	}
      }
    }
    int res = 0;
    for(int i = 0; i < bitcount; i++)
      res += max(profits[i][0], profits[i][1]);
    return res;
  }
};

// @begin_tests
void _run_test(vector< int > A, int N, int res_expected, int test_no) {
int tc_res = (new XorSequenceEasy)->getmax(A, N);
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
vector< int > A;
int N;
int res_expected;
{int tmpa[] = {3, 2, 1, 0, 3, 2};
A.assign(tmpa, tmpa + 6);}
N = 4;
res_expected = 8;
_run_test(A, N, res_expected, 0);
{int tmpa[] = {3, 0, 4, 6, 1, 5, 7, 6};
A.assign(tmpa, tmpa + 8);}
N = 8;
res_expected = 21;
_run_test(A, N, res_expected, 1);
{int tmpa[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};
A.assign(tmpa, tmpa + 15);}
N = 16;
res_expected = 76;
_run_test(A, N, res_expected, 2);
{int tmpa[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
A.assign(tmpa, tmpa + 21);}
N = 8;
res_expected = 0;
_run_test(A, N, res_expected, 3);
{int tmpa[] = {408024109, 11635919, 196474438, 117649705, 812669700, 553475508, 445349752, 271145432, 730417256, 738416295, 147699711, 880268351, 816031019, 686078705, 1032012284, 182546393, 875376506, 220137366, 906190345, 16216108, 799485093, 715669847, 413196148, 122291044, 777206980, 68706223, 769896725, 212567592, 809746340, 964776169, 928126551, 228208603, 918774366, 352800800, 849040635, 941604920, 326686120, 920977486, 964528038, 659998484, 207195539, 607901477, 725914710, 655525412, 949610052, 142750431, 766838105, 1024818573, 836758851, 97228667};
A.assign(tmpa, tmpa + 50);}
N = 1073741824;
res_expected = 720;
_run_test(A, N, res_expected, 4);
}
// @end_tests

// Born in Emacs
