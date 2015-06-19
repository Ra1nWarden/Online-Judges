class Solution {
public:
    // for the height of dph[j], find the left and right boundaries and calculate the area.
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        vector<int> dpl(n, 0);
        vector<int> dpr(n, n);
        vector<int> dph(n, 0);
        int ans = 0;
        for(int i = 0; i < m; i++) {
           int right = n;
           for(int j = n-1; j >= 0; j--) {
             if(matrix[i][j] == '1') {
                dpr[j] = min(dpr[j], right);       
             } else {
                dpr[j] = n;
                right = j;
             }
           }
           int left = 0;
           for(int j = 0; j < n; j++) {
               if(matrix[i][j] == '1') {
                   dpl[j] = max(dpl[j], left);
                   dph[j]++;
                   ans = max(ans, (dpr[j] - dpl[j]) * dph[j]);
               } else {
                   dpl[j] = 0;
                   left = j+1;
                   dph[j] = 0;
               }
           }
            
        }   
        return ans;
    }
};
