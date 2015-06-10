class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int zero = 0;
        int two = nums.size();
        while(i < two) {
            if(nums[i] == 0)
                swap(nums[zero++], nums[i++]);
            else if(nums[i] == 1)
                i++;
            else
                swap(nums[--two], nums[i]);
        }
    }
};
