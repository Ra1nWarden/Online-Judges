#include <iostream>
#include <sstream>
#include <cstring>
#include <queue>
#include <cmath>
#define MAXN 18
#define MAXC 260

using namespace std;

struct Node {
  int a, b, c;
  Node(int a, int b, int c) : a(a), b(b), c(c) {}
};

string board[MAXN];
int m, n, c;
int visited[MAXC][MAXC][MAXC];
int start[3], end[3];
queue<Node> fq, bq;
int ans;

int dx[] = {0, 0, -1, 0, 1};
int dy[] = {0, -1, 0, 1, 0};

bool generate(int num, int dir, int& new_num) {
  if(num == -1) {
    new_num = -1;
    return true;
  }
  int x = num / n;
  int y = num % n;
  int xx = x + dx[dir];
  int yy = y + dy[dir];
  new_num =  xx * n + yy;
  return xx > -1 && xx < m && yy > -1 && yy < n && board[xx][yy] != '#';
}

int norm(int num) {
  return num == -1 ? 256 : num;
}

bool valid(int a, int b, int c, int aa, int bb, int cc) {
  if(a == aa && b == bb && c == cc)
    return false;
  if(aa != -1 && bb != -1 && aa == bb)
    return false;
  if(bb != -1 && cc != -1 && bb == cc)
    return false;
  if(aa != -1 && cc != -1 && aa == cc)
    return false;
  if(a != -1 && b != -1 && aa == b && bb == a)
    return false;
  if(b != -1 && c != -1 && bb == c && cc == b)
    return false;
  if(c != -1 && a != -1 && aa == c && cc == a)
    return false;
  return true;
}

bool expand(queue<Node>& q, bool forward) {
  queue<Node> qq;
  while(!q.empty()) {
    Node u = q.front();
    q.pop();
    int aa, bb, cc;
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
	if(u.b == -1)
	  j = 4;
	for(int k = 0; k < 5; k++) {
	  if(u.c == -1)
	    k = 4;
	  if(generate(u.a, i, aa) && generate(u.b, j, bb) && generate(u.c, k, cc) && valid(u.a, u.b, u.c, aa, bb, cc)) {
	    if(visited[norm(aa)][norm(bb)][norm(cc)] != 0 && visited[norm(aa)][norm(bb)][norm(cc)] > 0 != forward) {
	      ans = abs(visited[norm(u.a)][norm(u.b)][norm(u.c)]) + abs(visited[norm(aa)][norm(bb)][norm(cc)]) - 1;
	      return false;
	    } else if(visited[norm(aa)][norm(bb)][norm(cc)] == 0) {
	      if(forward) {
		visited[norm(aa)][norm(bb)][norm(cc)] = visited[norm(u.a)][norm(u.b)][norm(u.c)] + 1;
	      } else {
		visited[norm(aa)][norm(bb)][norm(cc)] = visited[norm(u.a)][norm(u.b)][norm(u.c)] - 1;
	      }
	      qq.push(Node(aa, bb, cc));
	    }
	  }
	}
      }
    }
  }
  q = qq;
  return true;
}

int bfs() {
  while(true) {
    if(!expand(fq, true) || !expand(bq, false))
      break;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  while(true) {
    string nums;
    getline(cin, nums);
    stringstream ss(nums.c_str());
    ss >> n >> m >> c;
    if(!(n || m || c))
      break;
    for(int i = 0; i < m; i++) {
      getline(cin, board[i]);
    }
    memset(start, -1, sizeof start);
    memset(end, -1, sizeof end);
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
	if(board[i][j] >= 'a' && board[i][j] <= 'c') {
	  start[board[i][j] - 'a'] = i * n + j;
	} else if(board[i][j] >= 'A' && board[i][j] <= 'C') {
	  end[board[i][j] - 'A'] = i * n + j;
	} 
      }
    }
    memset(visited, 0, sizeof visited);
    queue<Node> eq;
    fq = eq;
    bq = eq;
    Node sn(start[0], start[1], start[2]);
    Node en(end[0], end[1], end[2]);
    fq.push(sn);
    bq.push(en);
    visited[norm(start[0])][norm(start[1])][norm(start[2])] = 1;
    visited[norm(end[0])][norm(end[1])][norm(end[2])] = -1;
    cout << bfs() << endl;
  }
  return 0;
}
