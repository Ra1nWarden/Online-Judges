class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int next = 0;
        int prevcnt = 0;
        int prevnum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(prevcnt == 0) {
                prevcnt = 1;
                prevnum = nums[i];
                nums[next++] = nums[i];
            } else if(nums[i] == prevnum) {
                if(prevcnt < 2) {
                    nums[next++] = nums[i];
                    prevcnt++;
                }
            } else {
                nums[next++] = nums[i];
                prevcnt = 1;
                prevnum = nums[i];
            }
        }
        return next;
    }
};
