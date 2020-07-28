class NumMatrix {
private:
    vector<vector<int>> sum_mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size() + 1;
        int n = (m == 1 ? 0 : matrix[0].size()) + 1;
        for(int i = 0; i < m; i++) {
            vector<int> sum_row(n, 0);
            sum_mat.push_back(sum_row);
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                sum_mat[i][j] = sum_mat[i-1][j] + sum_mat[i][j-1] - sum_mat[i-1][j-1];
                sum_mat[i][j] += matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum_mat[row2 + 1][col2 + 1] - sum_mat[row1][col2 + 1] - sum_mat[row2 + 1][col1] + sum_mat[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
