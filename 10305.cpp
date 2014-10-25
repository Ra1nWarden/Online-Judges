#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;
bool edge[101][101];
bool visited[101];
int inDegree[101];
vector<int> sorted;

void toposort(int u) {
  visited[u] = true;
  for(int i= 1; i <= n; i++) {
    if(edge[u][i] && !visited[i]) {
      toposort(i);
    }
  }
  sorted.push_back(u);
}

int main() {
  int c;
  while(cin >> n >> c && (n || c)) {
    memset(edge, false, sizeof edge);
    memset(inDegree, 0, sizeof inDegree);
    for(int i = 0; i < c; i++) {
      int x, y;
      cin >> x >> y;
      inDegree[y]++;
      edge[x][y] = true;
    }
    memset(visited, false, sizeof visited);
    sorted.clear();
    for(int i= 1; i <= n ; i++) {
      if(inDegree[i] == 0 && !visited[i]) {
	toposort(i);
      }
    }
    for(int i= sorted.size() -1; i >= 0; i--) {
      if(i == sorted.size() -1) {
	cout << sorted[i];
      }
      else {
	cout << " " << sorted[i];
      }
    }
    cout << endl;
    
  }
  return 0;
}
