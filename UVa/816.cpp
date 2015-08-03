#include <iostream>
#include <sstream>
#include <queue>
#include <cstring>
#define MAXN 10

using namespace std;

const char* dirs = "NESW";
const char* turns = "FLR";

int dir_id(char c) {
  return strchr(dirs, c) - dirs;
}

int turn_id(char c) {
  return strchr(turns, c) - turns;
}

const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};

struct Rule {
  string rules[4];
};

Rule board[MAXN][MAXN];
typedef pair<int, int> Point;
typedef pair<Point, int> Node;
Node parent[MAXN][MAXN][4];
vector<Node> path;

Node walk(Node node, int turn) {
  int dir = node.second;
  if(turn == 1) {
    dir = (dir + 3) % 4;
  }
  if(turn == 2) {
    dir = (dir + 1) % 4;
  }
  return make_pair(make_pair(node.first.first + dx[dir], node.first.second + dy[dir]), dir);
}

bool visited[MAXN][MAXN][4];

int main() {
  ios::sync_with_stdio(false);
  string name;
  while(getline(cin, name)) {
    Rule empty_rule;
    for(int i = 1; i <= 9; i++) {
      for(int j = 1; j <= 9; j++) {
	board[i][j] = empty_rule;
      }
    }
    if(name == "END")
      break;
    string info;
    getline(cin, info);
    stringstream infoss(info.c_str());
    int sx, sy;
    infoss >> sx >> sy;
    Point start = make_pair(sx, sy);
    string sdir;
    infoss >> sdir;
    int dir = dir_id(sdir[0]);
    Node startNode = walk(make_pair(start, dir), 0);
    int ex, ey;
    infoss >> ex >> ey;
    string line;
    while(getline(cin, line)) {
      stringstream ss(line.c_str());
      int x, y;
      ss >> x;
      if(!x)
	break;
      ss >> y;
      string dir;
      while(ss >> dir) {
	if(dir == "*")
	  break;
	board[x][y].rules[dir_id(dir[0])] = dir.substr(1);
      }
    }
    if(startNode.first.first == ex && startNode.first.second == ey) {
      cout << name << endl;
      cout << "  (" << sx << "," << sy << ") (" << ex << "," << ey << ")" << endl;
      continue;
    }
    queue<Node> q;
    q.push(startNode);
    memset(visited, false, sizeof visited);
    visited[startNode.first.first][startNode.first.second][startNode.second] = true;
    bool ok = false;
    while(!q.empty()) {
      Node u = q.front();
      q.pop();
      int x = u.first.first;
      int y = u.first.second;
      int dir = u.second;
      for(int i = 0; i < board[x][y].rules[dir].length(); i++) {
	Node v = walk(u, turn_id(board[x][y].rules[dir][i]));
	if(!visited[v.first.first][v.first.second][v.second]) {
	  q.push(v);
	  parent[v.first.first][v.first.second][v.second] = u;
	  visited[v.first.first][v.first.second][v.second] = true;
	  if(v.first.first == ex && v.first.second == ey) {
	    // construct path here...
	    path.clear();
	    path.push_back(v);
	    Node fa = u;
	    while(fa != startNode) {
	      path.push_back(fa);
	      fa = parent[fa.first.first][fa.first.second][fa.second];
	    }
	    path.push_back(startNode);
	    path.push_back(make_pair(start, dir_id(sdir[0])));
	    ok = true;
	    break;
	  }
	}
      }
      if(ok)
	break;
    }
    cout << name << endl;
    if(!ok) {
      cout << "  No Solution Possible" << endl;
      continue;
    }
    for(int i = 0; i < path.size(); i++) {
      if(i % 10 == 0) {
	cout << "  ";
      } else {
	cout << " ";
      }
      cout << "(" << path[path.size() - 1 - i].first.first << "," << path[path.size() - 1 - i].first.second << ")";
      if(i % 10 == 9)
	cout << endl;
    }
    if(path.size() % 10 != 0) {
      cout << endl;
    }
  }
  return 0;
}
