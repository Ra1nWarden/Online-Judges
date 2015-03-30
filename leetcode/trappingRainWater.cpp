class Solution {
public:
    int trap(int A[], int n) {
        int lmax[n];
        int maxval = 0;
        for(int i = 0; i < n; i++) {
            maxval = max(maxval, A[i]);
            lmax[i] = maxval;
        }
        maxval = 0;
        int ans = 0;
        for(int i = n-1; i > -1; i--) {
            maxval = max(maxval, A[i]);
            ans += max(min(maxval, lmax[i]) - A[i], 0);
        }
        return ans;
    }
};
