#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;


bool v[7][7][7][7];
bool visited[7][7];

struct Node {
  Node() {};
  Node(int x, int y) {
    coord = make_pair(x, y);
  };
  pair<int, int> coord;
  string seq;
};

string bfs(int x1, int y1, int x2, int y2) {
  visited[x1][y1] = true;
  Node nextnode(x1, y1);
  nextnode.seq = "";
  queue<Node> q;
  q.push(nextnode);
  string result = "";
  while(!q.empty()) {
    Node next = q.front();
    q.pop();
    int x = next.coord.first;
    int y = next.coord.second;
    if(x == x2 && y == y2) {
      result = next.seq;
      break;
    }
    if(x - 1 > 0 && v[x][y][x-1][y] && !visited[x-1][y]) {
      Node nextstep(x-1,y);
      nextstep.seq = next.seq + "W";
      visited[x-1][y] = true;
      q.push(nextstep);
    }
    if(x + 1 < 7 && v[x][y][x+1][y] && !visited[x+1][y]) {
      Node nextstep(x+1,y);
      nextstep.seq = next.seq + "E";
      visited[x+1][y] = true;
      q.push(nextstep);
    }
    if(y - 1 > 0 && v[x][y][x][y-1] && !visited[x][y-1]) {
      Node nextstep(x,y-1);
      nextstep.seq = next.seq + "N";
      visited[x][y-1] = true;
      q.push(nextstep);
    }
    if(y + 1 < 7 && v[x][y][x][y+1] && !visited[x][y+1]) {
      Node nextstep(x,y+1);
      nextstep.seq = next.seq + "S";
      visited[x][y+1] = true;
      q.push(nextstep);
    }  
  }
  return result;
}

int main() {
  int xstart, ystart;
  while(cin >> xstart >> ystart && (xstart || ystart)) {
    int xend, yend;
    cin >> xend >> yend;
    memset(v, true, sizeof v);
    memset(visited, false, sizeof visited);
    for(int i= 0; i < 3; i++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      if(a == c) {
	for(int j = min(b, d)+1; j < max(b, d) + 1; j++) {
	  if(a != 0 && a != 6) {
	    v[a+1][j][a][j] = false;
	    v[a][j][a+1][j] = false;
	  }
	}
      }
      else if(b == d) {
	for(int j = min(a, c)+1; j < max(a, c) + 1; j++) {
	  if(b != 0 && b != 6) {
	    v[j][b][j][b+1] = false;
	    v[j][b+1][j][b] = false;
	  }
	}
      }
    }
    cout << bfs(xstart, ystart, xend, yend) << endl;
  }
  return 0;
}
