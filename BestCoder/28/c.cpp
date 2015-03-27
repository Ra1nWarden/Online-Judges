#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#define MAXN 100005

using namespace std;

map<int, vector<pair<int, int> > > adjList;
int n, m, k;
long long dp[MAXN];
int dpe[MAXN];

typedef pair<pair<int, int>, int> Node; // previous edge, index, totallength

int main() {
  int tc;
  scanf("%d", &tc);
  for(int tcase = 0; tcase < tc; tcase++) {
    scanf("%d %d %d", &n, &m, &k);
    adjList.clear();
    memset(dp, -1, sizeof dp);
    memset(dpe, -1, sizeof dpe);
    for(int i = 0; i < m; i++) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      adjList[x].push_back(make_pair(y, z));
    }
    stack<Node> s;
    for(int i = 0; i < adjList[1].size(); i++) {
      s.push(make_pair(make_pair(adjList[1][i].second, adjList[1][i].first), adjList[1][i].second));
      dpe[adjList[1][i].first] = dp[adjList[1][i].first] =  adjList[1][i].second;
    }
    while(!s.empty()) {
      Node next = s.top();
      s.pop();
      int nexti = next.first.second;
      int nexte = next.first.first;
      for(int i = 0; i < adjList[nexti].size(); i++) {
	int nextii = adjList[nexti][i].first;
	if(adjList[nexti][i].second - nexte < k)
	  continue;
	int nexttotal = next.second + adjList[nexti][i].second;
	if(!(nexttotal >= dp[nextii] && adjList[nexti][i].second >= dpe[nextii])) {
	  if(!(nextii == n && nexttotal > dp[n])) {
	    s.push(make_pair(make_pair(adjList[nexti][i].second, nextii), nexttotal));
	    dp[nextii] = nexttotal;
	    dpe[nextii] = adjList[nexti][i].second;
	  }
	}
      }
    }
    //printf("%I64d\n", dp[n]);
    printf("%lld\n", dp[n]);
  }
  return 0;
}
