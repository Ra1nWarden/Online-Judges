class Solution {
private:
    void helper(int open, int close, string s, vector<string>& res) {
        int balance = close - open;
        if(open == 0 && close == 0) {
            res.push_back(s);
            return;
        }
        if(balance == 0) {
            helper(open-1, close, s + "(", res);
        } else {
            if(open > 0) {
                helper(open - 1, close, s + "(", res);
            }
            helper(open, close-1, s + ")", res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        helper(n, n, s, res);
        return res;
    }
};
