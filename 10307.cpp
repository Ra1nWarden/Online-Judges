#include <iostream>
#include <queue>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> coord;
typedef pair<int, pair<int, int> > edge;

int r, c;
int bfsNum[50][50];
vector<string> board;
vector<coord> nodes;
priority_queue<edge> edges;

bool legal(int x, int y) {
  if(x >= 0 && x < r && y >= 0 && y < c) {
    return board[x][y] != '#';
  } else {
    return false;
  }
}

ostream& operator<<(ostream& oss, const coord& point) {
  oss << "(" << point.first << ", " << point.second << ")";
  return oss;
}

int bfs(coord a, coord b) {
  memset(bfsNum, -1, sizeof bfsNum);
  int x1 = a.first;
  int y1 = a.second;
  int x2 = b.first;
  int y2 = b.second;
  queue<coord> q;
  bfsNum[x1][y1] = 0;
  q.push(a);
  while(!q.empty() && bfsNum[x2][y2] == -1) {
    coord next = q.front();
    q.pop();
    int x = next.first;
    int y = next.second;
    if(legal(x-1, y) && bfsNum[x-1][y] == -1) {
      bfsNum[x-1][y] = bfsNum[x][y] + 1;
      q.push(make_pair(x-1,y));
    }
    if(legal(x+1, y) && bfsNum[x+1][y] == -1) {
      bfsNum[x+1][y] = bfsNum[x][y] + 1;
      q.push(make_pair(x+1,y));
    }
    if(legal(x, y-1) && bfsNum[x][y-1] == -1) {
      bfsNum[x][y-1] = bfsNum[x][y] + 1;
      q.push(make_pair(x,y-1));
    }
    if(legal(x, y+1) && bfsNum[x][y+1] == -1) {
      bfsNum[x][y+1] = bfsNum[x][y] + 1;
      q.push(make_pair(x,y+1));
    }  
  }
  return bfsNum[x2][y2];
}

void buildGraph() {
  while(!edges.empty())
    edges.pop();
  for(int i= 0; i < nodes.size(); i++) {
    for(int j= i+1; j < nodes.size(); j++) {
      int weight = bfs(nodes[i], nodes[j]);
      edges.push(make_pair(-weight, make_pair(i, j)));
    }
  }
}

int findSet(int i, vector<int>& arr) {
    return arr[i] == i ? arr[i] : arr[i] = findSet(arr[i], arr);
}

bool sameSet(int i , int j, vector<int>& arr) {
  int a = findSet(i, arr);
  int b = findSet(j, arr);
  return a == b;
}

void unionSet(int i, int j, vector<int>& arr) {
  arr[findSet(i, arr)] = findSet(j, arr);
}

int main() {
  int tc;
  cin >> tc;
  string line;
  while(tc--) {
    cin >> c >> r;
    getline(cin, line);
    nodes.clear();
    board.clear();
    for(int i= 0; i< r; i++) {
      getline(cin, line);
      for(int j= 0; j < c; j++) {
	if(line[j] == 'A' || line[j] == 'S') {
	  nodes.push_back(make_pair(i, j));
	}
      }
      board.push_back(line);
    }
    buildGraph();
    int min_cost = 0;
    vector<int> ufset(nodes.size());
    for(int i= 0; i < ufset.size(); i++)
      ufset[i] = i;
    while(!edges.empty()) {
      edge next = edges.top();
      edges.pop();
      //cout << "next edge is " << nodes[next.second.first] << " to " << nodes[next.second.second] << " with weight " << next.first << endl;
      if(!sameSet(next.second.first, next.second.second, ufset)) {
	min_cost += next.first;
	//cout << "unioning " << nodes[next.second.first] << " and " << nodes[next.second.second] << endl;
	unionSet(next.second.first, next.second.second, ufset);
      }
    }
    cout << -min_cost << endl;
  }
  return 0;
}
