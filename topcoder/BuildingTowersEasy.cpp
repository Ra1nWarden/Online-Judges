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

class BuildingTowersEasy {
public:
  int maxHeight(int N, vector <int> x, vector <int> t) {
    if(x.empty())
      return N - 1;

    for(int i = 0; i < x.size(); i++)
      t[i] = min(t[i], x[i] - 1);

    for(int i = 0; i < x.size(); i++) {
      if(t[i] < (i == 0 ? 0 : t[i-1]) && (i == 0 ? 0 : t[i-1]) - t[i] > x[i] - (i == 0 ? 1 : x[i-1])) {
	t[i-1] = t[i] + (x[i] - (i == 0 ? 1 : x[i-1]));
	i -= 2;
	//printf("changed %d to %d\n", i-1, t[i-1]);
      }
    }
    x.push_back(N);
    t.push_back(N);
    int res = 0;
    int height = 0;
    for(int i = 0; i < x.size(); i++) {
      //printf("at i = %d, previous height = %d restriction is %d pos is %d\n", i, height, t[i], x[i]);
      int maxnewheight = height + x[i] - (i == 0 ? 1 : x[i-1]);
      if(maxnewheight <= t[i]) {
	res = max(res, maxnewheight);
	height = maxnewheight;
      } else {
	maxnewheight = height + (x[i] - (i == 0 ? 1 : x[i-1]) - (height - t[i])) / 2;
	res = max(res, maxnewheight);
	height = t[i];
      }
    }
    return res;
  }
};

// @begin_tests
void _run_test(int N, vector< int > x, vector< int > t, int res_expected, int test_no) {
int tc_res = (new BuildingTowersEasy)->maxHeight(N, x, t);
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
vector< int > x;
vector< int > t;
int res_expected;
N = 10;
{int tmpa[] = {3, 8};
x.assign(tmpa, tmpa + 2);}
{int tmpa[] = {1, 1};
t.assign(tmpa, tmpa + 2);}
res_expected = 3;
_run_test(N, x, t, res_expected, 0);
N = 100000;
x.clear();
t.clear();
res_expected = 99999;
_run_test(N, x, t, res_expected, 1);
N = 2718;
{int tmpa[] = {1, 30, 400, 1300, 2500};
x.assign(tmpa, tmpa + 5);}
{int tmpa[] = {100000, 100000, 100000, 100000, 100000};
t.assign(tmpa, tmpa + 5);}
res_expected = 2717;
_run_test(N, x, t, res_expected, 2);
N = 20;
{int tmpa[] = {4, 7, 13, 15, 18};
x.assign(tmpa, tmpa + 5);}
{int tmpa[] = {3, 8, 1, 17, 16};
t.assign(tmpa, tmpa + 5);}
res_expected = 8;
_run_test(N, x, t, res_expected, 3);
N = 447;
{int tmpa[] = {32, 35, 55, 60, 61, 88, 91, 97, 128, 151, 181, 186, 192, 196, 198, 237, 259, 268, 291, 314, 341, 367, 389, 390, 391, 428, 435};
x.assign(tmpa, tmpa + 27);}
{int tmpa[] = {81, 221, 172, 641, 25, 953, 330, 141, 123, 440, 692, 394, 200, 649, 78, 726, 50, 810, 501, 4, 216, 407, 2, 172, 0, 29, 14};
t.assign(tmpa, tmpa + 27);}
res_expected = 120;
_run_test(N, x, t, res_expected, 4);
N = 97638;
{int tmpa[] = {8, 1749, 4550, 5388, 6752, 7089, 9737, 14891, 16671, 16821, 17691, 19753, 24589, 25348, 30114, 32213, 34376, 36467, 37699, 41490, 44784, 44893, 57316, 58275, 58567, 61122, 61489, 63195, 64776, 65905, 68788, 69908, 72853, 78152, 78784, 82779, 84488, 86277, 88611, 92793, 93214, 97583};
x.assign(tmpa, tmpa + 42);}
{int tmpa[] = {16610, 6, 497, 14, 42892, 31, 79, 1203, 518, 31147, 597, 7846, 1396, 8309, 12, 14, 1148, 433, 23693, 13, 1939, 244, 19, 46, 27, 611, 412, 10, 27023, 19141, 34, 15667, 588, 10, 229, 83, 390, 14, 38441, 16021, 4, 39386};
t.assign(tmpa, tmpa + 42);}
res_expected = 6343;
_run_test(N, x, t, res_expected, 5);
}
// @end_tests

// Born in Emacs
