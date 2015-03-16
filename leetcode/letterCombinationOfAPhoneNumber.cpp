class Solution {
private:
    void helper(string digits, string m[], string str, vector<string>& res) {
        if(digits.length() == 0)
            res.push_back(str);
        else {
            int next = digits[0] - '2';
            for(int i = 0; i < m[next].length(); i++) {
                if(digits.length() > 1)
                    helper(digits.substr(1), m, str + m[next][i], res);
                else
                    helper("", m, str + m[next][i], res);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string m[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if(digits.length() == 0)
            return res;
        string s = "";
        helper(digits, m, s, res);
        return res;
    }
};
