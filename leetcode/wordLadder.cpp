class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_map<string, int> vis;
        queue<string> q;
        q.push(beginWord);
        vis[beginWord] = 1;
        int ans = 0;
        bool found = false;
        while(!q.empty()) {
            string u = q.front();
            q.pop();
            for(int i = 0; i < u.length(); i++) {
                for(int j = 0; j < 26; j++) {
                    string v = u;
                    v[i] = 'a' + j;
                    if(wordDict.count(v) == 0)
                        continue;
                    if(v == endWord) {
                        ans = vis[u] + 1;
                        found = true;
                        break;
                    }
                    if(vis.count(v) == 0) {
                        q.push(v);
                        vis[v] = vis[u] + 1;
                    }
                }
                if(found)
                    break;
            }
            if(found)
                break;
        }
        return ans;
    }
};
