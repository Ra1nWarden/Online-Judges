class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(true) {
            if(n == 1)
                break;
            if(seen.count(n))
                return false;
            seen.insert(n);
            stringstream ss;
            ss << n;
            string n_str = ss.str();
            int nn = 0;
            for(int i = 0; i < n_str.length(); i++) {
                nn += (n_str[i] - '0') * (n_str[i] - '0');
            }
            n = nn;
        }
        return true;
    }
};
