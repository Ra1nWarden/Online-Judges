class Solution {
public:
    pair<int, int> getCoord(int idx, int m, int n) {
        int x = idx / n;
        int y = idx % n;
        if(y == 0) {
            y = n-1;
            x--;
        } else {
            y--;
        }
        return make_pair(x, y);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 1, right = m * n;
        while(left != right) {
            pair<int, int> l = getCoord(left, m, n);
            int xleft = l.first, yleft = l.second;
            pair<int, int> r = getCoord(right, m, n);
            int xright = r.first, yright = r.second;
            if(target < matrix[xleft][yleft] || target > matrix[xright][yright])
                return false;
            int mid = (left + right) >> 1;
            pair<int, int> mi = getCoord(mid, m, n);
            int x = mi.first, y = mi.second;
            if(matrix[x][y] < target) {
                left = mid + 1;
            } else if(matrix[x][y] == target) {
                return true;  
            } else {
                right = mid;
            }
        }
        pair<int, int> sol = getCoord(left, m, n);
        return matrix[sol.first][sol.second] == target;
    }
};
