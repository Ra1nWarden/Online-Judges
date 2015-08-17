class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int counter[32];
        memset(counter, 0, sizeof counter);
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            for(int j = 0; j < 32; j++) {
                if(((1 << j) & num) != 0)
                    counter[j] = (counter[j] + 1) % 3;
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(counter[i] != 0)
                ans = ans | (1 << i);
        }
        return ans;
    }
};
