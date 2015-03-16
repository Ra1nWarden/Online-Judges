class Solution {
public:
    int atoi(string str) {
        if(str.length() == 0)
            return 0;
        int start = 0;
        for(int i = 0; i < str.length(); i++) {
            if(!isspace(str[i])) {
                start = i;
                break;
            }
        }
        str = str.substr(start);
        bool pos = true;
        if(str[0] == '+' || str[0] == '-') {
            pos = str[0] == '+';
            str = str.substr(1);
        }
        long long res = 0;
        for(int i = 0; i < str.length(); i++) {
            if(!isdigit(str[i]))
                break;
            res = res * 10 + (str[i] - '0');
            if(res > 9999999999)
                break;
        }
        res = pos ? res : -res;
        return (int) res == res ? (int) res : (pos ? INT_MAX : INT_MIN);
    }
};
