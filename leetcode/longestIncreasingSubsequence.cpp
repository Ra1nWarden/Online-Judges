class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cur;
        for(int i = 0; i < nums.size(); i++) {
            int idx = lower_bound(cur.begin(), cur.end(), nums[i]) - cur.begin();
            if(idx == cur.size()) {
                cur.push_back(nums[i]);
            } else {
                cur[idx] = nums[i];
            }
        }
        return cur.size();
    }
};
