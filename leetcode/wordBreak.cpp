class Solution {
private:
    map<string, bool> memo;
public:
   bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty())
            return true;
        if(memo.count(s))
            return memo[s];
        bool result = false;
        for(int i= 1; i <= s.length(); i++) {
            string first = s.substr(0, i);
            if(dict.count(first)) {
                result = wordBreak(s.substr(i), dict);
                if(result)
                    break;
            }
        }
        memo[s] = result;
        return result;
    }
};
