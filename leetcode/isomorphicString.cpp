class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.empty() && t.empty())
            return true;
        unordered_map<char, char> m;
        unordered_map<char, char> rm;
        for(int i = 0; i < s.length(); i++) {
            if(m.count(s[i]) == 0 && rm.count(t[i]) == 0) {
                m[s[i]] = t[i];
                rm[t[i]] = s[i];
            } else if(m.count(s[i]) == 0 || rm.count(t[i]) == 0) {
                return false;
            } else {
                if(m[s[i]] != t[i] || rm[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};
