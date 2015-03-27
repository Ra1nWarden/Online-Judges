#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

long long choose2(long long n) {
  return n * (n-1) / 2;
}

int main() {
  int n, m;
  cin >> n >> m;
  map<int, vector<int> > adjList;
  long long result = 0;
  for(int i= 0 ;i < m; i++) {
    int x, y;
    cin >> x >> y;
    if(adjList.count(x) == 0) {
      vector<int> singleton;
      singleton.push_back(y);
      adjList[x] = singleton;
    } else {
      adjList[x].push_back(y);
    }
  }

  for(int i = 1; i <= n; i++) {
    int visited[n+1];
    memset(visited, 0, sizeof visited);
    queue<int> q;
    vector<int> iAdj = adjList[i];
    for(int j = 0; j < iAdj.size(); j++) {
	q.push(iAdj[j]);
    }
    //cout << "i is " << i << endl;
    while(!q.empty()) {
      int next = q.front();
      q.pop();
      vector<int> nextAdj = adjList[next];
      for(int j= 0; j < nextAdj.size(); j++) {
	int v = nextAdj[j];
	if(v == i)
	  continue;
	//cout << i << " and " << v << endl;
	visited[v]++;
      }
    }
    for(int j = 1; j <= n; j++) {
      result += choose2(visited[j]);
    }
  }
  

  cout << result << endl;
  return 0;
}
