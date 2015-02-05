#include <iostream>
#include <map>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

bool DEBUG = false;

int n;
int v[101][101];
int dfsnum[101];
int dfslow[101];
int parent[101];
bool ap[101];
int root, dfsIterationIndex = 0, childrenCount;

void findArticulationPoint(int u) {
  dfsnum[u] = dfslow[u] = dfsIterationIndex++;
  for(int i= 0; i < n; i++) {
    if(v[u][i]) {
      if(dfsnum[i] == -1) {
	// not visited
	if(u == root)
	  childrenCount++;
	parent[i] = u;
	if(DEBUG)
	  cout << "calling from " << u << " to " << i << endl;
	findArticulationPoint(i);
	if(dfslow[i] >= dfsnum[u]) {
	  if(DEBUG) {
	    cout << "dfslow for " << i << " is " << dfslow[i] << endl;
	    cout << "dfsnum for " << u << " is " << dfsnum[u] << endl;
	  }
	  ap[u] = true;
	}
	dfslow[u] = min(dfslow[u], dfslow[i]);
      }
      else if(i != parent[u]) {
	// visited and not a back edge
	dfslow[u] = min(dfslow[u], dfsnum[i]);
      }
    }
  }
}

int main() {
  int caseNo = 1;
  while(cin >> n && n) {
    if(caseNo > 1)
      cout << endl;
    string line;
    getline(cin, line);
    map<int, string> nameMap;
    map<string, int> indexMap;
    for(int i= 0; i < n ;i++) {
      getline(cin, line);
      nameMap[i] = line;
      indexMap[line] = i;
    }
    memset(v, 0, sizeof v);
    int edges;
    cin >> edges;
    getline(cin, line);
    for(int i= 0; i < edges; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      string start, end;
      getline(iss, start, ' ');
      getline(iss, end, ' ');
      int startIndex = indexMap[start];
      int endIndex = indexMap[end];
      v[startIndex][endIndex] = 1;
      v[endIndex][startIndex] = 1;
    }
    
    memset(dfsnum, -1, sizeof dfsnum);
    memset(dfslow, -1, sizeof dfslow);
    memset(parent, -1, sizeof parent);
    memset(ap, false, sizeof ap);
    dfsIterationIndex = 0;
    for(int i= 0; i < n; i++) {
      if(dfsnum[i] == -1) {
	root = i;
	childrenCount =0;
	findArticulationPoint(i);
	ap[i] = (childrenCount > 1);
      }
    }
    
    if(DEBUG) {
      cout << "adjacency matrix" << endl;
      for(int i= 0; i < n; i++) {
	for(int j= 0; j < n; j++) {
	  cout << v[i][j];
	}
	cout << endl;
      }
      cout << endl;
      cout << "dfsnum" << endl;
      for(int i = 0; i < n; i++)
	cout << dfsnum[i];
      cout << endl;
      cout << "dfslow" << endl;
      for(int i = 0; i < n; i++)
	cout << dfslow[i];
      cout << endl;
    }
    
    vector<string> camera;
    for(int i = 0; i < n; i++) {
      if(ap[i]) {
	camera.push_back(nameMap[i]);
      }
    }
    sort(camera.begin(), camera.end());

    printf("City map #%d: %d camera(s) found\n", caseNo++, (int) camera.size());
    for(int i = 0; i < camera.size(); i++)
      cout << camera[i] << endl;
  }
  return 0;
}
