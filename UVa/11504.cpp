#include <iostream>
#include <cstring>
#include <stack>
#include <set>
#include <vector>
#include <map>

using namespace std;

int n;
int dfsCount;
map<int, int> dfsnum;
map<int, int> dfslow;
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
    if(dfsnum.count(next) == 0) {
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
    dfsCount = 0;
    dfsnum.clear();
    dfslow.clear();
    while(!scc.empty())
      scc.pop();
    in_stack.clear();
    sccv.clear();
    for(int i= 1;i <= n; i++) {
      if(dfsnum.count(i) == 0) 
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
    
    vector<int> inDegree(newn, 0);

    for(int i= 0; i < newn; i++) {
      for(int j= 0; j < reducedadj[i].size(); j++) {
	inDegree[reducedadj[i][j]]++;
      }
    } 

    if(DEBUG) {
      cout << "printing inDegrees:" << endl;
      for(int i= 0; i < newn; i++)
	cout << i << " has indegree " << inDegree[i] << endl;
    }
    
    int knock = 0;
    for(int i= 0; i < newn; i++) {
      if(inDegree[i] == 0)
	knock++;
    }

    cout << knock << endl;

  }
  return 0;
}
