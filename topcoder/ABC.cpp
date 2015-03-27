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

class ABC {
public:
  string createString(int N, int K) {
    for(int a = 0; a <= N; a++) {
      for(int b = 0; b <= N; b++) {
	if(a+b > N)
	  break;
	int c = N - a - b;
	int maxval = a * (b + c) + b * c;
	//cout << "maxval for " << a << " "<< b << " is " << maxval << endl;
	//cout << "K is " << K << endl;
	if(maxval >= K) {
	  //cout << "inside here" << endl;
	  //cout << maxval << " vs " << K << endl;
	  string res(N, ' ');
	  for(int i = 0; i < N; i++) {
	    if(i < a)
	      res[i] = 'A';
	    else if (i < a+b)
	      res[i] = 'B';
	    else
	      res[i] = 'C';
	  }
	  int diff = maxval - K;
	  while(diff > 0) {
	    for(int i = N-1; i > 0; i--) {
	      if(res[i] > res[i-1]) {
		swap(res[i], res[i-1]);
		diff--;
		break;
	      }
	    }
	  }
	  return res;
	}
      }
    }
    return "";
  }
};

// @begin_tests
void _run_test(int N, int K, string res_expected, int test_no) {
string tc_res = (new ABC)->createString(N, K);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
cout << '"' << res_expected << '"';
cout << endl << "got: ";
cout << '"' << tc_res << '"';
cout << endl;
}
}
int main() {
int N;
int K;
string res_expected;
N = 3;
K = 3;
res_expected = "ABC";
_run_test(N, K, res_expected, 0);
N = 3;
K = 0;
res_expected = "CBA";
_run_test(N, K, res_expected, 1);
N = 5;
K = 10;
res_expected = "";
_run_test(N, K, res_expected, 2);
N = 15;
K = 36;
res_expected = "CABBACCBAABCBBB";
_run_test(N, K, res_expected, 3);
}
// @end_tests

// Born in Emacs
