class Solution {
public:
    int countDigitOne(int n) {
        if(n < 1)
            return 0;
        else if(n < 10)
            return 1;
        long long len = 1;
        while(len <= n) {
            len *= 10;
        }
        len /= 10;
        int first_dig = n / len;
        if(first_dig == 1) {
            return countDigitOne(len - 1) + n % len + 1 + countDigitOne(n % len);
        } else {
            return countDigitOne(len - 1) * first_dig + len + countDigitOne(n % len);
        }
    }
};
