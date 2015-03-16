class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1) {
            return s;
        }
        string v[nRows];
        for(int i = 0; i < nRows; i++)
            v[i] = "";
        int pos = 0;
        bool inc = true;
        for(int i = 0; i < s.length(); i++) {
            v[pos] += s[i];
            if(inc)
                pos++;
            else
                pos--;
            if(pos == nRows - 1)
                inc = false;
            if(pos == 0)
                inc = true;
        }
        string res = "";
        for(int i = 0; i < nRows; i++)
            res += v[i];
        return res;
    }
};
