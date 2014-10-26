#include <iostream>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

bool DEBUG = false;

bool bfsPossible[300][300][4];
bool v[300][300];
int r, c;
int x1, y1;
int x2, y2;

bool valid(int startx, int starty, int endx, int endy) {
  if(startx == endx) {
    int lessy = min(starty, endy);
    int morey = max(starty, endy);
    for(int i= lessy; i <= morey; i++) {
      if(!v[startx][i])
	return false;
    }
    return true;
  }
  else if (starty == endy) {
    int lessx = min(startx, endx);
    int morex = max(startx, endx);
    for(int i=  lessx; i <= morex; i++) {
      if(!v[i][starty])
	return false;
    }
    return true;
  }
  return false;
}

int bfs(int startx, int starty, int endx, int endy) {
  queue<pair<int, int> > q;
  queue<int> indexq;
  q.push(make_pair(startx, starty));
  indexq.push(0);
  bfsPossible[startx][starty][1] = false;
  int result = -1;
  while(!q.empty()) {
    pair<int, int> next = q.front();
    int bfsIndex = indexq.front();
    indexq.pop();
    q.pop();
    int x = next.first;
    int y = next.second;
    if(x == endx && y == endy) {
      result = bfsIndex;
      break;
    }
    int step = bfsIndex % 3 + 1;
    if(DEBUG)
      cout << "next is " << x << ", " << y << " step is " << step << " bfsIndex is " << bfsIndex << endl;
    if(x-step >= 0 && bfsPossible[x-step][y][step % 3 + 1] && valid(x, y, x-step, y)) {
      if(DEBUG)
	cout << "going negative x" << endl;

      bfsPossible[x-step][y][step % 3 + 1] = false;
      q.push(make_pair(x-step, y));
      indexq.push(bfsIndex+1);
    }
    if(x+step < r && bfsPossible[x+step][y][step % 3 + 1] && valid(x, y, x+step, y)) {
      if(DEBUG)
	cout << "going positive x" << endl;

      bfsPossible[x+step][y][step % 3 + 1] = false;
      q.push(make_pair(x+step, y));
      indexq.push(bfsIndex+1);
    }
    if(y-step >= 0 && bfsPossible[x][y-step][step % 3 + 1] && valid(x, y, x, y-step)) {
      if(DEBUG)
	cout << "going negative y" << endl;

      bfsPossible[x][y-step][step%3 + 1] = false;
      q.push(make_pair(x, y-step));
      indexq.push(bfsIndex+1);
    }
    if(y+step < c && bfsPossible[x][y+step][step%3 + 1] && valid(x, y, x, y+step)) {
      if(DEBUG)
	cout << "going positive y" << endl;

      bfsPossible[x][y+step][step%3 + 1] = false;
      q.push(make_pair(x, y+step));
      indexq.push(bfsIndex+1);
    }
    
  }
  return result;
}

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    cin >> r >> c >> ws;
    memset(v, false, sizeof v);
    for(int i = 0; i < r; i++) {
      string line;
      getline(cin, line);
      for(int j= 0; j < c; j++) {
	if(line[j] == 'S') {
	  x1 = i;
	  y1 = j;
	  v[i][j] = true;
	}
	else if (line[j] == '.') {
	  v[i][j] = true;
	}
	else if (line[j] == 'E') {
	  x2 = i;
	  y2 = j;
	  v[i][j] = true;
	}
	else if (line[j] == '#') {
	  v[i][j] = false;
	}
      }
    }
    memset(bfsPossible, true, sizeof bfsPossible);
    int result = bfs(x1, y1, x2, y2);
    if(result == -1)
      cout << "NO" << endl;
    else
      cout << result << endl;
  }
  return 0;
}
