#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#define INF 2e8

using namespace std;

int adjMat[202][202];
int f, s, t;
map<int, int> p;
map<int, vector<int> > adjList;

void insertOrAdd(int u, int v) {
  if(adjList.count(u) == 0) {
    vector<int> singleton;
    singleton.push_back(v);
    adjList[u] = singleton;
  } else
    adjList[u].push_back(v);
}

void augmentPath(int u, int minEdge) {
  if(u == s) {
    f = minEdge;
    return;
  } else if (p.count(u)) {
    augmentPath(p[u], min(minEdge, adjMat[p[u]][u]));
    adjMat[p[u]][u] -= f;
    adjMat[u][p[u]] += f;
  }
}

int main() {
  int tc;
  cin >> tc;
  bool init = true;
  while(tc--) {
    if(!init)
      cout << endl;
    p.clear();
    adjList.clear();
    memset(adjMat, 0, sizeof adjMat);
    map<string, int> plugMap;
    map<string, int> appMap;
    int plugs;
    cin >> plugs;
    string line;
    getline(cin, line);
    s = 0;
    int runningIndex = 1;
    for(int i= 0; i < plugs; i++) {
      getline(cin, line);
      if(plugMap.count(line) == 0) {
	plugMap[line] = runningIndex++;
      }
      adjMat[0][plugMap[line]]++;
      if(adjMat[0][plugMap[line]] == 1) {
	insertOrAdd(0, plugMap[line]);
	insertOrAdd(plugMap[line], 0);
      }
    }
    int apps;
    cin >> apps;
    t = plugs + apps + 1;
    for(int i= 0; i < apps; i++) {
      string appName, plugName;
      cin >> appName >> plugName;
      if(appMap.count(plugName) == 0) {
	appMap[plugName] = runningIndex++;
      }
      adjMat[appMap[plugName]][t]++;
      if(adjMat[appMap[plugName]][t] == 1) {
	insertOrAdd(appMap[plugName], t);
	insertOrAdd(t, appMap[plugName]);
      }
    }    

    int converts;
    cin >> converts;
    map<string, vector<string> > convertMap;
    for(int i= 0; i < converts; i++) {
      string orig, con;
      cin >> con >> orig;
      if(convertMap.count(orig) == 0) {
	vector<string> singleton;
	singleton.push_back(con);
	convertMap[orig] = singleton;
      } else
	convertMap[orig].push_back(con);
    }
    
    for(map<string, int>::iterator itr = plugMap.begin(); itr != plugMap.end(); itr++) {
      string curPlug = itr->first;
      queue<string> q;
      q.push(curPlug);
      while(!q.empty()) {
	string next = q.front();
	q.pop();
	vector<string> nextAdj = convertMap[next];
	for(int i = 0; i < nextAdj.size(); i++) {
	  string nextNode = nextAdj[i];
	  //cout << "checking " << next << " to " << nextNode << endl;
	  if(appMap.count(nextNode) == 0)
	    q.push(nextNode);
	  else if(adjMat[plugMap[curPlug]][appMap[nextNode]] != INF) {
	    //cout << "connecting " << curPlug << " to " << nextNode << endl;
	    adjMat[plugMap[curPlug]][appMap[nextNode]] = INF;
	    insertOrAdd(plugMap[curPlug], appMap[nextNode]);
	    insertOrAdd(appMap[nextNode], plugMap[curPlug]);
	    q.push(nextNode);
	  }
	}
      }
      if(appMap.count(curPlug) != 0 && adjMat[plugMap[curPlug]][appMap[curPlug]] != INF) {
	adjMat[plugMap[curPlug]][appMap[curPlug]] = INF;
	insertOrAdd(plugMap[curPlug], appMap[curPlug]);
	insertOrAdd(appMap[curPlug], plugMap[curPlug]);
      }
    }

    // cout << "before max_flow: " << endl;
    // for(int i = 0; i <= t; i++) {
    //   for(int j= 0; j <= t; j++) {
    // 	cout << adjMat[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    int max_flow = 0;
    while(true) {
      f = 0;
      map<int, int> dist;
      queue<int> q;
      q.push(s);
      dist[s] = 0;
      while(!q.empty()) {
	int u = q.front();
	q.pop();
	if(u == t)
	  break;
	vector<int> uAdj = adjList[u];
	for(int i = 0; i < uAdj.size(); i++) {
	  int v = uAdj[i];
	  //cout << u << " is adjacent to " << v << endl;
	  if(adjMat[u][v] > 0 && !dist.count(v)) {
	    q.push(v);
	    p[v] = u;
	    dist[v] = dist[u] + 1;
	  }
	}
      }
      
      augmentPath(t, INF);
      if(f == 0)
	break;
      max_flow += f;
    }

    // cout << "after max_flow: " << endl;
    // for(int i = 0; i <= t; i++) {
    //   for(int j= 0; j <= t; j++) {
    // 	cout << adjMat[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    cout << apps - max_flow << endl;
    init = false;
  
  }
  return 0;
}
