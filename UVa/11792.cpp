#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

map<int, set<int> > nodes;
set<int> impstations;
map<pair<int, int>, int> shortest;
int n;

int bfs(int start, int end) {
  int smaller = min(start, end);
  int larger = max(start, end);
  if(shortest.count(make_pair(smaller, larger)) != 0)
     return shortest[make_pair(smaller, larger)];
  vector<bool> visited(n+1, false);
  visited[smaller] = true;
  queue<pair<int, int> > q;
  q.push(make_pair(smaller, 0));
  int result = -1;
  while(!q.empty()) {
    pair<int, int> next = q.front();
    q.pop();
    set<int> adjList = nodes[next.first];
    for(set<int>::iterator itr = adjList.begin(); itr != adjList.end(); itr++) {
      // cout << next.first << " is adjacent to " << *itr << endl;
      if(!visited[*itr]) {
	visited[*itr] = true;
	if(*itr == larger) {
	  result = next.second + 1;
	  break;
	} else {
	  q.push(make_pair(*itr, next.second+1));
	}
      }
    }
    if(result != -1)
      break;
  }
  // cout << "bfs result for " << start << " and " << end << " is " << result << endl;
  return shortest[make_pair(smaller, larger)] = result;
}

int main() {
  int tc;
  string line;
  cin >> tc;
  while(tc--) {
    int lines;
    cin >> n >> lines >> ws;
    nodes.clear();
    impstations.clear();
    shortest.clear();
    for(int i= 0; i < lines; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      vector<int> stations;
      int onestop;
      while(iss >> onestop && onestop)
	stations.push_back(onestop);
      for(int j= 0; j < stations.size(); j++) {
	if(nodes.count(stations[j]) == 0) {
	  set<int> adj;
	  if(j - 1 >= 0)
	    adj.insert(stations[j-1]);
	  if(j+1 < stations.size())
	    adj.insert(stations[j+1]);
	  nodes[stations[j]] = adj;
	}
	else {
	  impstations.insert(stations[j]);
	  if(j - 1 >= 0)
	    nodes[stations[j]].insert(stations[j-1]);
	  if(j + 1 < stations.size())
	    nodes[stations[j]].insert(stations[j+1]);
	}
      }
    }
    vector<int> v(impstations.begin(), impstations.end());

    int minLength = -1;
    int minStation = 10001;
    for(int i= 0; i < v.size(); i++) {
      int dist = 0;
      for(int j= 0; j < v.size(); j++) {
	if(i != j) {
	  dist += bfs(v[i], v[j]);
	}
      }
      //cout << "importatant station " << v[i] << " has dist " << dist << endl;
      if(minStation == 10001 || dist < minLength) {
	minLength = dist;
	minStation = v[i];
	//cout << "minLength is " << minLength << " minStations is " << minStation << endl;
      } else if(dist == minLength) {
	minStation = min(minStation, v[i]);
      }
    }
    cout << "Krochanska is in: " << minStation << endl;
  }
  return 0;
}
