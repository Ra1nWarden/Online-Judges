#include <iostream>
#include <queue>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int> > edge;

map<string, int> stations;

vector<int> initSet(int n) {
  vector<int> result(n);
  for(int i = 0; i < n; i++) {
    result[i] = i;
  }
  return result;
}

int findSet(int u, vector<int>& arr) {
  return arr[u] == u ? u : arr[u] = findSet(arr[u], arr);
}

bool sameSet(int x, int y, vector<int>& arr) {
  return findSet(x, arr) == findSet(y, arr);
}

void unionSet(int x, int y, vector<int>& arr) {
  arr[findSet(x, arr)] = findSet(y, arr);
}

int main() {
  int n, l;
  string line;
  while(cin >> n >> l && (n || l)) {
    getline(cin, line);
    stations.clear();
    for(int i= 0; i < n; i++) {
      getline(cin, line);
      stations[line] = i;
    }
    priority_queue<edge> edges;
    for(int i = 0; i < l; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      string start;
      string end;
      getline(iss, start, ' ');
      getline(iss, end, ' ');
      int weight;
      iss >> weight;
      edges.push(make_pair(-weight, make_pair(stations[start], stations[end])));
    }
    getline(cin, line);
    int min_cost = 0;
    vector<int> arr = initSet(n);
    while(!edges.empty()) {
      edge next = edges.top();
      edges.pop();
      if(!sameSet(next.second.first, next.second.second, arr)) {
	min_cost += next.first;
	unionSet(next.second.first, next.second.second, arr);
      }
    }
    int parent = findSet(0, arr);
    bool possible = true;
    for(int i= 1; i < n; i++) {
      if(findSet(i, arr) != parent) {
	possible = false;
	break;
      }
    }
    if(!possible)
      cout << "Impossible" << endl;
    else
      cout << -min_cost << endl;
  }
  return 0;
}
