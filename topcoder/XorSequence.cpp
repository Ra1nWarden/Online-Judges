#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#define MAXN 140000

using namespace std;

// @begin_lib
// @end_lib

typedef pair<long long, int> ii;

bool _cmp(const ii& a, const ii& b) {
  return a.first < b.first;
}

class XorSequence {
public:
  int C[MAXN];
  int lowbit(int x) {
    return x & (-x);
  }
  int sum(int x) {
    int ret = 0;
    while(x > 0) {
      ret += C[x];
      x -= lowbit(x);
    }
    return ret;
  }
  void add(int x, int d) {
    while(x <= MAXN) {
      C[x] += d;
      x += lowbit(x);
    }
  }

  ii V[MAXN];
  long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R) {
    long long A[sz];
    A[0] = (long long) A0;
    A[1] = (long long) A1;
    for(int i= 2; i < sz; i++) {
      A[i] = (A[i-2] * P + A[i-1]*Q + R) % N;
    }

    for(int i = 0; i < sz; i++)
      V[i] = make_pair(A[i], i + 1);
   
    sort(V, V+sz, _cmp);
 

    int bitcount = 0;
    while(N != 1) {
      N >>= 1;
      bitcount++;
    }
    long long res = 0;

    for(int i = bitcount; i > 0; i--) {
      int bitmask = ((1 << (bitcount - i)) - 1) << i;
    
      int start = 0;
      long long case0 = 0;
      long long case1 = 0;
      while(start < sz) {
	int end = start;
	long long sumVal = 0;
	int numZero = 0;
	int numOne = 0;
	memset(C, 0, sizeof C);
	while(end < sz && (V[start].first & bitmask) == (V[end].first & bitmask)) {

	  if(((1 << (i - 1)) & V[end].first) != 0) {
	    sumVal += sum(V[end].second);
	    numOne++;
	  } else {
	    add(V[end].second, 1);
	    numZero++;
	  }
	  end++;
	}
	case0 += sumVal;
	case1 += (long long) numOne * numZero - sumVal;
	start = end;
      }
    
      res += max(case0, case1);
    }
    return res;
  }
};

// @begin_tests
void _run_test(int N, int sz, int A0, int A1, int P, int Q, int R, long long res_expected, int test_no) {
long long tc_res = (new XorSequence)->getmax(N, sz, A0, A1, P, Q, R);
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
int sz;
int A0;
int A1;
int P;
int Q;
int R;
long long res_expected;
N = 4;
sz = 6;
A0 = 3;
A1 = 2;
P = 0;
Q = 1;
R = 3;
res_expected = 8LL;
_run_test(N, sz, A0, A1, P, Q, R, res_expected, 0);
N = 8;
sz = 8;
A0 = 2;
A1 = 5;
P = 3;
Q = 1;
R = 4;
res_expected = 13LL;
_run_test(N, sz, A0, A1, P, Q, R, res_expected, 1);
N = 8;
sz = 7;
A0 = 3;
A1 = 0;
P = 1;
Q = 2;
R = 4;
res_expected = 12LL;
_run_test(N, sz, A0, A1, P, Q, R, res_expected, 2);
N = 32;
sz = 15;
A0 = 7;
A1 = 9;
P = 11;
Q = 2;
R = 1;
res_expected = 60LL;
_run_test(N, sz, A0, A1, P, Q, R, res_expected, 3);
N = 131072;
sz = 131072;
A0 = 7;
A1 = 7;
P = 1;
Q = 0;
R = 0;
res_expected = 0LL;
_run_test(N, sz, A0, A1, P, Q, R, res_expected, 4);
N = 131072;
sz = 131070;
A0 = 411;
A1 = 415;
P = 398;
Q = 463;
R = 9191;
res_expected = 4302679760LL;
_run_test(N, sz, A0, A1, P, Q, R, res_expected, 5);
}
// @end_tests

// Born in Emacs
