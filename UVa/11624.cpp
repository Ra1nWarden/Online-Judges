#include <iostream>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

int x, y;
vector<pair<int, int> > fires;
vector<string> board;
int bfsIndex[1001][1001];
int r, c;

bool legal(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c && board[x][y] != '#';
}

bool border(int x, int y) {
  return x == 0 || x == r-1 || y == 0 || y == c-1;
}

int bfs() {
  bfsIndex[x][y] = 0;
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));
  for(int i= 0; i < fires.size(); i++) {
    board[fires[i].first][fires[i].second] = '#';
  }
  int result = -1;
  while(!q.empty()) {
    pair<int, int> next = q.front();
    q.pop();
    for(int i= 0; i < fires.size(); i++) {
      pair<int, int> each = fires[i];
      int x1 = each.first;
      int y1 = each.second;
      if(legal(x1-1, y))
	board[x1-1][y1] = '#';
      if(legal(x1+1, y1))
	board[x1+1][y1] = '#';
      if(legal(x1, y1+1))
	board[x1][y1+1] = '#';
      if(legal(x1, y1-1))
	board[x1][y1-1] = '#';
    }
    int x1 = next.first;
    int y1 = next.second;
    if(border(x1, y1))
      return 1;
    //cout << "at " << x1 << ", " << y1 << endl;
    if(legal(x1-1, y1) && bfsIndex[x1-1][y1] == -1) {
      bfsIndex[x1-1][y1] = bfsIndex[x1][y1] + 1;
      if(border(x1-1,y1)) {
	result = bfsIndex[x1-1][y1];
	break;
      } else {
	q.push(make_pair(x1-1, y1));
      }
    }
    if(legal(x1+1, y1) && bfsIndex[x1+1][y1] == -1) {
      bfsIndex[x1+1][y1] = bfsIndex[x1][y1] + 1;
      if(border(x1+1, y1)) {
	result = bfsIndex[x1+1][y1];
	//cout << result << " for " << x1 << ", " << y1 << endl;
	break;
      } else {
	q.push(make_pair(x1+1, y1));
      }
    }
    if(legal(x1, y1+1) && bfsIndex[x1][y1+1] == -1) {
      bfsIndex[x1][y1+1] = bfsIndex[x1][y1] + 1;
      if(border(x1, y1+1)) {
	result = bfsIndex[x1][y1+1];
      } else {
	q.push(make_pair(x1, y1+1));
      }
    }
    if(legal(x1, y1-1) && bfsIndex[x1][y1-1] == -1) {
      bfsIndex[x1][y1-1] = bfsIndex[x1][y1] + 1;
      if(border(x1, y1-1)) {
	result = bfsIndex[x1][y1-1];
      } else {
	q.push(make_pair(x1, y1-1));
      }
    }
  }
  return result == -1 ? -1 : result + 1;
}

int main() {
  int tc;
  cin >> tc;
  string line;
  while(tc--) {
    cin >> r >> c;
    getline(cin, line);
    board.clear();
    fires.clear();
    for(int i = 0; i < r; i++) {
      getline(cin, line);
      board.push_back(line);
      for(int j= 0; j < c; j++) {
	if(line[j] == 'J') {
	  x = i;
	  y = j;
	}
	if(line[j] == 'F') {
	  fires.push_back(make_pair(i, j));
	}
      }
    }
    memset(bfsIndex, -1, sizeof bfsIndex);
    int result = bfs();
    if(result == -1)
      cout << "IMPOSSIBLE" << endl;
    else
      cout << result << endl;
  }
  return 0;
}
