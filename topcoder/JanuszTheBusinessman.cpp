#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#define INF 2e9

using namespace std;

// @begin_lib
// @end_lib

class JanuszTheBusinessman {
private:
  int adjMat[732][732];
  map<int, int> p;
  map<int, vector<int> > adjList;
  int f, s, t;
public:
  void augmentPath(int v, int minEdge) {
    if(v == s) {
      f= minEdge;
      return;
    } else if (p.count(v)) {
      augmentPath(p[v], min(minEdge, adjMat[p[v]][v]));
      adjMat[p[v]][v] -= f;
      adjMat[v][p[v]] += f;
    }
  }
  int makeGuestsReturn(vector <int> arrivals, vector <int> departures) {
    memset(adjMat, -1, sizeof adjMat);
    for(int i = 1; i <= arrivals.size(); i++) {
      adjMat[0][i] = 1;
      adjList[0].push_back(i);
      adjList[i].push_back(0);
      adjMat[i+365][731] = 1;
      adjList[i+365].push_back(731);
      adjList[731].push_back(i+365);
      bool matched = false;
      for(int j = i+1; j <= arrivals.size(); j++) {
	int a1 = arrivals[i];
	int b1 = departures[i];
	int a2 = arrivals[j];
	int b2 = departures[j];
	if(!(b1 < a2 || b2 < a1)) {
	  adjMat[i][j+365] = 1;
	  adjList[i].push_back(j+365);
	  adjList[j+365].push_back(i);
	  matched = true;
	}
      }
      if(!matched) {
	adjMat[i][i+365] = 1;
	adjList[i].push_back(i+365);
	adjList[i+365].push_back(i);
      }
    }
    int max_flow = 0;
    s = 0;
    t = 731;
    while(true) {
      f = 0;
      queue<int> q;
      map<int, int> dist;
      q.push(s);
      dist[s] = 0;
      while(!q.empty()) {
	int u = q.front();
	q.pop();
	if(u == t)
	  break;
	vector<int> adj = adjList[u];
	for(int j = 0; j < adj.size(); j++) {
	  int v = adj[j];
	  if(adjMat[u][v] > 0 && !dist.count(v)) {
	    dist[v] = dist[u] + 1;
	    q.push(v);
	    p[v] = u;
	  }
	}
      }
      augmentPath(t, INF);
      if(f == 0)
	break;
      max_flow += f;
    }
    return max_flow;
  }
};

// @begin_tests
void _run_test(vector< int > arrivals, vector< int > departures, int res_expected, int test_no) {
int tc_res = (new JanuszTheBusinessman)->makeGuestsReturn(arrivals, departures);
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
vector< int > arrivals;
vector< int > departures;
int res_expected;
{int tmpa[] = {2, 10, 6};
arrivals.assign(tmpa, tmpa + 3);}
{int tmpa[] = {6, 11, 9};
departures.assign(tmpa, tmpa + 3);}
res_expected = 2;
_run_test(arrivals, departures, res_expected, 0);
{int tmpa[] = {2, 10, 23, 34, 45, 123, 1};
arrivals.assign(tmpa, tmpa + 7);}
{int tmpa[] = {25, 12, 40, 50, 48, 187, 365};
departures.assign(tmpa, tmpa + 7);}
res_expected = 1;
_run_test(arrivals, departures, res_expected, 1);
{int tmpa[] = {8, 12, 20, 30, 54, 54, 68, 75};
arrivals.assign(tmpa, tmpa + 8);}
{int tmpa[] = {13, 31, 30, 53, 55, 70, 80, 76};
departures.assign(tmpa, tmpa + 8);}
res_expected = 3;
_run_test(arrivals, departures, res_expected, 2);
{int tmpa[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148};
arrivals.assign(tmpa, tmpa + 10);}
{int tmpa[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223};
departures.assign(tmpa, tmpa + 10);}
res_expected = 2;
_run_test(arrivals, departures, res_expected, 3);
{int tmpa[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6};
arrivals.assign(tmpa, tmpa + 20);}
{int tmpa[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13};
departures.assign(tmpa, tmpa + 20);}
res_expected = 14;
_run_test(arrivals, departures, res_expected, 4);
}
// @end_tests

// Born in Emacs
