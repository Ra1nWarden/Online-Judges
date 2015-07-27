class Solution {
private:
    void solve(int index, int level, string str, string res, vector<string>& ans) {
        if(level >= 4 || index >= str.length()) {
            if(level == 4 && index == str.length()) {
                ans.push_back(res);
            }
            return;
        }
        if(str[index] == '0') {
            string rescpy = res;
            if(level > 0) {
                rescpy += ".";
            }
            rescpy += "0";
            solve(index+1, level+1, str, rescpy, ans);
            return;
        }
        for(int i = 1; i <= min(3, (int) str.length() - index); i++) {
            int num = atoi(str.substr(index, i).c_str());
            if(num < 256) {
                string rescpy = res;
                if(level > 0) {
                    rescpy += ".";
                }
                rescpy += str.substr(index, i);
                solve(index+i, level+1, str, rescpy, ans);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string res = "";
        solve(0, 0, s, res, ans);
        return ans;
    }
};
