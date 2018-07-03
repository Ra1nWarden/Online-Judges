#include <cstdio>
#include <unordered_map>
#include <string>
#include <functional>
#include <queue>
#include <set>

using namespace std;

const int maxn = 10000;
const int maxl = 10;
char str[maxl+5], str2[maxl+5];
unordered_map<string, int> dict;
typedef pair<int, int> Edge;
vector<Edge> adjMat[maxn+5];
int n;

int dijkstra(int s, int t) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  unordered_map<int, int> min_dist;
  pq.push(make_pair(0, s));
  min_dist[s] = 0;
  int ans;
  while(!pq.empty()) {
    pair<int, int> u = pq.top();
    pq.pop();
    for(int i = 0; i < adjMat[u.second].size(); i++) {
      Edge e = adjMat[u.second][i];
      if(!min_dist.count(e.first) || min_dist[e.first] > e.second + u.first) {
	pq.push(make_pair(e.second + u.first, e.first));
	min_dist[e.first] = e.second + u.first;
      }
    }
    if(u.second == t) {
      ans = u.first;
      break;
    }
  }
  return ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d\n", &n);
    dict.clear();
    for(int i = 1; i <= n; i++) {
      adjMat[i].clear();
    }
    for(int i = 1; i <= n; i++) {
      scanf("%s\n", str);
      string name(str);
      dict[name] = i;
      int m;
      scanf("%d", &m);
      for(int j = 0; j < m; j++) {
	int u, l;
	scanf("%d %d\n", &u, &l);
	adjMat[i].push_back(make_pair(u, l));
      }
    }
    int query;
    scanf("%d\n", &query);
    while(query--) {
      scanf("%s %s\n", str, str2);
      string source(str);
      string dest(str2);
      printf("%d\n", dijkstra(dict[source], dict[dest]));
    }
  }
  return 0;
}
