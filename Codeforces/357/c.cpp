#include <iostream>
#include <sstream>
#include <queue>
#include <functional>

using namespace std;

string line;

int main() {
  ios::sync_with_stdio(false);
  getline(cin, line);
  int n;
  stringstream ss(line.c_str());
  ss >> n;
  int cnt = 0;
  priority_queue<int, vector<int>, greater<int> > pq;
  stringstream output;
  while(n--) {
    getline(cin, line);
    stringstream ls(line.c_str());
    string cmd;
    ls >> cmd;
    if(cmd == "insert") {
      int num;
      ls >> num;
      output << line << endl;
      cnt++;
      pq.push(num);
    } else if(cmd == "removeMin") {
      if(pq.empty()) {
	output << "insert 1" << endl;
	pq.push(1);
	cnt++;
      }
      pq.pop();
      output << line << endl;
      cnt++;
    } else if(cmd == "getMin") {
      int num;
      ls >> num;
      while(!pq.empty() && pq.top() < num) {
	pq.pop();
	output << "removeMin" << endl;
	cnt++;
      }
      if(pq.empty() || pq.top() > num) {
	pq.push(num);
	output << "insert " << num << endl;
	cnt++;
      }
      output << line << endl;
      cnt++;
    }
  }
  cout << cnt << endl;
  cout << output.str();
  return 0;
}
