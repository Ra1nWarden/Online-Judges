#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int> > edge;

vector<int> initSet(int n) {
  vector<int> result(n);
  for(int i= 0; i < n; i++)
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
  int n, l;
  while(cin >> n >> l && (n || l)) {
    priority_queue<edge> edges;
    long long origsum = 0;
    for(int i= 0; i < l; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      origsum += z;
      edge newedge = make_pair(-z, make_pair(x, y));
      edges.push(newedge);
    }
    vector<int> arr = initSet(n);
    long long min_cost = 0;
    while(!edges.empty()) {
      edge next = edges.top();
      edges.pop();
      if(!sameSet(next.second.first, next.second.second, arr)) {
	min_cost += next.first;
	unionSet(next.second.first, next.second.second, arr);
      }
    }
    //cout << "origsum is " << origsum << endl;
    //cout << "min_sum is "<< min_cost << endl;
    cout << origsum + min_cost << endl;
  }
  return 0;
}
