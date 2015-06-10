class Solution {
private:
    int target[260];
    int count[260];
    bool check() {
        for(int i = 1; i <= 256; i++) {
            if(count[i] < target[i])
                return false;
        }
        return true;
    }
    string minAns(string ans, string next) {
        if(ans == "")
            return next;
        else
            return ans.length() < next.length() ? ans : next;
    }
public:
    string minWindow(string s, string t) {
        memset(target, 0, sizeof target);
        memset(count, 0, sizeof count);
        for(int i = 0; i < t.length(); i++)
            target[t[i]]++;
        int i = 0, j = 0;
        string ans = "";
        while(true) {
            while(check()) {
                ans = minAns(ans, s.substr(i, j-i));
                count[s[i]]--;
                i++;
            }
            if(j < s.length()) {
                count[s[j]]++;
                j++;
            } else
                break;
        }
        return ans;
    }
};
