class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.length();
        int pl = p.length();
        vector<vector<bool> >* dp = new vector<vector<bool> >(sl+1, vector<bool>(pl+1, false));
        (*dp)[0][0] = true;
        for(int j = 1; j <= pl; j++)
            (*dp)[0][j] = (*dp)[0][j-1] && p[j-1] == '*';
        for(int i = 1; i <= sl; i++) {
            for(int j = 1; j <= pl; j++) {
                if(p[j-1] == '*')
                    (*dp)[i][j] = (*dp)[i][j-1] || (*dp)[i-1][j];
                else if(p[j-1] == '?')
                    (*dp)[i][j] = (*dp)[i-1][j-1];
                else
                    (*dp)[i][j] = (*dp)[i-1][j-1] && s[i-1] == p[j-1];
            }
        }
        return (*dp)[sl][pl];
    }
};
