class Solution {
private:
    map<int, vector<int>> adjMat; 
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if(adjMat.count(u)) {
                adjMat[u].push_back(v);
            } else {
                adjMat[u] = {v};
            }
            if(adjMat.count(v)) {
                adjMat[v].push_back(u);
            } else {
                adjMat[v] = {u};
            }
        }
        
        vector<int> vis(n, 0);
        vis[0] = 1;
        stack<int> s;
        s.push(0);
        while(!s.empty()) {
            int u = s.top();
            s.pop();
            for(int i = 0; i < adjMat[u].size(); i++) {
                int v = adjMat[u][i];
                if(vis[v]) {
                    continue;
                }
                vis[v] = vis[u] + 1;
                s.push(v);
            }
        }
        
        int idx = -1;
        int depth = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] > depth) {
                depth = vis[i];
                idx = i;
            }
        }
        
        for(int i = 0; i < n; i++)
            vis[i] = 0;
        vis[idx] = 1;
        s.push(idx);
        int diameter = 0;
        int end = 0;
        while(!s.empty()) {
            int u = s.top();
            s.pop();
             for(int i = 0; i < adjMat[u].size(); i++) {
                int v = adjMat[u][i];
                if(vis[v]) {
                    continue;
                }
                vis[v] = vis[u] + 1;
                diameter = max(diameter, vis[v]);
                if(diameter == vis[v]) {
                    end = v;
                }
                s.push(v);
            }
        }
        
        
        vector<int> ans;
        int cur = end;
        while(true) {
            if(vis[cur] == (1 + diameter) / 2) {
                ans.push_back(cur);
            }
            if(!(diameter&1) && (1 + diameter) / 2 + 1 == vis[cur]) {
                ans.push_back(cur);
            }
            bool found = false;
            for(int i = 0; i < adjMat[cur].size(); i++) {
                int next = adjMat[cur][i];
                if(vis[next] == vis[cur] - 1) {
                    cur = next;
                    found = true;
                    break;
                }
            }
            if(!found)
                break;
        }
        return ans;
    }
};
