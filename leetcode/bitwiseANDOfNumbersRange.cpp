class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            int mask = (1 << i);
            if((m & mask) != (n & mask))
                break;
            if(m & mask)
                ans |= mask;
        }
        return ans;
    }
};
