class Solution {
private:
    map<string, vector<string> > memo;
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if(memo.count(s))
            return memo[s];
        vector<string> result;
        if(s.empty()) {
            result.push_back("");
        } else {
            for(int i= 1; i <= s.length(); i++) {
                string first = s.substr(0, i);
                if(dict.count(first)) {
                    vector<string> subResult = wordBreak(s.substr(i), dict);
                    for(int j= 0; j < subResult.size(); j++) {
                        string curSub = subResult[j];
                        if(curSub.empty())
                            result.push_back(first);
                        else
                            result.push_back(first + " " + curSub);
                    }
                }
            }
        }
        memo[s] = result;
        return result;
    }
};
