class Solution {
private:
    unordered_map<int, int> f;
    int findSet(int u) {
        return u == f[u] ? u : f[u] = findSet(f[u]);
    }
    void unionSet(int a, int b) {
        f[findSet(a)] = findSet(b);
    }
public:
    int longestConsecutive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(f.count(num))
                continue;
            f[num] = num;
            if(f.count(num - 1))
                unionSet(num, num - 1);
            if(f.count(num + 1))
                unionSet(num, num + 1);
        }
        unordered_set<int> visited;
        unordered_map<int, int> am;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(visited.count(num))
                continue;
            visited.insert(num);
            int parent = findSet(num);
            if(am.count(parent)) {
                am[parent] = am[parent] + 1;
            } else {
                am[parent] = 1; 
            }
            ans = max(ans, am[parent]);
        }
        return ans;
    }
};
