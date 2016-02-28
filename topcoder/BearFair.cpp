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

typedef pair<int, int> II;

class BearFair {
public:
  string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
    vector<II> ranges;
    for(int i = 0; i < upTo.size(); i++) {
      ranges.push_back(make_pair(upTo[i], quantity[i]));
    }
    sort(ranges.begin(), ranges.end());
    if(ranges.back().first != b) {
      ranges.push_back(make_pair(b, n));
    } else if(ranges.back().second != n) {
      return "unfair";
    }
    bool check = true;
    for(int i = 1; i < ranges.size() && check; i++) {
      if(ranges[i].first == ranges[i-1].first && ranges[i].second != ranges[i-1].second) {
	check = false;
      }
      if(ranges[i].second < ranges[i-1].second) {
	check = false;
      }
    }
    if(!check)
      return "unfair";
    int even = 0, odd = 0;
    int start = 1, end = 1;
    int prev = 0;
    for(int i = 0; i < ranges.size(); i++) {
      end = ranges[i].first;
      int num = ranges[i].second - prev;
      int len = end - start + 1;
      if(num > len) {
	return "unfair";
      }
      if(len & 1) {
	if(start & 1) {
	  even += max(0, num - ((len + 1) >> 1));
	  odd += max(0, num - (len >> 1));
	} else {
	  even += max(0, num - (len >> 1));
	  odd += max(0, num - ((len + 1) >> 1));
	}
      } else {
	odd += max(0, num - (len >> 1));
	even += max(0, num - (len >> 1));
      }
      prev = ranges[i].second;
      start = end + 1;
    }
    int thresh = n >> 1;
    if(even > thresh || odd > thresh) {
      return "unfair";
    } else {
      return "fair";
    }
  }
};

// @begin_tests
void _run_test(int n, int b, vector< int > upTo, vector< int > quantity, string res_expected, int test_no) {
string tc_res = (new BearFair)->isFair(n, b, upTo, quantity);
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
int n;
int b;
vector< int > upTo;
vector< int > quantity;
string res_expected;
n = 4;
b = 6;
{int tmpa[] = {3, 6};
upTo.assign(tmpa, tmpa + 2);}
{int tmpa[] = {2, 4};
quantity.assign(tmpa, tmpa + 2);}
res_expected = "fair";
_run_test(n, b, upTo, quantity, res_expected, 0);
n = 4;
b = 6;
{int tmpa[] = {3, 6};
upTo.assign(tmpa, tmpa + 2);}
{int tmpa[] = {2, 3};
quantity.assign(tmpa, tmpa + 2);}
res_expected = "unfair";
_run_test(n, b, upTo, quantity, res_expected, 1);
n = 2;
b = 6;
{int tmpa[] = {1, 2, 3};
upTo.assign(tmpa, tmpa + 3);}
{int tmpa[] = {1, 1, 2};
quantity.assign(tmpa, tmpa + 3);}
res_expected = "unfair";
_run_test(n, b, upTo, quantity, res_expected, 2);
n = 50;
b = 1000;
{int tmpa[] = {736, 205, 264, 235, 273, 40, 901, 37, 900, 424, 122, 517, 820, 402, 669, 279, 455, 921, 774, 923, 107, 936, 484, 171, 248, 186, 970, 231, 321, 902, 606, 24, 451, 585, 823, 270, 361, 292, 128, 521, 689, 683, 270, 726, 980, 652, 996, 909, 196, 357};
upTo.assign(tmpa, tmpa + 50);}
{int tmpa[] = {35, 9, 9, 9, 9, 3, 46, 3, 46, 18, 7, 25, 39, 18, 32, 9, 20, 49, 37, 49, 7, 49, 24, 8, 9, 8, 49, 9, 12, 46, 29, 2, 20, 29, 39, 9, 16, 11, 7, 27, 33, 32, 9, 34, 49, 32, 50, 47, 8, 16};
quantity.assign(tmpa, tmpa + 50);}
res_expected = "fair";
_run_test(n, b, upTo, quantity, res_expected, 3);
n = 4;
b = 1000;
{int tmpa[] = {400, 600};
upTo.assign(tmpa, tmpa + 2);}
{int tmpa[] = {4, 0};
quantity.assign(tmpa, tmpa + 2);}
res_expected = "unfair";
_run_test(n, b, upTo, quantity, res_expected, 4);
}
// @end_tests

// Born in Emacs
