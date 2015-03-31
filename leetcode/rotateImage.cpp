class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for(int i = 0; i < matrix.size() / 2; i++) {
            for(int j = i; j < matrix.size() - 1 - i; j++) {
                int i2 = j;
                int j2 = matrix.size() - 1 - i;

                int i3 = matrix.size() - 1 - i;
                int j3 = matrix.size() - 1 - j;

                int i4 = matrix.size() - 1 - j;
                int j4 = i;

                int v = matrix[i][j];
                int v2 = matrix[i2][j2];
                int v3 = matrix[i3][j3];
                int v4 = matrix[i4][j4];
                matrix[i][j] = v4;
                matrix[i2][j2] = v;
                matrix[i3][j3] = v2;
                matrix[i4][j4] = v3;
            }
        }
    }
};
