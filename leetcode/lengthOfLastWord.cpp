class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool reset = false;
        for(int i=  0; i < s.length(); i++) {
            if(s[i] == ' ')
                reset = true;
            else {
                if(reset) {
                    ans = 1;
                    reset = false;
                } else
                    ans++;
            }
        }
        return ans;
    }
};
