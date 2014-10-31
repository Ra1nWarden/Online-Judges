#include <iostream>
#include <vector>
#include <map>
#define INF 2e9

using namespace std;

// target index, weight
typedef pair<int, int> edge;

map<int, vector<edge> > graph;

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int n, m;
    cin >> n >> m;
    graph.clear();
    for(int i= 0; i < m; i++) {
      int start, end, weight;
      cin >> start >> end >> weight;
      if(graph.count(start) == 0) {
	vector<edge> e;
	e.push_back(make_pair(end, weight));
	graph[start] = e;
      } else {
	graph[start].push_back(make_pair(end, weight));
      }
    }
    vector<int> dist(n, INF);
    dist[0] = 0;
    for(int i= 0; i < n-1; i++) {
      for(int j= 0; j < n; j++) {
	vector<edge> edges = graph[j];
	for(int k = 0; k < edges.size(); k++) {
	  int nextNode = edges[k].first;
	  int weight = edges[k].second;
	  dist[nextNode] = min(dist[nextNode], weight + dist[j]);
	}
      }
    }

    bool neg_cycle = false;
    for(int i= 0; i < n; i++) {
      vector<edge> edges = graph[i];
      for(int j = 0; j < edges.size(); j++) {
	int nextNode = edges[j].first;
	int weight = edges[j].second;
	if(dist[nextNode] > weight + dist[i]) {
	  neg_cycle = true;
	  break;
	}
      }
      if(neg_cycle)
	break;
    }
    cout << (neg_cycle ? "possible" : "not possible") << endl;
    
  }
  return 0;
}
