class Solution {
public:
    double pow(double x, int n) {
        if(n == 0)
            return 1.0;
        if(n == 1)
            return x;
        if(n == -1)
            return 1 / x;
        if(n % 2 == 0) {
            double half = pow(x, n /2);
            return half * half;
        } else {
            return pow(x, n - 1) * x;
        }
    }
};
