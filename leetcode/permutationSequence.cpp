class Solution {
public:
    char nextNumber(vector<bool>& used, int n) {
        int ans;
        for(int i = 1; i < 10 && n; i++) {
            if(!used[i])
                n--;
            if(n == 0)
                ans = i;
        }
        used[ans] = true;
        return ans + '0';
    }
    int factorial(int n) {
        return n == 0 ? 1 : n * factorial(n-1);
    }
    string getPermutation(int n, int k) {
        vector<bool> used(n+1, false);
        k--;
        string ans;
        while(ans.length() < n) {
            int nn = n - 1 - ans.size();
            if(nn > 0) {
                int nfactorial = factorial(nn);
                ans += nextNumber(used, k / nfactorial + 1);
                k %= nfactorial;
            } else {
                ans += nextNumber(used, nn + 1);
                break;
            }
        }
        return ans;
    }
};
