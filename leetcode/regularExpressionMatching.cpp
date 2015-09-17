class Solution {
private:
    bool checkEmpty(string p) {
        if(p.length() % 2)
            return false;
        for(int i = 1; i < p.length(); i += 2) {
            if(p[i] != '*')
                return false;
        }
        return true;
    }
public:
    bool isMatch(string s, string p) {
        if(s.empty())
            return checkEmpty(p);
        if(p.empty())
            return false;
        if(p.length() > 1 && p[1] == '*') {
            if(s[0] == p[0] || p[0] == '.') {
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            } else {
                return isMatch(s, p.substr(2));
            }
        } else {
            if(s[0] == p[0] || p[0] == '.') {
                return isMatch(s.substr(1), p.substr(1));
            } else {
                return false;
            }
        }
    }
};
