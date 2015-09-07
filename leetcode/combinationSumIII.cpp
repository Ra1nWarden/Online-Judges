class Solution {
private:
    int target_size;
    vector<vector<int>> ans;
    void solve(vector<int>& sub_ans, int sum) {
        if(sub_ans.size() == target_size) {
            if(sum == 0)
                ans.push_back(sub_ans);
            return;
        }
        for(int next = sub_ans.back() + 1; next <= min(9, sum); next++) {
            sub_ans.push_back(next);
            solve(sub_ans, sum - next);
            sub_ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        target_size = k;
        for(int i = 1; i <= min(9, n); i++) {
            vector<int> sub_ans;
            sub_ans.push_back(i);
            solve(sub_ans, n - i);
        }
        return ans;
    }
};
