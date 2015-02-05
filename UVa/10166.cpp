#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <vector>

using namespace std;

// time, station name
typedef pair<string, string> stop;
// latest leave time, earliest arrive time
typedef pair<string, string> dist;

struct Edge {
  Edge(string s, string e, string d) : start(s), end(e), dest(d) {};
  string start;
  string end;
  string dest;
};

stack<string> toposorted;
set<string> dfsVisited;
map<string, vector<Edge> > graph;

void toposort(string station) {
  dfsVisited.insert(station);
  vector<Edge> edges = graph[station];
  for(int i= 0; i < edges.size(); i++) {
    Edge next = edges[i];
    if(dfsVisited.count(next.dest) == 0)
      toposort(next.dest);
  }
  toposorted.push(station);
}

int main() {
  int stops;
  while(cin >> stops && stops) {
    graph.clear();
    string line;
    getline(cin, line);
    for(int i = 0; i < stops; i++) {
      getline(cin, line);
    }
    int trains;
    cin >> trains;
    for(int i= 0; i < trains; i++) {
      int stops;
      cin >> stops;
      vector<stop> vstop;
      for(int j= 0; j < stops; j++) {
	string time, station;
	cin >> time >> station;
	vstop.push_back(make_pair(time, station));
      }

      for(int j= 0; j < stops - 1; j++) {
	stop start = vstop[j];
	stop end = vstop[j+1];
	Edge e(start.first, end.first, end.second);
	if(graph.count(start.second) != 0)
	  graph[start.second].push_back(e);
	else {
	  vector<Edge> singleton;
	  singleton.push_back(e);
	  graph[start.second] = singleton;
	}
      }
    }

    string startTime, startStation, endStation;
    cin >> startTime >> startStation >> endStation;
    dfsVisited.clear();
    toposort(startStation);

    map<string, dist> result;
    result[startStation] = make_pair("", startTime);

    while(!toposorted.empty()) {
      string next = toposorted.top();
      toposorted.pop();
      if(result.count(next) == 0)
	continue;
      string nextArriveTime = result[next].second;
      //cout << "arrival time for " << next << " is " << nextArriveTime << endl;
      vector<Edge> adj = graph[next];
      for(int i= 0; i < adj.size(); i++) {
	Edge nextEdge = adj[i];
	if(nextEdge.start >= nextArriveTime) {
	  //cout << "next node is " << next << endl;
	  string nextDest = nextEdge.dest;
	  if(result.count(nextDest) == 0) {
	    result[nextDest] = make_pair(nextEdge.start, nextEdge.end);
	  } else {
	    string oldLeave = result[nextDest].first;
	    string oldArrive = result[nextDest].second;
	    if(nextEdge.end < oldArrive) {
	      result[nextDest] = make_pair(nextEdge.start, nextEdge.end);
	    } else if (nextEdge.end == oldArrive && nextEdge.start > oldLeave) {
	      result[nextDest] = make_pair(nextEdge.start, nextEdge.end);
	    }
	  }
	}
      }
    }

    if(result.count(endStation) == 0) {
      cout << "No connection" << endl;
    } else {
      string latestStart = startTime;
      vector<Edge> adj = graph[startStation];
      for(int i= 0; i < adj.size(); i++) {
	Edge nextEdge = adj[i];
	string nextDest = nextEdge.dest;
	//cout << nextDest << ": " << result[nextDest].first << " vs " << latestStart << endl;
	if(result[nextDest].first >= latestStart) {
	  latestStart = max(latestStart, nextEdge.start);
	}
      }
      
      cout << latestStart << " " << result[endStation].second << endl;
    }
  }
  return 0;
}
