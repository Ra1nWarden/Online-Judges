class Solution {
private:
    map<int, int> m;
public:
    int numTrees(int n) {
        if(m.count(n))
            return m[n];
        if(n <= 1)
            return m[n] = 1;
        int ans = 0;
        for(int i = 0; i <= n - 1; i++) {
            ans += numTrees(i) * numTrees(n-1-i);
        }
        return m[n] = ans;
    }
};
