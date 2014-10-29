#include <iostream>
#include <cstring>
#include <sstream>
#include <stack>

using namespace std;

bool DEBUG = true;

int v[100][100];
int n;
int dfsNumberCount = 0;
int dfsnum[100];
int dfslow[100];
int dfsparent[100];
bool articulation_vertex[100];
int dfsRoot, rootChildren;

void articulationPoint(int u) {
  dfsnum[u] = dfslow[u] = dfsNumberCount++;
  for(int i = 0; i < n; i++) {
    if(v[u][i]) {
      if(dfsnum[i] == -1) {
	// not visited
	if(u == dfsRoot) {
	  rootChildren++;
	}
	dfsparent[i] = u;
	if(DEBUG)
	  cout << "calling from " << u << " to " << i << endl;
	articulationPoint(i);
	if(dfslow[i] >= dfsnum[u]) {
	  articulation_vertex[u] = true;
	  cout << "dfslow for " << i << " is " << dfslow[i] << endl;
	  cout << "dfsnum for " << u << " is " << dfsnum[u] << endl;
	}
	dfslow[u] = min(dfslow[u], dfslow[i]);
      } 
      else if(i != dfsparent[u])
	dfslow[u] = min(dfslow[u], dfsnum[i]);
    }
  }
}

int main() {
  while(cin >> n && n) {
    memset(v, 0, sizeof v);
    string line;
    getline(cin, line);
    while(true) {
      getline(cin, line);
      istringstream iss(line.c_str());
      int start;
      iss >> start;
      if(start == 0)
	break;
      int end;
      while(iss >> end) {
	v[start-1][end-1] = 1;
	v[end-1][start-1] = 1;
      }
    }
    if(DEBUG) {
      for(int i = 0;i < n; i++) {
	for(int j= 0; j < n; j++) {
	  cout << v[i][j];
	}
	cout << endl;
      }
      cout << endl;
    }
    
    memset(articulation_vertex, false, sizeof articulation_vertex);
    memset(dfsnum, -1, sizeof dfsnum);
    memset(dfslow, -1, sizeof dfslow);
    memset(dfsparent, -1, sizeof dfsparent);
    for(int i= 0;i < n; i++) {
      if(dfsnum[i] == -1) {
	dfsRoot = i;
	rootChildren = 0;
	articulationPoint(i);
	articulation_vertex[i] = (rootChildren > 1);
      }
    }
    
    if(DEBUG) {
      cout << "dfsnum " << endl;
      for(int i= 0; i < n; i++) {
	cout << dfsnum[i];
      }
      cout << endl;
      cout << "dfslow " << endl;
      for(int i= 0;i < n; i++) {
	cout << dfslow[i];
      }
      cout << endl;
      cout << "children count: " << rootChildren << endl;
    }

    int result = 0;
    for(int i = 0; i < n; i++) {
      if(articulation_vertex[i])
	result++;
    }
    cout << result << endl;

  }
  return 0;
}
