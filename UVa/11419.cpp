#include <iostream>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>
#define INF 2e9

using namespace std;

int s, t, f;
map<int, vector<int> > adjList;
int adjMat[2002][2002];
map<int, int> p;

void insertOrAdd(int u, int v) {
  if(adjList.count(u) == 0) {
    vector<int> singleton;
    singleton.push_back(v);
    adjList[u] = singleton;
  } else {
    adjList[u].push_back(v);
  }
}

void augmentPath(int u, int minEdge) {	
  //cout << "begin augmentPath with value " << u << " and " << minEdge << endl;
  if(u == s) {
    //cout << "if" << endl;
    f = minEdge;
    return;
  } else if (p.count(u)) {
    //cout << "else if" << endl;
    augmentPath(p[u], min(minEdge, adjMat[p[u]][u]));
    adjMat[p[u]][u] -= f;
    adjMat[u][p[u]] += f;
  }
  //cout << "end augmentPath" << endl;
}

int main() {
  int r, c, n;
  while(cin >> r >> c >> n && (r || c || n)) {
    int grid[r+1][c+1];
    memset(grid, 0, sizeof grid);
    memset(adjMat, 0, sizeof adjMat);
    p.clear();
    for(int i= 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      grid[x][y] = 1;
      adjMat[x][r+y] = 1;
      insertOrAdd(x, r+y);
      insertOrAdd(r+y, x);
    }

    // cout << "grid: " << endl;
    // for(int i= 1; i <= r; i++) {
    //   for(int j= 1; j <= c; j++) {
    // 	cout << grid[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    
    s = 0;
    t = r + c + 1;
    for(int i = 1; i <= r; i++) {
      adjMat[s][i] = 1;
      insertOrAdd(s, i);
      insertOrAdd(i, s);
    }

    for(int i = r + 1; i <= r + c; i++) {
      adjMat[i][t] = 1;
      insertOrAdd(i, t);
      insertOrAdd(t, i);
    }

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
	for(int i= 0; i < uAdj.size(); i++) {
	  int v = uAdj[i];
	  if(adjMat[u][v] > 0 && !dist.count(v)) {
	    dist[v] = dist[u] + 1;
	    p[v] = u;
	    q.push(v);
	  }
	}
      }
      
      //cout << "begin of call augmentPath" << endl;
      augmentPath(t, INF);
      //cout << "end of call augmentPath" << endl;
      if(f == 0)
	break;
      max_flow += f;
    }



    //cout << max_flow << endl;

    // cout << "adjMat after max_flow:" << endl;
    // for(int i = s; i <= t; i++) {
    //   for(int j= s; j <= t; j++) {
    // 	cout << adjMat[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    vector<string> result;

    bool flowed[2002];
    memset(flowed, false, sizeof flowed);

    for(int i= 1; i <= r; i++) {
      if(adjMat[s][i] == 0)
	flowed[i] = true;
    }
    
    for(int i= r+1; i <= r+c; i++) {
      if(adjMat[i][t] == 0)
	flowed[i] = true;
    }

    // cout << "flowed " << endl;
    // for(int i= 1; i<= r; i++) {
    //   cout << "r" << i << " " << flowed[i] << endl;
    // }
    // for(int i= r+1; i <= r+c; i++) {
    //   cout << "c" << i << " " << flowed[i] << endl;
    // }

    bool visited[2002];
    memset(visited, false, sizeof visited);

    //typedef pair<int, bool> sti;
    
    stack<int> q;
    for(int i = r+1; i <= r+c; i++) {
      if(!flowed[i]) {
	//cout << "pushing " << i << endl;
	q.push(i);
      }
    }

    while(!q.empty()) {
      int next = q.top();
      //cout << "marking " << next << endl;
      q.pop();
      if(visited[next])
	continue;
      visited[next] = true;
      vector<int> nextAdj = adjList[next];
      //int requiredFlow = next.second ? 1 : 0;
      for(int i = 0; i < nextAdj.size(); i++) {
	if(nextAdj[i] != s && nextAdj[i] != t && !visited[nextAdj[i]] && adjMat[next][nextAdj[i]] == 0) {
	  //cout << next << " is adjacent to " << nextAdj[i] << endl;
	  q.push(nextAdj[i]);
	}
      }
    }

    for(int i= 1; i <= r; i++) {
      if(visited[i]) {
	stringstream ss;
	ss << "r" << i;
	result.push_back(ss.str());
      }
    }

    for(int i= r + 1; i <= r + c; i++) {
      if(!visited[i]) {
	stringstream ss;
	ss << "c" << i - r;
	result.push_back(ss.str());
      }
    }

    cout << result.size();
    for(int i= 0; i < result.size(); i++)
      cout << " " << result[i];
    cout << endl;
  }
  return 0;
}
