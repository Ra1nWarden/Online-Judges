#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct Node {
  Node() {};
  Node(int n) : pos(n) {
    remain = 16;
    time = 0;
    rest = false;
  };
  int pos;
  int remain;
  bool rest;
  int time;
  bool operator<(const Node& another) const {
    int convert1 = (time + 6) % 24;
    int convert2 = (another.time + 6) % 24;
    if(pos != another.pos)
      return pos < another.pos;
    if(remain != another.remain)
      return remain < another.remain;
    if(convert1 != convert2)
      return convert1 < convert2;
    if(rest != another.rest)
      return rest;
    return false;
  };
};

bool dark(int time) {
  int convert = (time  + 6) % 24;
  return !(convert > 6 && convert < 18);
}

bool valid(string s) {
  int longest = 0;
  int counter = 0;
  for(int i= 0; i < s.length(); i++) {
    if(s[i] == '*') {
      counter++;
    }
    else {
      if(counter > longest)
	longest = counter;
      counter = 0;
    }
  }
  return longest < 11;
}

set<Node> visited; 

int bfs(string s) {
  int dest = s.length() - 1;
  queue<Node> q;
  Node start(0);
  visited.insert(start);
  q.push(start);
  int result = -1;
  while(!q.empty()) {
    Node next = q.front();
    q.pop();
    //cout << "next on queue: " << next.pos << " remain: " << next.remain << " rest: " << next.rest << " time: " << next.time << endl;
    if(next.pos == dest) {
      result = next.time;
      break;
    }
    Node nextstep = next;
    // resting
    if(next.rest) {
      nextstep.time++;
      nextstep.remain--;
      if(nextstep.remain == 0) {
	nextstep.rest = false;
	nextstep.remain = 16;
      }
      if(visited.count(nextstep) == 0) {
	q.push(nextstep);
	visited.insert(nextstep);
      }
    }
    // not resting
    else {
      if(s[next.pos] == '*' && dark(next.time))
	continue;
      if(next.remain == 0) {
	// have to reset
	nextstep.rest = true;
	nextstep.remain = 7;
	nextstep.time++;
	if(visited.count(nextstep) == 0) {
	  q.push(nextstep);
	  visited.insert(nextstep);
	}
      } else {
	// rest
	nextstep.rest = true;
	nextstep.remain = 7;
	nextstep.time++;
	if(visited.count(nextstep) == 0) {
	  q.push(nextstep);
	  visited.insert(nextstep);
	}
	// go
	// when can you go?
	
	Node nextstep2 = next;
	nextstep2.time++;
	nextstep2.remain--;
	nextstep2.pos++;
	if(visited.count(nextstep2) == 0) {
	  q.push(nextstep2);
	  visited.insert(nextstep2);
	}
      }
    }
  }
  return result;
}

int main() {
  int tc;
  cin >> tc;
  string line;
  getline(cin, line);
  for(int t = 1; t <= tc; t++) {
    getline(cin, line);
    int result = -1;
    if(valid(line)) {
      visited.clear();
      result = bfs(line);
    }
    cout << "Case #" << t << ": " << result << endl;
  }
  return 0;
}
