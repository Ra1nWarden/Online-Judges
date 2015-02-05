#include <iostream>
#include <utility>
#include <cstring>
#include <map>

#define IMPOSSIBLE -2

using namespace std;

bool DEBUG = false;

int costs[51][51];
int times[51][51];
// time used
// node with time left
int costmemo[51][1001];
int n, t;

pair<int, int> travel(int node, int time, int cost, map<int, bool> visited) {
  if(DEBUG)
    cout << "calling node " << node << " with time left " << time << " and cost " << cost << endl; 
  if(costmemo[node][time] != -1) {
    // (cost, time)
    pair<int, int> result(costmemo[node][time], time);
    return result;
  }
  if(node == n - 1) {
    costmemo[node][time] = cost;
    pair<int, int> result(cost, time);
    return result;
  } else {
    int minCost = IMPOSSIBLE;
    int minTime = IMPOSSIBLE;
    for(int i = 0; i < n; i++) {
      if(!visited[i] && time >= times[node][i]) {
	map<int, bool> visited_copy = visited;
	visited_copy[i] = true;
	pair<int, int> bestNext = travel(i, time - times[node][i], cost + costs[node][i], visited_copy);
	if(minCost == IMPOSSIBLE || bestNext.first < minCost) {
	  minCost = bestNext.first;
	  minTime = bestNext.second;
	}
      }
    }
    costmemo[node][time] = minCost;
    pair<int, int> result(minCost, minTime);
    return result;
  }
}

int main() {
  int t;
  while(cin >> n >> t && (n || t)) {
    memset(times, -1, sizeof times);
    memset(costs, -1, sizeof costs);
    memset(costmemo, -1, sizeof costmemo);
    map<int, bool> visited;
    for(int i= 0; i < n; i++) {
      for(int j= 0; j < n; j++) {
	int time;
	cin >> time;
	times[i][j] = time;
      }
    }	
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	int cost;
	cin >> cost;
	costs[i][j] = cost;
      }
      visited[i] = false;
    }
    visited[0] = true;
    pair<int, int> result = travel(0, t, 0, visited);
    cout << result.first << " " << t - result.second << endl;
  }
  return 0;
}
