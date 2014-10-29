#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#define INF 2e9

using namespace std;

// target, weight
typedef pair<int, int> edge;
// index -> energy, adjacent
map<int, pair<int, vector<int> > > graph;

int dist[101];

int main() {
  int n;
  while(cin >> n && n != -1) {
    graph.clear();
    for(int i = 1; i <= n; i++) {
      int energy;
      cin >> energy;
      int degree;
      cin >> degree;
      vector<int> adjNodes;
      for(int j= 0; j < degree; j++) {
	int x;
	cin >> x;
	adjNodes.push_back(x);
      }
      graph[i] = make_pair(-energy, adjNodes);
    }
    for(int j= 0; j < 101; j++)
      dist[j] = INF;
    dist[1] = 0;
    for(int j = 1; j <= n-1; j++) {
      for(int k = 1; k <= n; k++) {
	pair<int, vector<int> > adj = graph[k];
	for(int l = 0; l < adj.second.size(); l++) {
	  int nextNode = adj.second[l];
	  //cout << "next is " << nextNode << endl;
	  int weight = graph[nextNode].first;
	  //cout << "next weight is " << weight << endl;
	  if(min(dist[nextNode], dist[k] + weight) < 100)
	    dist[nextNode] = min(dist[nextNode], dist[k] + weight);
	  //cout << "dsit[nextNode] is " << dist[nextNode] << endl;
	}
      }
    }
    bool negative_cycle = false;
    int cycle_index = -1;
    for(int j= 1; j <= n; j++) {
      pair<int, vector<int> > adj = graph[j];
      for(int k = 0; k < adj.second.size(); k++) {
	int nextNode = adj.second[k];
	int weight = graph[nextNode].first;
	if(dist[j] + weight < dist[nextNode]) {
	  negative_cycle = true;
	  cycle_index = j;
	}
      }
    }


    bool winnable = true;
    //cout << "n is  " << n << endl;
    for(int i= 1; i <=n; i++) {
      cout << dist[i] << " "; 
      if(dist[i] >= 100) {
	winnable = false;
	break;
      }
    }
    // cout << endl;
    if(!winnable) {
      cout << "hopeless" << endl; 
      continue;
    }
 
    if(negative_cycle) {
      //cout << "cycle_index is " << cycle_index << endl;
      stack<int> s;
      s.push(cycle_index);
      set<int> visited;
      visited.insert(cycle_index);
      while(!s.empty()) {
	int next = s.top();
	s.pop();
	pair<int, vector<int> > adj = graph[next];
	for(int j= 0; j < adj.second.size(); j++) {
	  int nextnode = adj.second[j];
	  //cout << "from " << next << " next node is " << nextnode << endl;
	  if(visited.count(nextnode) == 0) {
	    s.push(nextnode);
	    visited.insert(nextnode);
	  }
	}
      }
      if(visited.count(1) > 0 && visited.count(n) > 0) {
	cout << "winnable" << endl;
	continue;
      }
    }


    //cout << endl;
    cout << (!winnable ? "hopeless" : "winnable") << endl;
  }
  return 0;
}
