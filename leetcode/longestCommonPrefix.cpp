class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        else {
            string last = strs.back();
            strs.pop_back();
            string subres = longestCommonPrefix(strs);
            int i;
            for(i = 0; i < min(subres.length(), last.length()); i++) {
                if(subres[i] != last[i]) {
                    break;
                }
            }
            return subres.substr(0, i);
        }
    }
};
