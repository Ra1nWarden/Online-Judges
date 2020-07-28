class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted;
        vector<int> ans;
        for(int i = nums.size() - 1; i >= 0; i--) {
            int idx = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            ans.push_back(idx);
            sorted.insert(sorted.begin() + idx, nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
