class Solution {
private:
    unordered_map<long long, int> seen;
    long long rep;
    bool calc(long long& p, long long q, string& ans) {
        if(p == 0)
            return true;
        p *= 10;
        if(seen.count(p)) {
            rep = p;
            return true;
        }
        seen[p] = ans.length();
        ans += ('0' + (p / q));
        if(p % q == 0) {
            return true;
        } else {
            p = p % q;
            return false;
        }
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long p = (long long) numerator;
        long long q = (long long) denominator;
        bool pos = (p < 0 && q < 0) || (p > 0 && q > 0);
        if(p == 0)
            pos = true;
        p = abs(p);
        q = abs(q);
        rep = -1;
        long long whole = p / q;
        p %= q;
        string ans = "";
        while(true) {
            if(calc(p, q, ans))
                break;
        }
        stringstream ss;
        if(!pos)
            ss << "-";
        if(rep != -1) {
            // repeat
            int idx = seen[rep];
            ss << whole << "." << ans.substr(0, idx) << "(" << ans.substr(idx) << ")";
        } else {
            // no repeat
            ss << whole;
            if(!ans.empty())
                ss  << "." << ans;
        }
        return ss.str();
    }
};
