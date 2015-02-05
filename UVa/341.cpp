#include <iostream>
#include <cstring>
#include <vector>
#define INF 2e8
using namespace std;

int n;
int dist[11][11];
int nextNode[11][11];

vector<int> getPath(int i, int j) {
  //cout << "get path " << i << " to " << j << endl;
  vector<int> result;
  if(i == j){
    result.push_back(i);
    return result;
  }
  else if(nextNode[i][j] == -1)
    return result;
  else {
    vector<int> subresult = getPath(i, nextNode[i][j]);
    subresult.push_back(j);
    return subresult;
  }
    
}

int main() {
  int tc = 1;
  while(cin >> n && n) {
    // cout << n << endl;
    for(int i= 1;i <= n; i++)
      for(int j= 1; j <=n; j++) {
	dist[i][j] = INF;
      }
    memset(nextNode, -1, sizeof nextNode);
    for(int i= 1; i <= n; i++) {
      int intersects;
      cin >> intersects;
      for(int j=0; j < intersects; j++) {
	int lead, delay;
	cin >> lead >> delay;
	dist[i][lead] = delay;
	nextNode[i][lead] = i;
      }
    }

    for(int k = 1; k <= n; k++) {
      for(int i= 1; i <= n; i++) {
	for(int j= 1; j <= n; j++) {
	  if(dist[i][k] + dist[k][j] < dist[i][j]) {
	    dist[i][j] = dist[i][k] + dist[k][j];
	    nextNode[i][j] = nextNode[k][j];
	  }
	}
      }
    }
    
    int start, end;
    cin >> start >> end;
    vector<int> path = getPath(start, end);
    cout << "Case " << tc++ << ": Path =";
    for(int i = 0; i < path.size(); i++)
      cout << " " << path[i];
    cout << "; " << dist[start][end] << " second delay" << endl;
  }
  return 0;
}
