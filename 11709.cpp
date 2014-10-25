#include <iostream>
#include <cstring>
#include <map>
#include <stack>
#include <set>

using namespace std;

int n;
int v[1001][1001];
int dfsnum[1001];
int dfslow[1001];
int dfsCounter;
int sccCount;
stack<int> scc;
set<int> in_stack;

bool DEBUG = false;

void tarjan(int u) {
  scc.push(u);
  in_stack.insert(u);
  dfsnum[u] = dfslow[u] = dfsCounter++;
  for(int i= 0; i < n;i++) {
    if(v[u][i]) {
      if(dfsnum[i] == -1) {
	tarjan(i);
	dfslow[u] = min(dfslow[u], dfslow[i]);
      }
      else if(in_stack.count(i) != 0)
	dfslow[u] = min(dfslow[u], dfsnum[i]);
    }
  }
  if(dfslow[u] == dfsnum[u]) {
    if(DEBUG)
      cout << u << " ";
    while(!scc.empty() && scc.top() != u) {
      int next = scc.top();
      if(DEBUG)
	cout << next << " ";
      scc.pop();
      in_stack.erase(next);
    }
    if(DEBUG)
      cout << endl;
    scc.pop();
    in_stack.erase(u);
    sccCount++;
  }
}

int main() {
  int r;
  while(cin >> n >> r && (n || r)) {
    map<string, int> nameMap;
    string line;
    getline(cin, line);
    for(int i= 0; i < n; i++) {
      getline(cin, line);
      nameMap[line] = i;
    }
    memset(v, 0, sizeof v);
    for(int j= 0; j < r; j++) {
      getline(cin, line);
      int start = nameMap[line];
      getline(cin, line);
      int end = nameMap[line];
      v[start][end] = 1;
    }
    memset(dfsnum, -1, sizeof dfsnum);
    memset(dfslow, -1, sizeof dfslow);
    dfsCounter= 0;
    sccCount = 0;
    for(int i= 0; i < n; i++) {
      if(dfsnum[i] == -1) {
	tarjan(i);
      }
    }
    cout << sccCount << endl;
  }
  return 0;
}
