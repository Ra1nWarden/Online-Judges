class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() < 2) {
            ans = nums;
            return ans;
        }
        int num1, num2, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && num1 == nums[i]) {
                cnt1++;
            } else if(i > 1 && num2 == nums[i]) {
                cnt2++;
            } else if(cnt1 == 0) {
                num1 = nums[i];
                cnt1 = 1;
            } else if(cnt2 == 0) {
                num2 = nums[i];
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(num1 == nums[i])
                cnt1++;
            else if(num2 == nums[i])
                cnt2++;
        }
        if(cnt1 > 0 && cnt1 > nums.size() / 3)
            ans.push_back(num1);
        if(cnt2 > 0 && cnt2 > nums.size() / 3)
            ans.push_back(num2);
        return ans;
    }
};
