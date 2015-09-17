class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int full = 0;
        int cur = 0;
        for(int i = 0; i < nums.size(); i++)
            cur ^= nums[i];
        for(int i = 0; i <= nums.size(); i++)
            full ^= i;
        return full ^ cur;
    }
};
