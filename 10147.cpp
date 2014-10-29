#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cmath>
#define EPSILON 1e-8

using namespace std;

typedef pair<int, int> coord;
typedef pair<double, pair<int, int> > edge;

ostream& operator<<(ostream& oss, const edge& e) {
  oss << e.second.first << " to " << e.second.second << " takes " << e.first << endl;
  return oss;
}

double dist(coord a, coord b) {
  return sqrt(pow(a.first - b.first, 2) + pow(b.second - a.second, 2));
}

vector<int> initSet(int n) {
  vector<int> result(n);
  for(int i= 0; i < n;i++)
    result[i] = i;
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
  int tc;
  cin >> tc;
  for(int t= 0; t < tc; t++) {
    if(t != 0)
      cout << endl;
    int n;
    cin >> n;
    vector<coord> coords;
    for(int i= 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      coords.push_back(make_pair(x, y));
    }
    vector<int> arr = initSet(n);
    int built;
    cin >> built;
    for(int i= 0; i < built; i++) {
      int x, y;
      cin >> x >> y;
      unionSet(x-1, y-1, arr);
    }
    priority_queue<edge> edges;
    for(int i= 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
	//cout << "loop " << i << ", " << j << endl;
	edges.push(make_pair(-dist(coords[i], coords[j]), make_pair(i, j)));
      }
    }
    vector<pair<int, int> > added;
    while(!edges.empty()) {
      edge next = edges.top();
      edges.pop();
      //cout << next << endl;
      if(!sameSet(next.second.first, next.second.second, arr)) {
	//cout << "unioned" << endl;
	unionSet(next.second.first, next.second.second, arr);
	added.push_back(next.second);
      }
    }
    if(added.empty())
      cout << "No new highways needed" << endl;
    else {
      for(int i = 0; i < added.size(); i++)
	cout << added[i].first+1 << " " << added[i].second+1 << endl;
    }
  }
  return 0;
}
