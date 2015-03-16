class Solution {
public:
    int reverse(int x) {
        bool pos = x > 0;
        if(!pos)
            x = -x;
        long long res = 0;
        while(x > 0) {
            res = res * 10 + (x % 10);
            x /= 10;
        }
        res = pos ? res : -res;
        if((int) res != res)
            return 0;
        else
            return (int) res;
    }
};
