class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        for(int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0) {
                ans = idx + 1;
                break;
            }
            nums[idx] = -nums[idx];
        }
        return ans;
    }
};
