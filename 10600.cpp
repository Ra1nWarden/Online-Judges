#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int> > edge;

vector<int> initSet(int n) {
  vector<int> result(n);
  for(int i= 0; i < n; i++)
    result[i] = i;
  return result;
}

int findSet(int x, vector<int>& arr) {
  return arr[x] == x ? x : arr[x] = findSet(arr[x], arr);
}

bool sameSet(int x, int y, vector<int>& arr) {
  //cout << "sameSet called with " << x << ",  " << y << endl;
  for(int i= 0; i < arr.size(); i++) {
    //cout << arr[i] << " ";
  }
  //cout << endl;
  return findSet(x, arr) == findSet(y, arr);
}

void unionSet(int x, int y, vector<int>& arr) {
  arr[findSet(x, arr)] = findSet(y, arr);
}

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int n, s;
    cin >> n >> s;
    vector<edge> edges;
    for(int i= 0; i < s; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      edges.push_back(make_pair(-z, make_pair(min(x, y), max(x, y))));
    }
    priority_queue<edge> q(edges.begin(), edges.end());
    vector<edge> best;
    vector<int> arr = initSet(n);
    int min_cost = 0;
    while(!q.empty()) {
      edge next = q.top();
      q.pop();
      if(!sameSet(next.second.first-1, next.second.second-1, arr)) {
	unionSet(next.second.first-1, next.second.second-1, arr);
	best.push_back(next);
	min_cost += next.first;
      }
    }
    min_cost = -min_cost;
    //cout << "min_cost is " << min_cost << endl;
    int second_best = -1;
    for(int i= 0; i < best.size(); i++) {
      edge remove = best[i];
      // cout << "removing  " << remove.second.first << " and " << remove.second.second << endl;
      vector<edge> newedges = edges;
      newedges.erase(find(newedges.begin(), newedges.end(), remove));
      vector<int> newarr = initSet(n);
      priority_queue<edge> newq(newedges.begin(), newedges.end());
      int new_min_cost = 0;
      while(!newq.empty()) {
	edge newnext = newq.top();
	newq.pop();
	//cout << "popped out set " << newnext.second.first << ", " << newnext.second.second << endl;
	if(!sameSet(newnext.second.first-1, newnext.second.second-1, newarr)) {
	  //cout << "inside if " << endl;
	  // cout << "joining " << newnext.second.first-1 << " and " << newnext.second.second-1 << endl;
	  unionSet(newnext.second.first-1, newnext.second.second-1, newarr);
	  new_min_cost += newnext.first;
	  //cout << "new_min_cost is  "<< new_min_cost << endl;
	}
      }
      bool disconnected = false;
      int check = findSet(0, newarr);
      for(int i= 1; i < newarr.size(); i++) {
	if(check != findSet(i, newarr)) {
	  disconnected = true;
	  break;
	}
      }
      if(disconnected) {
	continue;
      }
      new_min_cost = -new_min_cost;
      // cout << "new_min_cost is " << new_min_cost << endl;
      if(second_best == -1 || new_min_cost < second_best)
	second_best  = new_min_cost;
    }
    cout << min_cost << " " << second_best << endl;
  }
  return 0;
}
