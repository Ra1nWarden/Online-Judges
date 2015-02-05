#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

struct Board {
  Board() {};
  Board(vector<vector<int> > b) : v(b) {};
  vector<vector<int> > v;
  bool operator<(const Board& another) const {
    for(int i= 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
	if(v[i][j] != another.v[i][j])
	  return v[i][j] < another.v[i][j];
      }
    }
    return false;
  };
};

map<Board, string> dict;

Board transform(Board orig, int i, bool row, bool pos) {
  Board result = orig;
  if(row) {
    if(pos) {
      int tmp = result.v[i][2];
      result.v[i][2] = result.v[i][1];
      result.v[i][1] = result.v[i][0];
      result.v[i][0] = tmp;
    }
    else {
      int tmp = result.v[i][0];
      result.v[i][0] = result.v[i][1];
      result.v[i][1] = result.v[i][2];
      result.v[i][2] = tmp;
    }
  }
  else {
    if(pos) {
      int tmp = result.v[2][i];
      result.v[2][i] = result.v[1][i];
      result.v[1][i] = result.v[0][i];
      result.v[0][i] = tmp;
    }
    else {
      int tmp = result.v[0][i];
      result.v[0][i] = result.v[1][i];
      result.v[1][i] = result.v[2][i];
      result.v[2][i] = tmp;
    }
  }
  return result;
}

ostream& operator<<(ostream& oss, const Board& board) {
  for(int i= 0; i < 3; i++) {
    for(int j =0; j < 3; j++) {
      oss << board.v[i][j];
    }
    oss << endl;
  }
  oss << endl;
  return oss;
}

int main() {
  int r1[] = {1,2,3};
  int r2[] = {4,5,6};
  int r3[] = {7,8,9};
  vector<vector<int> > startv;
  vector<int> r1v(r1, r1+3);
  vector<int> r2v(r2, r2+3);
  vector<int> r3v(r3, r3+3);
  startv.push_back(r1v);
  startv.push_back(r2v);
  startv.push_back(r3v);
  Board start(startv);
  queue<Board> q;
  dict[start] = "";
  q.push(start);
  while(!q.empty()) {
    Board next = q.front();
    q.pop();
    for(int i = 0; i < 3; i++) {
      ostringstream oss;
      oss << "H" << i+1;
      string add = oss.str();
      Board transp = transform(next, i, true, false);
      if(dict.count(transp) == 0) {
	dict[transp] = add + dict[next];
	//cout << transp << dict[transp] << endl;
	q.push(transp);
      }
    }
    for(int i = 0; i < 3; i++) {
      ostringstream oss;
      oss << "V" << i+1;
      string add = oss.str();
      Board transn = transform(next, i, false, true);
      if(dict.count(transn) == 0) {
	dict[transn] = add + dict[next];
	//cout << transn << dict[transn] << endl;
	q.push(transn);
      }
    }
  }
  
  int x;
  while(cin >> x && x) {
    vector<vector<int> > b;
    vector<int> r;
    r.push_back(x);
    for(int i= 1; i < 9; i++) {
      cin >> x;
      r.push_back(x);
      if(i % 3 == 2) {
	b.push_back(r);
	r.clear();
      }
    }
    Board test(b);
    if(dict.count(test) == 0) {
      cout << "Not solvable" << endl;
    }
    else {
      string result = dict[test];
      if(!result.empty())
	cout << (result.length() / 2) << " " << result << endl;
      else
	cout << 0 << endl;
    }
  }
  return 0;
}
