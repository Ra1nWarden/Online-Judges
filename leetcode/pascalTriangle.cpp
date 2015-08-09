class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        if(numRows == 0)
            return ans;
        if(numRows == 1) {
            vector<int> row;
            row.push_back(1);
            ans.push_back(row);
            return ans;
        } else {
            ans = generate(numRows-1);
            vector<int> row;
            row.push_back(1);
            for(int i = 0; i < ans.back().size() - 1; i++) {
                row.push_back(ans.back()[i] + ans.back()[i+1]);
            }
            row.push_back(1);
            ans.push_back(row);
            return ans;
        }
    }
};
