#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class RedGreenBlueLight {
public:
	vector <int> move(vector <int> steps) {
		int n = steps.size();
		vector<int> cnt(n+1, 0);
		for(int i = 0; i < steps.size(); i++) {
			if(steps[i] > n)
				continue;
			cnt[steps[i]]++;
		}
		int cur = cnt[n];
		for(int i = n-1; i >= 1; i--) {
			cur = cur / 3 + cnt[i];
		}
		if(cur < 3) {
			return {-1};
		}
		// first 1/3
		vector<int> red(n+1, 0);
		int need = 1;
		for(int i = 1; i <= n; i++, need *= 3) {
			while(cnt[i] > 0 && need > 0) {
				cnt[i]--;
				need--;
				red[i]++;
			}
			if(need == 0) {
				break;
			}
		}
		// second 1/3
		vector<int> green(n+1, 0);
		need = 1;
		for(int i = 1; i <= n; i++, need *= 3) {
			while(cnt[i] > 0 && need > 0) {
				green[i]++;
				cnt[i]--;
				need--;
			}
			if(need == 0) {
				break;
			}
		}
		vector<int> ans;
		for(int i = 0; i < steps.size(); i++) {
			if(steps[i] > n) {
				ans.push_back(2);
			} else if(red[steps[i]]) {
				ans.push_back(0);
				red[steps[i]]--;
			} else if(green[steps[i]]) {
				ans.push_back(1);
				green[steps[i]]--;
			} else {
				ans.push_back(2);
			}
		}
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	RedGreenBlueLight *obj;
	vector <int> answer;
	obj = new RedGreenBlueLight();
	clock_t startTime = clock();
	answer = obj->move(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	vector <int> p1;
	
	{
	// ----- test 0 -----
	int t0[] = {1,1,1,1,1,1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,2,2,1,0,2,0,0,2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {11,11,11,11,11,11,11,11,11,11};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {7,8,9,7,7,8,9,8,7,9,7,7,8,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,2,3,4,5,6,7,999888777,2,3,4,5,2,3,2,9,1,7,2,3,4,5,6,7,15};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,0,1,1,0,2,1,2,0,2,1,1,0,2,0,2,1,0,1,0,2,1,2,2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
