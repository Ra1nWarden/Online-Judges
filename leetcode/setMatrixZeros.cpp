class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstrow = false;
        bool firstcol = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0 && j == 0) {
                        firstrow = true;
                        firstcol = true;
                    } else if(i == 0) {
                        firstrow = true;
                        matrix[0][j] = 0;
                    } else if(j == 0) {
                        firstcol = true;
                        matrix[i][0] = 0;
                    } else {
                        matrix[i][0] = matrix[0][j] = 0;
                    }
                }
            }
        }
        for(int i = 1; i < m; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 1; j < n; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
        if(firstrow) {
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        if(firstcol) {
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};
