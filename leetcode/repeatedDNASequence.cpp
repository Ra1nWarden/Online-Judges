class Solution {
private:
    char cv[4] = {'A', 'C', 'G', 'T'};
    int nv[4] = {1, 2, 3, 4};
    int decode(char c) {
        for(int i = 0; i < 4; i++) {
            if(cv[i] == c) {
                return nv[i];
            }
        }
        return -1;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<int, int> m;
        vector<string> ans;
        if(s.length() < 10)
            return ans;
        int hash = 0;
        int base = 1;
        int i;
        for(i = 0; i < 10; i++) {
            hash += base * decode(s[i]);
            base *= 5;
        }
        base /= 5;
        m[hash] = 1;
        while(i < s.length()) {
            hash /= 5;
            hash += base * decode(s[i]);
            if(m.count(hash))
                m[hash]++;
            else
                m[hash] = 1;
            if(m[hash] == 2) {
                ans.push_back(s.substr(i-9, 10));
            }
            i++;
        }
        return ans;
    }
};
