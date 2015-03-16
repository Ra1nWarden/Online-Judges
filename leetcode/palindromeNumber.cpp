class Solution {
public:
    bool isPalindrome(int y) {
        stringstream ss;
        ss << y;
        string str = ss.str();
        int len = str.length() / 2;
        for(int i = 0; i < len; i++) {
            if(str[i] != str[str.length() - 1 - i])
                return false;
        }
        return true;
    }
};
