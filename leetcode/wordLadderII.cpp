#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<string, vector<string>> parents;
    unordered_map<string, int> visited;
    queue<string> q;
    vector<vector<string>> ans;
public:
    void insert(string k, string s) {
        if(parents.count(k) == 0) {
            vector<string> v;
            v.push_back(s);
            parents[k] = v;
        } else {
            vector<string> cpy = parents[k];
            cpy.push_back(s);
            parents[k] = cpy;
        }
    }
    void dfs(string w, string start, stack<string> s) {
        if(w == start) {
            s.push(w);
            vector<string> each;
            while(!s.empty()) {
                each.push_back(s.top());
                s.pop();
            }
            ans.push_back(each);
            return;
        }
        if(parents.count(w) == 0)
            return;
        for(int i = 0; i < parents[w].size(); i++) {
	  stack<string> ss = s;
            ss.push(w);
            dfs(parents[w][i], start, ss);
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        q.push(start);
        visited[start] = 1;
        bool done = false;
        while(!q.empty()) {
            string u = q.front();
            q.pop();
            for(int i = 0; i < u.length(); i++) {
                for(int j = 0; j < 26; j++) {
                    string v = u;
                    v[i] = 'a' + j;
                    if(dict.count(v) == 0)
                        continue;
                    if(visited.count(v) == 0) {
                        visited[v] = visited[u] + 1;
                        if(v == end) {
                            done = true;
                        } else if(!done) {
                            q.push(v);
                        }
                        insert(v, u);
                    } else if(visited[v] == visited[u] + 1) {
                        insert(v, u);
                    }
                }
            }
        }
        stack<string> s;
        dfs(end, start, s);
        return ans;
    }
};

int main() {
  Solution sol;
  string start = "a";
  string end = "c";
  unordered_set<string> s;
  s.insert("a");
  s.insert("b");
  s.insert("c");
  vector<vector<string> > ans = sol.findLadders(start, end, s);
  return 0;
}
