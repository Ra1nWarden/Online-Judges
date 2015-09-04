class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0, sum = 0;
        int ans = nums.size() + 1;
        while(j < nums.size()) {
            sum += nums[j++];
            if(sum >= s) {
                while(i <= j) {
                    sum -= nums[i++];
                    if(sum < s)
                        break;
                }
                ans = min(ans, j - i + 1);
            }
        }
        return ans == nums.size() + 1 ? 0 : ans;
    }
};
