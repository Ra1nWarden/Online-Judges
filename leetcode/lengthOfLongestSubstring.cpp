class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        int prev[128];
        memset(prev, -1, sizeof prev);
        int res = 0;
        int last = -1;
        for(int i = 0; i < s.length(); i++) {
            int nextchar = s[i];
            if(prev[nextchar] == -1) 
                prev[nextchar] = i;
            else {
                if(prev[nextchar] > last) {
                    res = max(res, i - last - 1);
                    last = prev[nextchar];
                }
                prev[nextchar] = i;
            }
        }
        res = max(res, (int) s.length() - last - 1);
        return res;
    }
};
