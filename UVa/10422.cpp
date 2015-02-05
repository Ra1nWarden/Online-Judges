#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Board {
  Board() {};
  Board(vector<string> m) : v(m) {};
  int index;
  vector<string> v;
  bool operator<(const Board& another) const {
    for(int i= 0; i < 5; i++) {
      if(v[i] != another.v[i])
	return v[i] < another.v[i];
    }
    return false;
  };
  bool operator==(const Board& another) const {
    for(int i= 0; i < 5; i++) {
      if(v[i] != another.v[i])
	return false;
    }
    return true;
  };
};

Board target;
set<Board> visited;

ostream& operator<<(ostream& oss, const Board& b) {
  for(int i= 0; i < 5; i++) {
    for(int j= 0; j < 5; j++)
      oss << b.v[i][j];
    oss << endl;
  }
  oss << endl;
  return oss;
}

void bfs(Board start) {
  visited.insert(start);
  queue<Board> q;
  start.index = 0;
  q.push(start);
  while(!q.empty()) {
    Board next = q.front();
    // cout << "index: " << next.index << endl << next << endl;
    q.pop();
    if(next.index == 10)
      continue;
    vector<string> nextv = next.v;
    int x = -1;
    int y = -1;
    for(int i= 0; i < 5; i++) {
      for(int j= 0; j < 5; j++) {
	if(nextv[i][j] == ' ') {
	  x = i;
	  y = j;
	}
      }
    }
    if(x + 2 < 5) {
      if(y - 1 >= 0) {
	vector<string> newv = nextv;
	newv[x][y] = newv[x+2][y-1];
	newv[x+2][y-1] = ' ';
	Board nextb(newv);
	if(visited.count(nextb) == 0) {
	  nextb.index = next.index + 1;

	  q.push(nextb);
	  visited.insert(nextb);
	}
      }
      if(y + 1 < 5) {
	vector<string> newv = nextv;
	newv[x][y] = newv[x+2][y+1];
	newv[x+2][y+1] = ' ';
	Board nextb(newv);
	if(visited.count(nextb) == 0) {
	  nextb.index = next.index + 1;

	  q.push(nextb);
	  visited.insert(nextb);
	}
      }
    }
    if(x - 2 >= 0) {
      if(y - 1 >= 0) {
	vector<string> newv = nextv;
	newv[x][y] = newv[x-2][y-1];
	newv[x-2][y-1] = ' ';
	Board nextb(newv);
	if(visited.count(nextb) == 0) {
	  nextb.index = next.index + 1;

	  q.push(nextb);
	  visited.insert(nextb);
	}
      }
      if(y + 1 < 5) {
	vector<string> newv = nextv;
	newv[x][y] = newv[x-2][y+1];
	newv[x-2][y+1] = ' ';
	Board nextb(newv);
	if(visited.count(nextb) == 0) {
	  nextb.index = next.index + 1;

	  q.push(nextb);
	  visited.insert(nextb);
	}
      }
    }
    if(y - 2 >= 0) {
      if(x - 1 >= 0) {
	vector<string> newv = nextv;
	newv[x][y] = newv[x-1][y-2];
	newv[x-1][y-2] = ' ';
	Board nextb(newv);
	if(visited.count(nextb) == 0) {
	  nextb.index = next.index + 1;

	  q.push(nextb);
	  visited.insert(nextb);
	}
      }
      if(x + 1 < 5) {
	vector<string> newv = nextv;
	newv[x][y] = newv[x+1][y-2];
	newv[x+1][y-2] = ' ';
	Board nextb(newv);
	if(visited.count(nextb) == 0) {
	  nextb.index = next.index + 1;

	  q.push(nextb);
	  visited.insert(nextb);
	}
      }
    }
    if(y + 2 < 5) {
      if(x - 1 >= 0) {
	vector<string> newv = nextv;
	newv[x][y] = newv[x-1][y+2];
	newv[x-1][y+2] = ' ';
	Board nextb(newv);
	if(visited.count(nextb) == 0) {
	  nextb.index = next.index + 1;

	  q.push(nextb);
	  visited.insert(nextb);
	}
      }
      if(x + 1 < 5) {
	vector<string> newv = nextv;
	newv[x][y] = newv[x+1][y+2];
	newv[x+1][y+2] = ' ';
	Board nextb(newv);
	if(visited.count(nextb) == 0) { 
	  nextb.index = next.index + 1;

	  q.push(nextb);
	  visited.insert(nextb);
	}
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  string line;
  getline(cin, line);
  vector<string> targetv;
  string a = "11111";
  string b = "01111";
  string c = "00 11";
  string d = "00001";
  string e = "00000";
  targetv.push_back(a);
  targetv.push_back(b);
  targetv.push_back(c);
  targetv.push_back(d);
  targetv.push_back(e);
  target.v = targetv;
  visited.clear();
  target.index = 0;
  bfs(target);
  while(n--) {
    vector<string> startv;
    for(int i = 0; i < 5; i++) {
      getline(cin, line);
      startv.push_back(line);
    }
    Board start(startv);
    // cout << "count returns " << visited.count(start) << endl;
    set<Board>::iterator found = find(visited.begin(), visited.end(), start);
    if(found == visited.end())
      cout << "Unsolvable in less than 11 move(s)." << endl;
    else
      cout << "Solvable in " << found->index << " move(s)." << endl;
  }
  return 0;
}
