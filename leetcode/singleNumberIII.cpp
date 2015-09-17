class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum ^= nums[i];
        }
        int lowbit = sum & (-sum);
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]&lowbit)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
