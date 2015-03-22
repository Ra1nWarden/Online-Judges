class Solution {
public:
    string transform(string str) {
        stringstream ss;
        for(int i = 0; i < str.length(); i++) {
            if(i == str.length() - 1) {
                ss << 1 << str[i];
            }
            for(int j = i + 1; j < str.length(); j++) {
                if(str[i] != str[j]) {
                    ss << (j - i) << str[i];
                    i = j;
                    i--;
                    break;
                } else if(j == str.length() - 1) {
                    ss << (j - i + 1) << str[i];
                    i = j;
                }
            }
        }
        return ss.str();
    }
    string countAndSay(int n) {
        string start = "1";
        for(int i = 0; i < n-1; i++)
            start = transform(start);
        return start;
    }
};
