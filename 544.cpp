#include <iostream>
#include <map>
#include <cstdio>
#define INF 2e8

using namespace std;

int main() {
  int n, r;
  int tc = 1;
  while(cin >> n >> r && (n || r)) {
    int adj[n][n];
    map<string, int> indexCount;
    int index = 0;
    for(int i= 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	adj[i][j] = -1;
      }
    }
    for(int i = 0; i < r; i++) {
      string a, b;
      int weight;
      cin >> a >> b >> weight;
      if(indexCount.count(a) == 0)
	indexCount[a] = index++;
      if(indexCount.count(b) == 0)
	indexCount[b] = index++;
      int indexa = indexCount[a];
      int indexb = indexCount[b];
      adj[indexa][indexb] = adj[indexb][indexa] = weight;
    }
    
    for(int k= 0;  k < n; k++) {
      for(int i = 0; i < n; i++) {
	for(int j= 0; j < n; j++) {
	  adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
	}
      }
    }

    string start, end;
    cin >> start >> end;
    printf("Scenario #%d\n", tc++);
    printf("%d tons\n\n", adj[indexCount[start]][indexCount[end]]);
  }
  return 0;
}
