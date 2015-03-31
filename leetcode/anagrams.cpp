class Solution {
private:
    int hash(string str) {
        sort(str.begin(), str.end());
        int ans = 0;
        int prime = 31;
        for(int i = 0; i < str.length(); i++) {
            ans += (str[i] - 'a' + 1) * prime;
            prime *= 31;
        }
        return ans;
    }
public:
    vector<string> anagrams(vector<string> &strs) {
        map<int, vector<string> > m;
        for(int i = 0; i < strs.size(); i++) {
            int hashVal = hash(strs[i]);
            m[hashVal].push_back(strs[i]);
        }
        vector<string> ans;
        for(map<int, vector<string> >::iterator itr = m.begin(); itr != m.end(); itr++) {
            if(itr->second.size() > 1) {
                for(int i = 0; i < itr->second.size(); i++)
                    ans.push_back(itr->second[i]);
            }
        }
        return ans;
    }
};
