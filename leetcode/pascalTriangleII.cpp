class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if(rowIndex == 0) {
            ans.push_back(1);
            return ans;
        } else {
            vector<int> sub_ans = getRow(rowIndex - 1);
            ans.push_back(1);
            for(int i = 0; i < sub_ans.size() - 1; i++) {
                ans.push_back(sub_ans[i] + sub_ans[i+1]);
            }
            ans.push_back(1);
            return ans;
        }
    }
};
