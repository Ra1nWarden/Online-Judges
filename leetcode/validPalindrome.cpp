class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(true) {
            while(i < s.length()) {
                if(isalnum(s[i]))
                    break;
                i++;
            }
            while(j > -1) {
                if(isalnum(s[j]))
                    break;
                j--;
            }
            if(i < s.length() && j > -1 && i < j) {
                char ic = tolower(s[i]);
                char jc = tolower(s[j]);
                if(ic != jc)
                    return false;
                i++;
                j--;
            } else {
                break;
            }
        }
        return true;
    }
};
