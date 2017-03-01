#include <cstdio>
#include <cstring>
#include <utility>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int maxn = 1000;
char board[maxn+5][maxn+5];
typedef pair<int, int> Point;
map<Point, vector<Point> > connects;
map<Point, vector<Point> > explodes;
map<Point, int> idx;
map<int, set<Point> > idx_explodes;
int n, r;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void explore(int x, int y, int xx, int yy) {
  Point base = make_pair(x, y);
  for(int len = 1; len <= r; len++) {
    int new_x = x + len * xx;
    int new_y = y + len * yy;
    Point another = make_pair(new_x, new_y);
    if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)
      break;
    if(board[new_x][new_y] == '#')
      break;
    if(board[new_x][new_y] == '*') {
      connects[base].push_back(another);
      connects[another].push_back(base);
    }
    if(board[new_x][new_y] == 'S') {
      explodes[base].push_back(another);
    }
  }
}

void explode(int x, int y, int xx, int yy, set<Point>& trees, set<int>& indirect) {
  Point base = make_pair(x, y);
  for(int len = 1; len <= r; len++) {
    int new_x = x + len * xx;
    int new_y = y + len * yy;
    Point another = make_pair(new_x, new_y);
    if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)
      break;
    if(board[new_x][new_y] == '#')
      break;
    if(board[new_x][new_y] == '*') {
      indirect.insert(idx[another]);
    }
    if(board[new_x][new_y] == 'S') {
      trees.insert(another);
    }
  }
}

void merge() {
  int next_idx = 0;
  for(map<Point, vector<Point> >::iterator itr = connects.begin(); itr != connects.end(); itr++) {
    Point u = itr->first;
    if(idx.count(u) == 0) {
      set<Point> ans;
      idx[u] = ++next_idx;
      queue<Point> q;
      q.push(u);
      while(!q.empty()) {
	Point qu = q.front();
	q.pop();
	for(int i = 0; i < connects[qu].size(); i++) {
	  Point v = connects[qu][i];
	  if(idx.count(v) == 0) {
	    idx[v] = next_idx;
	    q.push(v);
	  }
	}
	for(int i = 0; i < explodes[qu].size(); i++) {
	  Point v =  explodes[qu][i];
	  ans.insert(v);
	}
      }
      idx_explodes[next_idx] = ans;
    }
  }
}

int main() {
  scanf("%d %d\n", &n, &r);
  for(int i = 0; i < n; i++)
    scanf("%s\n", board[i]);
  int total = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(board[i][j] == '*') {
	for(int k = 0; k < 4; k++)
	  explore(i, j, dx[k], dy[k]);
      } else if(board[i][j] == 'S') {
	total++;
      }
    }
  }
  merge();
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(board[i][j] == '.') {
	set<Point> trees;
	set<int> indirect;
	for(int k = 0; k < 4; k++)
	  explode(i, j, dx[k], dy[k], trees, indirect);
	for(set<int>::iterator itr = indirect.begin(); itr != indirect.end(); itr++) {
	  int i = *itr;
	  set<Point> points = idx_explodes[i];
	  for(set<Point>::iterator point = points.begin(); point != points.end(); point++) {
	    trees.insert(*point);
	  }
	}
	if(trees.size() == total) {
	  ans++;
	}
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
