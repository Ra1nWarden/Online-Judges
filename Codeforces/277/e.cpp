#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int v[100000];
int lis[100000];
int result[100000];
int dfsCounter, dfsRoot, rootChildren;
int dfsNum[100000];
int dfsLow[100000];
int dfsParent[100000];
map<int, vector<int> > nextMap;

void articulationPoint(int u) {
  dfsLow[u] = dfsNum[u] = dfsCounter++;
  if(result[u] == 0)
    result[u] = 1;
  vector<int> adj = nextMap[u];
  for(int i = 0; i < adj.size(); i++) {
    int v = adj[i];
    cout << u << " has child " << v << endl; 
    if(dfsNum[v] == 0) {
      dfsParent[v] = u;
      if(u == dfsRoot)
	rootChildren++;
      articulationPoint(v);
      if(dfsLow[v] >= dfsNum[u])
	result[u] = 2;
      dfsLow[u] = min(dfsLow[u], dfsLow[v]);
    }
    else if (v != dfsParent[u])
      dfsLow[u] = min(dfsLow[u], dfsNum[v]);
  }
}

int main() {
  int n;
  cin >> n;
  memset(lis, 1, sizeof (int) * n);
  for(int i= 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = x;
  }
  int maxLength = 1;
  nextMap.clear();
  for(int i= 0; i < n; i++) {
    int num = v[i];
    for(int j = 0; j < i; j++) {
      if(v[j] < num) {
	if(1 + lis[j] > lis[i]) {
	  lis[i] = 1 + lis[j];
	  vector<int> child;
	  child.push_back(j);
	  nextMap[i] = child;
	}
	else if(1 + lis[j] == lis[i]) {
	  nextMap[i].push_back(j);
	}
	maxLength = max(maxLength, lis[i]);
      }
    }
  }
  memset(result, 0, sizeof result);
  
  vector<int> maxStart;
  for(int i= 0; i < n; i++) {
    if(lis[i] == maxLength) {
      //cout << v[i] << endl;
      maxStart.push_back(i);
    }
  }
  
  dfsCounter = 0;
  memset(dfsNum, 0, sizeof dfsNum);
  memset(dfsLow, 0, sizeof dfsLow);
  for(int i= 0; i < maxStart.size(); i++) {
    dfsRoot = maxStart[i];
    rootChildren = 0;
    articulationPoint(maxStart[i]);
    result[dfsRoot] = (rootChildren > 1 ? 2 : 1);
  }
  
  for(int i= 0; i < n; i++) {
    cout << result[i]+1;
  }
  cout << endl;
  
  
  return 0;
}
