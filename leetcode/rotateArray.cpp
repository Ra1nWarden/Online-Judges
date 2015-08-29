class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k == 0)
            return;
        vector<int> ans;
        int idx = n - k;
        for(int i = 0; i < nums.size(); i++, idx++, idx %= n) {
            ans.push_back(nums[idx]);
        }
        nums = ans;
    }
};
