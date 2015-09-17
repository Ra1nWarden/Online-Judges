class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int prod = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            ans[i] *= prod;
            prod *= nums[i];
        }
        prod = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--) {
            ans[i] *= prod;
            prod *= nums[i];
        }
        return ans;
    }
};
