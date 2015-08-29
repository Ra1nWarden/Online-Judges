class Solution {
private:
    bool dfs(int u, map<int, vector<int> >& adjList, vector<int>& visited, int n) {
        visited[u] = 0;
        for(int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if(visited[v] == 0)
                return false;
            else if(visited[v] == -1 && !dfs(v, adjList, visited, n))
                return false;
        }
        visited[u] = 1;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, vector<int> > adjList;
        for(int i = 0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> visited(numCourses, -1);
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == -1) {
                if(!dfs(i, adjList, visited, numCourses))
                    return false;
            }
        }
        return true;
    }
};
