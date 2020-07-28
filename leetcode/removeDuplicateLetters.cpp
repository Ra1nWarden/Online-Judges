class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> indices[26];
        set<char> chars;
        for(int i = 0; i < s.length(); i++) {
            indices[s[i] - 'a'].push_back(i);
            chars.insert(s[i]);
        }
        int char_length = chars.size();
        string ans = "";
        int min_idx = 0;
        for(int i = 0; i < char_length; i++) {
            char next_char;
            for(set<char>::iterator itr = chars.begin(); itr != chars.end(); itr++) {
                vector<int>& v = indices[(*itr) - 'a'];
                int cur_idx = *lower_bound(v.begin(), v.end(), min_idx);
                bool ok = true;
                for(set<char>::iterator next_itr = chars.begin(); next_itr != chars.end(); next_itr++) {
                    vector<int>& vv = indices[(*next_itr) - 'a'];
                    if(lower_bound(vv.begin(), vv.end(), cur_idx) == vv.end()) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    next_char = *itr;
                    min_idx = cur_idx;
                    break;
                }
            }
            ans.push_back(next_char);
            chars.erase(next_char);
        }
        return ans;
    }
};
