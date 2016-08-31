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

class LCMGCD {
public:
  int count_fact(int num, int fact) {
    int ans = 0;
    while(num % fact == 0) {
      num /= fact;
      ans++;
    }
    return ans;
  }
  bool check(vector<int> x, int t) {
    vector<int> two, three;
    int t2 = count_fact(t, 2);
    int t3 = count_fact(t, 3);
    printf("t has %d %d\n", t2, t3);
    for(int i = 0; i < x.size(); i++) {
      two.push_back(count_fact(x[i], 2));
      three.push_back(count_fact(x[i], 3));
      printf("%d has %d %d\n", x[i], two[i], three[i]);
    }
    for(int i = 0; i < x.size(); i++) {
      if(two[i] == t2 && three[i] == t3) {
	if(x.size() == 1)
	  return true;
	int min2 = 2000000000;
	int max2 = 0;
	int min3 = 2000000000;
	int max3 = 0;
	for(int j = 0; j < x.size(); j++) {
	  if(j == i)
	    continue;
	  min2 = min(min2, two[j]);
	  min3 = min(min3, three[j]);
	  max2 = max(max2, two[j]);
	  max3 = max(max3, three[j]);
	}
	if(min2 <= t2 && min3 <= t3)
	  return true;
	if(max2 >= t2 && max3 >= t3)
	  return true;
      }
    }
    for(int i = 0; i < x.size(); i++) {
      for(int j = i+1; j < x.size(); j++) {
	if((two[i] == t2 && three[i] < t3 && two[j] < t2 && three[j] == t3) || (two[i] < t2 && three[i] == t3 && two[j] == t2 && three[j] < t3) || (two[i] == t2 && three[i] > t3 && two[j] > t2 && three[j] == t3) || (two[i] > t2 && three[i] == t3 && two[j] == t2 && three[j] > t3)) {
	  if(x.size() == 2)
	    return true;
	  int min2 = 2000000000;
	  int max2 = 0;
	  int min3 = 2000000000;
	  int max3 = 0;
	  for(int k = 0; k < x.size(); k++) {
	    if(k == i || k == j)
	      continue;
	    min2 = min(min2, two[j]);
	    min3 = min(min3, three[j]);
	    max2 = max(max2, two[j]);
	    max3 = max(max3, three[j]);
	  }
	  if(min2 <= t2 && min3 <= t3)
	    return true;
	  if(max2 >= t2 && max3 >= t3)
	    return true;
	}
      }
    }
    for(int i = 0; i < x.size(); i++) {
      for(int j = i+1; j < x.size(); j++) {
	if((two[i] == t2 && three[j] == t3) || (three[i] == t3 && two[j] == t2) || (two[i] == t2 && three[j] == t3) || (three[i] == t3 && two[j] == t2)) {
	  if(x.size() == 2)
	    return true;
	  int min2 = 2000000000;
	  int max2 = 0;
	  int min3 = 2000000000;
	  int max3 = 0;
	  for(int k = 0; k < x.size(); k++) {
	    if(k == i || k == j)
	      continue;
	    min2 = min(min2, two[j]);
	    min3 = min(min3, three[j]);
	    max2 = max(max2, two[j]);
	    max3 = max(max3, three[j]);
	  }
	  int v2[3] = {two[i], two[j], min2};
	  int v3[3] = {three[i], three[j], min3};
	  if(try_all(v2, v3, t2, t3)) {
	    return true;
	  }
	  v2[2] = max2;
	  v3[3] = max3;
	  if(try_all(v2, v3, t2, t3)) {
	    return true;
	  }
	}
      }
    }
   
    return false;
  }
  string isPossible(vector <int> x, int t) {
    return check(x, t) ? "Possible" : "Impossible";
  }
};

// @begin_tests
void _run_test(vector< int > x, int t, string res_expected, int test_no) {
string tc_res = (new LCMGCD)->isPossible(x, t);
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
vector< int > x;
int t;
string res_expected;
{int tmpa[] = {2, 3};
x.assign(tmpa, tmpa + 2);}
t = 6;
res_expected = "Possible";
_run_test(x, t, res_expected, 0);
{int tmpa[] = {4, 9};
x.assign(tmpa, tmpa + 2);}
t = 6;
res_expected = "Impossible";
_run_test(x, t, res_expected, 1);
{int tmpa[] = {6, 12, 24, 18, 36, 72, 54, 108, 216};
x.assign(tmpa, tmpa + 9);}
t = 36;
res_expected = "Possible";
_run_test(x, t, res_expected, 2);
{int tmpa[] = {6, 27, 81, 729};
x.assign(tmpa, tmpa + 4);}
t = 6;
res_expected = "Impossible";
_run_test(x, t, res_expected, 3);
{int tmpa[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
x.assign(tmpa, tmpa + 50);}
t = 1;
res_expected = "Possible";
_run_test(x, t, res_expected, 4);
{int tmpa[] = {72, 16, 16, 16, 16, 16, 27, 27, 27, 27, 27, 27, 27, 27, 27};
x.assign(tmpa, tmpa + 15);}
t = 72;
res_expected = "Possible";
_run_test(x, t, res_expected, 5);
{int tmpa[] = {100663296, 544195584, 229582512, 59049};
x.assign(tmpa, tmpa + 4);}
t = 60466176;
res_expected = "Possible";
_run_test(x, t, res_expected, 6);
{int tmpa[] = {2, 4, 8, 16, 32, 64};
x.assign(tmpa, tmpa + 6);}
t = 256;
res_expected = "Impossible";
_run_test(x, t, res_expected, 7);
}
// @end_tests

// Born in Emacs
