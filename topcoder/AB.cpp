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

class AB {
public:
  string createString(int N, int K) {
    int max = (N / 2) * (N - N / 2);
    if(max < K)
      return "";
    string res(N, ' ');
    for(int i = 0; i < N; i++) {
      if(i < N / 2)
	res[i] = 'A';
      else
	res[i] = 'B';
    }
    int diff = max - K;
    while(diff--) {
      int apos = N - 1;
      while(res[apos] == 'A')
	apos--;
      while(res[apos] == 'B')
	apos--;
      swap(res[apos], res[apos+1]);
    }
    return res;
  }
};

// @begin_tests
void _run_test(int N, int K, string res_expected, int test_no) {
string tc_res = (new AB)->createString(N, K);
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
K = 2;
res_expected = "ABB";
_run_test(N, K, res_expected, 0);
N = 2;
K = 0;
res_expected = "BA";
_run_test(N, K, res_expected, 1);
N = 5;
K = 8;
res_expected = "";
_run_test(N, K, res_expected, 2);
N = 10;
K = 12;
res_expected = "BAABBABAAB";
_run_test(N, K, res_expected, 3);
}
// @end_tests

// Born in Emacs
