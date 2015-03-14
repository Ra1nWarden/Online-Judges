#include <cstring>
#define INF 2e8

class Solution {
public:
    int maxProduct(int A[], int n) {
        int dpmin[n+1][2];
        for(int i = 0; i < n+1; i++) {
            for(int j= 0; j < 2; j++)
                dpmin[i][j] = INF;
        }
        int dpmax[n+1][2];
        for(int i = 0; i < n+1; i++) {
            for(int j= 0; j < 2; j++)
                dpmax[i][j] = -INF;
        }
        dpmin[0][0] = A[0];
        dpmin[0][1] = A[0];
        dpmax[0][0] = A[0];
        dpmax[0][1] = A[0];
        for(int i = 1; i < n; i++) {
            dpmin[i][0] = min(dpmin[i-1][0], dpmin[i-1][1]);
            dpmax[i][0] = max(dpmax[i-1][0], dpmax[i-1][1]);
            if(A[i] > 0) {
                dpmin[i][1] = min(A[i], dpmin[i-1][1] * A[i]);
                dpmax[i][1] = max(A[i], dpmax[i-1][1] * A[i]);
            } else {
                dpmin[i][1] = min(A[i], dpmax[i-1][1] * A[i]);
                dpmax[i][1] = max(A[i], dpmin[i-1][1] * A[i]);
            }
        }
        return max(dpmax[n-1][0], dpmax[n-1][1]);
    }
};
