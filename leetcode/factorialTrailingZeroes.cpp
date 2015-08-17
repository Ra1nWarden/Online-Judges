class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long base = 5;
        long long nn = n;
        while(base <= nn) {
            ans += (nn / base);
            base *= 5;
        }
        return ans;
    }
};
