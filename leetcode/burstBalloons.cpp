typedef pair<int, int> Tuple;
class Solution {
private:
    map<Tuple, int> memo;
    int helper(vector<int>& nums, int left, int right) {
        Tuple key = make_pair(left, right);
        if(memo.count(key)) {
            return memo[key];
        }
        int ans = 0;
        for(int i = left; i <= right; i++) {
            int mult = nums[i];
            if(left > 0) {
                mult *= nums[left - 1];
            }
            if(right + 1 < nums.size()) {
                mult *= nums[right + 1];
            }
            int cur = mult;
            if(i > left) {
                cur += helper(nums, left, i-1);
            }
            if(i < right) {
                cur += helper(nums, i+1, right);
            }
            ans = max(ans, cur);
        }
        return memo[key] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
