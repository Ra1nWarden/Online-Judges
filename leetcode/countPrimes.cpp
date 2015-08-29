class Solution {
public:
    int countPrimes(int n) {
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i = 2; i < n; i++) {
            if(!visited[i]) {
                ans++;
                for(int j = i + i; j < n; j += i) {
                    visited[j] = true;
                }
            }
        }
        return ans;
    }
};
