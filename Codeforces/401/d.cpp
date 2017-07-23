#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

string check(string cur, string prev) {
  stringstream ss;
  int cl = cur.length();
  int pl = prev.length();
  for(int i = 0; i < min(cl, pl); i++) {
    if(cur[i] > prev[i]) {
      break;
    } else if(cur[i] < prev[i]) {
      return cur;
    } else {
      ss << cur[i];
    }
  }
  return ss.str();
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n >> ws;
  stack<string> v;
  string line;
  while(n--) {
    getline(cin, line);
    v.push(line);
  }
  stack<string> ans;
  string prev = v.top();
  v.pop();
  string cur;
  ans.push(prev);
  while(!v.empty()) {
    cur = v.top();
    v.pop();
    cur = check(cur, prev);
    ans.push(cur);
    prev = cur;
  }
  while(!ans.empty()) {
    cout << ans.top() << endl;
    ans.pop();
  }
  return 0;
}
