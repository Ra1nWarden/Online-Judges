class Solution {
private:
    vector<int> route;
    vector<int> visited;
    vector<pair<int, int> > adjList;
    int n;
    int idx;
public:
    bool dfs(int u) {
        visited[u] = -1;
        for(int i = 0; i < adjList.size(); i++) {
            if(adjList[i].second == u) {
                int v = adjList[i].first;
                if(visited[v] == -1)
                    return false;
                else if(visited[v] == 0 && !dfs(v))
                    return false;
            }
        }
        visited[u] = 1;
        route[idx--] = u;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        n = numCourses;
        idx = n - 1;
        visited = vector<int>(n, 0);
        route = vector<int>(n, -1);
        adjList = prerequisites;
        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                if(!dfs(i)) {
                    vector<int> empty_v;
                    return empty_v;
                }
            }
        }
        return route;
    }
};
