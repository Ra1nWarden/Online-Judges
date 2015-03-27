#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#define INF 2e9

using namespace std;

// @begin_lib
// @end_lib

class TheConsecutiveIntegersDivOne {
public:
  int find(vector <int> numbers, int k) {
    sort(numbers.begin(), numbers.end());
    int result = INF;
    for(int i = 0; i < numbers.size(); i++) {
      int fixed = numbers[i];
      for(int j = max(0, k - ((int) numbers.size() - i)); j <= min(k-1, i); j++) {
	int res = 0;
	for(int l = i - j; l < i - j + k; l++) {
	  res += abs(numbers[l] - (fixed + l - i));
	}
	//cout << "find res " << res << " fixed is " << fixed << " i is " << i <<  " j is " << j << endl;
	result = min(result, res);
      }
    }
    return result;
  }
};

// @begin_tests
void _run_test(vector< int > numbers, int k, int res_expected, int test_no) {
int tc_res = (new TheConsecutiveIntegersDivOne)->find(numbers, k);
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
vector< int > numbers;
int k;
int res_expected;
{int tmpa[] = {4, 7, 47};
numbers.assign(tmpa, tmpa + 3);}
k = 2;
res_expected = 2;
_run_test(numbers, k, res_expected, 0);
{int tmpa[] = {1, 100};
numbers.assign(tmpa, tmpa + 2);}
k = 1;
res_expected = 0;
_run_test(numbers, k, res_expected, 1);
{int tmpa[] = {-96, -53, 82, -24, 6, -75};
numbers.assign(tmpa, tmpa + 6);}
k = 2;
res_expected = 20;
_run_test(numbers, k, res_expected, 2);
{int tmpa[] = {64, -31, -56};
numbers.assign(tmpa, tmpa + 3);}
k = 2;
res_expected = 24;
_run_test(numbers, k, res_expected, 3);
{int tmpa[] = {-96, -53, 82, -24, 6, -75};
numbers.assign(tmpa, tmpa + 6);}
k = 4;
res_expected = 90;
_run_test(numbers, k, res_expected, 4);
{int tmpa[] = {905094, -9856209, -5067503, 2152352, 6069125, 6070805, -3078364, 3447730, 8533640, 8101663, 5627524, 7232490, 5409193, -6902965, -9001727, 7082618, -4761194, 9863063, 4156041, -6268386, -2551014, -1459606, 6848269, -2591702, -1581233, 4052341, -7692095, -251864, -6426888, 8421368, -9552201, 4005431, -9852381, -6312701, 1751043, 5428343, 3952329, -5260966, -6860219, -6470224, 6032682};
numbers.assign(tmpa, tmpa + 41);}
k = 30;
res_expected = 109318407;
_run_test(numbers, k, res_expected, 5);
}
// @end_tests

// Born in Emacs
