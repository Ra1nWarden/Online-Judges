class Solution {
private:
    int convert(string s, char one, char five, char ten, int base) {
        int res = 0;
        if(s.length() == 0)
            return res;
        if(s.length() == 2 && s[0] == one) {
            if(s[1] == five)
                return 4 * base;
            if(s[1] == ten)
                return 9 * base;
            if(s[1] == one)
                return 2 * base;
        }
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == one)
                res += base;
            else if(s[i] == five)
                res += base * 5;
        }
        return res;
    }
    void add(char one, char five, char ten, int base, string& s, int& res) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != one && s[i] != five && s[i] != ten) {
                res += convert(s.substr(0, i), one, five, ten, base);
                s = s.substr(i);
                break;
            }
            if(i == s.length() - 1) {
                res += convert(s, one, five, ten, base);
                s = "";
                break;
            }
        }
    }
public:
    int romanToInt(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'M') {
                res += 1000;
            } else {
                s = s.substr(i);
                break;
            }
        }
        add('C', 'D', 'M', 100, s, res);
        add('X', 'L', 'C', 10, s, res);
        add('I', 'V', 'X', 1, s, res);
        return res;
    }
};
