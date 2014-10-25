#include <iostream>
#include <cstring>
#include <stack>
#include <set>
#include <vector>
#include <map>

using namespace std;

int n;
int dfsnum[100001];
int dfslow[100001];
int dfsCount;
set<int> in_stack;
stack<int> scc;
map<int, vector<int> > adj;
vector<vector<int> > sccv;

bool DEBUG = false;
bool TARJANDEBUG = false;

void tarjan(int u) {
  if(TARJANDEBUG)
    cout << "calling tarjan on " << u << endl;
  dfsnum[u] = dfslow[u] = dfsCount++;
  scc.push(u);
  in_stack.insert(u);
  for(int i= 0; i < adj[u].size(); i++) {
    int next = adj[u][i];
    if(dfsnum[next] == -1) {
      tarjan(next);
      dfslow[u] = min(dfslow[u], dfslow[next]);
    }
    else if(in_stack.count(next) != 0)
      dfslow[u] = min(dfslow[u], dfsnum[next]);
  }
  if(dfsnum[u] == dfslow[u]) {
    if(TARJANDEBUG)
      cout << "putting into sccv for " << u << endl;
    vector<int> each;
    while(!scc.empty() && scc.top() != u) {
      int next = scc.top();
      scc.pop();
      in_stack.erase(next);
      each.push_back(next);
    }
    scc.pop();
    in_stack.erase(u);
    each.push_back(u);
    sccv.push_back(each);
  }
}

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    adj.clear();
    int l;
    cin >> n >> l;
    for(int i= 0; i < l; i++) {
      int x, y;
      cin >> x >> y;
      if(adj.count(x) == 0) {
	vector<int> adjList;
	adjList.push_back(y);
	adj[x] = adjList;
      } else {
	adj[x].push_back(y);
      }
    }
    memset(dfsnum, -1, sizeof dfsnum);
    memset(dfslow, -1, sizeof dfslow);
    dfsCount = 0;
    while(!scc.empty())
      scc.pop();
    in_stack.clear();
    sccv.clear();
    for(int i= 1;i <= n; i++) {
      if(dfsnum[i] == -1) 
	tarjan(i);
    }

    if(DEBUG) {
      cout << "printint SCCs" << endl;
      for(int i= 0; i < sccv.size(); i++) {
	for(int j= 0; j < sccv[i].size(); j++)
	  cout << sccv[i][j];
	cout << endl;
      }
      cout << endl;
    }

    map<int, int> nodeConvert;
    for(int i= 0; i < sccv.size(); i++) {
      for(int j =0; j < sccv[i].size(); j++) {
	nodeConvert[sccv[i][j]] = i;
      }
    }
    vector<vector<int> > reducedadj;
    
    for(int i =0; i < sccv.size(); i++) {
      set<int> newedges;
      for(int j= 0; j < sccv[i].size(); j++) {
	for(int k = 0; k < adj[sccv[i][j]].size(); k++) {
	  int connect = adj[sccv[i][j]][k];
	  if(nodeConvert[connect] != nodeConvert[sccv[i][j]]) {
	    newedges.insert(nodeConvert[connect]);
	  }
	}
      }
      vector<int> newV(newedges.begin(), newedges.end());
      reducedadj.push_back(newV);
    }

    if(DEBUG) {
      cout << "printing reducedadj:" << endl;
      for(int i= 0; i < reducedadj.size(); i++) {
	for(int j= 0; j < reducedadj[i].size(); j++) {
	  cout << "new node indexed " << i << " has child " << reducedadj[i][j] << endl;
	}
      }
      cout << endl;
    }

    int newn = reducedadj.size();

    vector<vector<int> > newadjMat;
    for(int i= 0; i < newn; i++) {
      vector<int> emptyRow(newn, 0);
      newadjMat.push_back(emptyRow);
    }
    
    for(int i = 0; i < newn; i++) {
      for(int j = 0; j < reducedadj[i].size(); j++) {
	int start = i;
	int end = reducedadj[i][j];
	newadjMat[start][end] = 1;
      }
    }

    if(DEBUG) {
      cout << "adjmatrix: " << endl;
      for(int i= 0; i < newn; i++) {
	for(int j= 0; j < newn; j++) {
	  cout << newadjMat[i][j];
	}
	cout << endl;
      }
      cout << endl;
    }
    
    vector<bool> visited(newn, false);
    int knock = 0;
    int knocked = 0;
    while(knocked < newn) {
      int nextNode = -1;
      for(int j = 0; j < newn; j++) {
	if(visited[j])
	  continue;
	bool ok = true;
	for(int i = 0; i < newn; i++) {
	  if(newadjMat[i][j] != 0 && !visited[i]) {
	    ok = false;
	    break;
	  }
	}
	if(ok) {
	  nextNode = j;
	}
      }
      if(DEBUG) {
	cout << "kncoking " << nextNode << endl;
      }
      stack<int> s;
      visited[nextNode] = true;
      knocked++;
      s.push(nextNode);
      while(!s.empty()) {
	int next = s.top();
	s.pop();
	for(int i = 0; i < newn; i++) {
	  if(newadjMat[next][i] && !visited[i]) {
	    visited[i] = true;
	    knocked++;
	    s.push(i);
	  }
	}
      }
      knock++;
    }
    cout << knock << endl;
  }
  return 0;
}
