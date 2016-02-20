#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

struct Node {
  int id;
  int time;
  int period;
  Node(int a, int b, int c) : id(a), time(b), period(c) {}
  bool operator<(const Node& rhs) const {
    if(time != rhs.time) {
      return time > rhs.time;
    } else {
      return id > rhs.id;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  string line;
  priority_queue<Node> pq;
  while(getline(cin, line)) {
    if(line == "#")
      break;
    stringstream ss(line.c_str());
    string reg;
    int num, p;
    ss >> reg >> num >> p;
    pq.push(Node(num, p, p));
  }
  int k;
  cin >> k;
  while(k--) {
    Node u = pq.top();
    pq.pop();
    cout << u.id << endl;
    u.time += u.period;
    pq.push(u);
  }
  return 0;
}
