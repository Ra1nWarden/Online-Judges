#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <sstream>
#include <map>
#define INF 2e9

using namespace std;

int dist[501];
int n;
bool stations[501];
int beforeMinDist[501];

// dist and vertex
typedef pair<int, int> pqnode;
// next node and dist
typedef pair<int, int> edge;

map<int, vector<edge> > graph;

void dijkstra(int u) {
  dist[u] = 0;
  priority_queue<pqnode, vector<pqnode>, greater<pqnode> > pq;
  pq.push(make_pair(0, u));
  while(!pq.empty()) {
    pqnode next = pq.top();
    pq.pop();
    if(next.first == dist[next.second]) {
      vector<edge> adj = graph[next.second];
      for(int i = 0; i < adj.size(); i++) {
	edge neighbor = adj[i];
	int weight = neighbor.second;
	int nodeindex = neighbor.first;
	if(dist[next.second] + weight < dist[nodeindex]) {
	  dist[nodeindex] = dist[next.second] + weight;
	  pq.push(make_pair(dist[nodeindex], nodeindex));
	}
      }
    }
  }
}

int main() {
  int tc;
  cin >> tc;
  bool start = true;
  while(tc--) {
    if(!start)
      cout << endl;
    int exists;
    cin >> exists >> n;
    memset(stations, false, sizeof stations);
    for(int i= 0; i < exists; i++) {
      int station;
      cin >> station;
      stations[station] = true;
    }
    string line;
    getline(cin, line);
    graph.clear();
    while(getline(cin, line)) {
      if(line.empty())
	break;
      istringstream iss(line.c_str());
      int x, y, l;
      iss >> x >> y >> l;
      if(graph.count(x) == 0) {
	vector<edge> singleton;
	singleton.push_back(make_pair(y, l));
	graph[x] = singleton;
      }
      else {
	graph[x].push_back(make_pair(y, l));
      }
      if(graph.count(y) == 0) {
	vector<edge> singleton;
	singleton.push_back(make_pair(x, l));
	graph[y] = singleton;
      }
      else {
	graph[y].push_back(make_pair(x, l));
      }
    }

    for(int i= 1; i <= n; i++)
      beforeMinDist[i] = INF;
    for(int i = 1; i <= n; i++) {
      if(stations[i]) {
	for(int j= 1; j <= n; j++)
	  dist[j] = INF;
	dijkstra(i);
	for(int j = 1; j <= n; j++) {
	  beforeMinDist[j] = min(beforeMinDist[j], dist[j]);
	}
      }
    }

    int minStation = -1;
    int minDist = INF;
    for(int i = 1; i <= n; i++) {
      if(!stations[i]) {
	for(int j= 1; j <= n; j++)
	  dist[j] = INF;
	dijkstra(i);
	int thismax = 0;
	for(int j = 1; j <= n; j++) {
	  thismax = max(thismax, min(beforeMinDist[j], dist[j]));
	}
	if(thismax < minDist) {
	  minDist = thismax;
	  minStation = i;
	}
      }
    }
    cout <<( minStation == -1 ? 1 : minStation) << endl;
    start = false;
  }
  return 0;
}
