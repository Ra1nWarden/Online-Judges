class Solution {
public:
    int titleToNumber(string s) {
        int base = 1;
        int ans = 0;
        for(int i = s.length() - 1; i > -1; i--) {
            ans += base * (s[i] - 'A' + 1);
            base *= 26;
        }
        return ans;
    }
};
