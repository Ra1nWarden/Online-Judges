#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <vector>
#include <utility>
#include <cstring>
#define INF 2e9

using namespace std;

// stored in adjacency list
// elevator number, index, dist
typedef pair<int, pair<int, int> > edge;
// mindist, index, elevator number
// elevator number = -1 at the beginning
typedef pair<int, pair<int, int> > pqnode;

map<int, vector<edge> > graph;

int dist[100][6];

void insert(int elevator, int from, int to, int weight) {
  if(graph.count(from) == 0) {
    vector<edge> singleton;
    singleton.push_back(make_pair(elevator, make_pair(to, weight)));
    graph[from] = singleton;
  } else {
    graph[from].push_back(make_pair(elevator, make_pair(to, weight)));
  }
}

int main() {
  int n, dest;
  while(cin >> n >> dest) {
    int t[n];
    for(int i= 0; i < n; i++) {
      int time;
      cin >> time;
      t[i] = time;
    }
    cin >> ws;
    string line;
    graph.clear();
    for(int i= 0; i < n; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      vector<int> reachable;
      int floor;
      while(iss >> floor)
	reachable.push_back(floor);
      for(int j =0; j< reachable.size(); j++) {
	if(j + 1 != reachable.size()) {
	  int reach = reachable[j+1];
	  int weight = t[i] * (reach - reachable[j]);
	  insert(i, reachable[j], reachable[j+1], weight);
	} 
	if(j - 1 >= 0) {
	  int reach = reachable[j-1];
	  int weight = (reachable[j] - reachable[j-1]) * t[i];
	  insert(i, reachable[j], reachable[j-1], weight);
	}
      }
    }
    for(int i= 0; i < 100; i++)
      for(int j= 0; j < 6; j++)
	dist[i][j] = INF;
    for(int j= 0; j < 6; j++)
      dist[0][j] = 0;
    priority_queue<pqnode, vector<pqnode>, greater<pqnode> > pq;
    pq.push(make_pair(0, make_pair(0, -1)));
    while(!pq.empty()) {
      pqnode next = pq.top();
      pq.pop();
      if(next.first == dist[next.second.first][next.second.second]) {
	vector<edge> adjList = graph[next.second.first];
	for(int j= 0; j < adjList.size(); j++) {
	  edge eachCon = adjList[j];
	  int weight = eachCon.second.second;
	  if(next.second.second != -1) {
	    weight +=  (eachCon.first == next.second.second ? 0 : 60);
	  }
	  int index = eachCon.second.first;
	  if(dist[next.second.first][next.second.second] + weight < dist[index][eachCon.first]) {
	    dist[index][eachCon.first] = dist[next.second.first][next.second.second] + weight;
	    pq.push(make_pair(dist[index][eachCon.first], make_pair(index, eachCon.first)));
	  }
	}
      }
    }

    int result = INF;
    for(int i=  0; i < 6; i++) 
      result = min(result, dist[dest][i]);
    if(result == INF) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << result << endl;
    }
  }
  return 0;
}
