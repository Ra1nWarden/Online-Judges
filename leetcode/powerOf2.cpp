class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        while(n) {
            if(n % 2 && n != 1)
                return false;
            n >>= 1;
        }
        return true;
    }
};
