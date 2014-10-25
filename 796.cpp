#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>

using namespace std;

bool DEBUG = false;

int n;
int v[1001][1001];
int bridge[1001][1001];
int dfsnum[1001];
int dfslow[1001];
int parent[1001];
int dfsIterationCount;
int bridgeCount;

void findArticulationBridge(int u) {
  dfsnum[u] = dfslow[u] = dfsIterationCount++;
  for(int i = 0; i < n; i++) {
    if(v[u][i]) {
      if(dfsnum[i] == -1) {
	// not visited
	parent[i] = u;
	findArticulationBridge(i);
	if(dfslow[i] > dfsnum[u]) {
	  if(DEBUG)
	    cout << i << ", " << u << " is a bridge " << endl;  
	  bridgeCount++;
	  bridge[u][i] = 1;
	  bridge[i][u] = 1;
	}
	dfslow[u] = min(dfslow[u], dfslow[i]);
      }
      else if(i != parent[u]) {
	// visited and not back edge
	dfslow[u] = min(dfslow[u], dfsnum[i]);
      }
    }
  }
}

int main() {
  while(cin >> n) {
    string line;
    getline(cin, line);
    memset(v, 0, sizeof v);
    for(int i = 0; i < n; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      int start;
      iss >> start;
      string junk;
      iss >> ws;
      getline(iss, junk, ' ');
      int end;
      while(iss >> end) {
	v[start][end] = 1;
	v[end][start] = 1;
      }
    }
    if(DEBUG) {
      for(int i= 0;i < n; i++) {
	for(int j= 0; j < n;j++) {
	  cout << v[i][j];
	}
	cout << endl;
      }
      cout << endl;
    }

    memset(bridge, 0, sizeof bridge);
    memset(dfsnum, -1, sizeof dfsnum);
    memset(dfslow, -1, sizeof dfslow);
    bridgeCount = 0;
    for(int i= 0; i < n; i++) {
      if(dfsnum[i] == -1) {
	dfsIterationCount = 0;
	findArticulationBridge(i);
      }
    }

    printf("%d critical links\n", bridgeCount);
    for(int i= 0;i < n; i++) {
      for(int j= i+1; j < n;j++) {
	if(bridge[i][j])
	  printf("%d - %d\n", i, j);
      }
    }
    printf("\n");
    
  }
  return 0;
}
