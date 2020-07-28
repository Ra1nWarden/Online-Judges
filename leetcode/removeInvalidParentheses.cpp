#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef pair<string, int> QNode;
class Solution {
public:
    bool isOK(string s) {
        int balance = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                balance++;
            } else if(s[i] == ')') {
                balance--;
                if(balance < 0)
                    return false;
            }
        }
        return balance == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        queue<QNode> q;
        q.push(make_pair(s, 0));
        while(!q.empty()) {
            QNode u = q.front();
            q.pop();
            if(isOK(u.first)) {
	      if(ans.empty() || ans.begin()->length() == u.first.length()) {
                    ans.insert(u.first);
	      } else if(ans.begin()->length() > u.first.length()) {
                    break;
                }
            } else {
                for(int i = u.second; i < u.first.length(); i++) {
                    if(u.first[i] == '(' || u.first[i] == ')') {
                        string v = u.first;
                        v.erase(v.begin() + i);
                        q.push(make_pair(v, i));
                    }
                }
            }
        }
        vector<string> ansv(ans.begin(), ans.end());
	return ansv;
    }
};

int main() {
  Solution sol;
  vector<string> ans = sol.removeInvalidParentheses(")(");
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
