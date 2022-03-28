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
#include <cstring>
#include <ctime>
#include <functional>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> Node;

class JumpingTiger {
public:
	int travel(vector <string> plan) {
		II start = make_pair(-1, -1), end = make_pair(-1, -1);
		for(int i = 0; i < plan.size(); i++) {
			for(int j = 0; j < plan[i].length(); j++) {
				if(plan[i][j] == 'T')
					start = make_pair(i, j);
				else if(plan[i][j] == 'L')
					end = make_pair(i, j);
			}
		}
		int max_x = plan.size();
		int max_y = plan[0].length();
		priority_queue<Node, vector<Node>, greater<Node> > pq;
		pq.push(make_pair(0, start));
		int ans = -1;
		bool vis[50][50];
		memset(vis, false, sizeof vis);
		while(!pq.empty()) {
			Node u = pq.top();
			pq.pop();
			II cur = u.second;
			vis[cur.first][cur.second] = true;
			//cout << "top node is " << cur.first << ", " << cur.second << " distance " << u.first << endl;
			if(cur == end) {
				ans = u.first;
				break;
			}
			int dx[4] = {-1, 0, 1, 0};
			int dy[4] = {0, 1, 0, -1};
			for(int dir = 0; dir < 4; dir++) {
				// 1 step
				int xx = cur.first + dx[dir];
				int yy = cur.second + dy[dir];
				if(xx >= 0 && xx < max_x && yy >= 0 && yy < max_y && plan[xx][yy] != '#') {
					if(!vis[xx][yy]) {
						pq.push(make_pair(u.first + 1, make_pair(xx, yy)));
					}
				}
				for(int len = 2; len > 0; len++) {
					xx = cur.first + dx[dir] * len;
					yy = cur.second + dy[dir] * len;
					int xx_1 = xx + dx[dir];
					int yy_1 = yy + dy[dir];
					if(xx_1 < 0 || xx_1 >= max_x || yy_1 < 0 || yy_1 >= max_y) {
						break;
					}
					if(plan[xx_1][yy_1] != '#' && plan[xx][yy] != '#') {
						if(!vis[xx_1][yy_1]) {
							pq.push(make_pair(u.first + 2, make_pair(xx_1, yy_1)));
						}
					}
				}
			}
		}
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	JumpingTiger *obj;
	int answer;
	obj = new JumpingTiger();
	clock_t startTime = clock();
	answer = obj->travel(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"T.######","#..#####","##..####","###..###","####..##","#####..#","######..","#######L"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 14;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"T.######","#..#####","##..####","###..###","####..##","#####..#","######..",".######L"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 14;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"T.######","#..#####","##..####","###..###","####..##","#####..#",".#####..",".######L"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 6;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"T.######","#..#####","##..####","###..###","####..##","#####..#",".#####..",".#####.L"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {".##.","#L##","####",".#T#"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -1;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"T","#","#","L","#","#",".","."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -1;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"T######..####.##.L###"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 7 -----
	string t0[] = {".########.....####.....#########..#.......",".#########..#######....###########..#####.","#########################################.","..#..##############.###############..#####","..#..#############..################.####.","..#..###########.#.######################.","####..##########.##..########..#########..","#.#.############.##.####################..","#.#.######################################",".############..##..#####################.#",".#######################################.#","##########################################","#########.#############.##################","####..###.########..###.#######T##########","###################.######################","##########################################","#########..##########################.####","#####################################.####","##########################################","####..##########################..##..#.##",".######################################.##",".#########################################","#.########"
			"################################","#.######..##.....##################...####","#####################################.####","#########.##############################.#","#..######.##...###..#########..#####.##.L#","####################################.#####","##########################.########..#####","##########################.###############","##########################################","########################################.#","########################################.#",".##################.######################",".####..############.######################","#####################################.####","#####################################.####","..####.#..###..#####.###################.#","######.#############.###################.#","####################.##############..#####","########################################.#","############.######.####################..","#####..#####.######.#.##############......","#.####..########.###.....############....#","#.#############..###."
			"################.##.#",".#####.############.###.#############.##.#",".....#.#..######.##.##...#######...#..#..#","...#############...####..#..#######......#","##########..####.###..#..#.#########..##.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 9;
	all_right = KawigiEdit_RunTest(7, p0, true, p1) && all_right;
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
