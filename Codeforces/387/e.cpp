#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<string> > ans;
stack<int> s;

int main() {
  iostream::sync_with_stdio(false);
  string str;
  bool word = true;
  while(getline(cin, str, ',')) {
    if(word) {
      while(!s.empty() && s.top() == 0) {
	s.pop();
	if(!s.empty()) {
	  int u = --s.top();
	  s.pop();
	  s.push(u);
	}
      }
      int depth = s.size();
      if(depth == ans.size()) {
	vector<string> v;
	v.push_back(str);
	ans.push_back(v);
      } else {
	ans[depth].push_back(str);
      }
    } else {
      int num;
      stringstream ss(str);
      ss >> num;
      s.push(num);
    }
    word = !word;
  }
  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++) {
    for(int j = 0; j < ans[i].size(); j++) {
      if(j)
	cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
