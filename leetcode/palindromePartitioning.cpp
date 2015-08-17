class Solution {
private:
    bool is_palindrome(const string& sub) {
        for(int i = 0; i < sub.length() / 2; i++) {
            if(sub[i] != sub[sub.length() - 1 - i])
                return false;
        }
        return true;
    }
    void helper(const string& s, int start, vector<string>& each, vector<vector<string> >& ans) {
        if(start == s.length()) {
            ans.push_back(each);
            return;
        }
        for(int end = start; end < s.length(); end++) {
            if(is_palindrome(s.substr(start, end - start + 1))) {
                each.push_back(s.substr(start, end - start + 1));
                helper(s, end+1, each, ans);
                each.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> each;
        helper(s, 0, each, ans);
        return ans;
    }
};
